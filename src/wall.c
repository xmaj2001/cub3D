/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:10:43 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 10:36:11 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void			intersection_point(t_ray *ray, t_system *game,
						t_wall *wall);
static void			find_texture_position_x(t_ray *ray, t_system *game,
						t_wall *wall);
static void			render_wall(t_system *game, int pixel, t_wall *wall,
						int texture);
static t_texture	get_texture(t_system *sys, t_ray *ray);

void	draw_wall(t_ray *ray, t_system *sys, int pixel)
{
	t_wall	wall;

	wall.texture = ray->texture;
	sys->map.textures[TEXTURE] = get_texture(sys, ray);
	wall.height = (int)(HEIGHT / ray->prd_dist);
	wall.line_start_y = (HEIGHT / 2 - wall.height / 2);
	wall.line_end_y = (HEIGHT / 2 + wall.height / 2);
	if (wall.line_start_y < 0)
		wall.line_start_y = 0;
	if (wall.line_end_y >= HEIGHT)
		wall.line_end_y = HEIGHT - 1;
	intersection_point(ray, sys, &wall);
	find_texture_position_x(ray, sys, &wall);
	wall.texture_pos = (wall.line_start_y - HEIGHT / 2 + wall.height / 2)
		* wall.texture_step;
	render_wall(sys, pixel, &wall, TEXTURE);
}

static void	intersection_point(t_ray *ray, t_system *sys, t_wall *wall)
{
	if (ray->side == HORIZONTAL)
		wall->point_x = (sys->player.pos.y / BLOCK) + ray->prd_dist
			* ray->dir.y;
	else
		wall->point_x = (sys->player.pos.x / BLOCK) + ray->prd_dist
			* ray->dir.x;
	wall->point_x -= floor(wall->point_x);
}

static void	find_texture_position_x(t_ray *ray, t_system *sys, t_wall *wall)
{
	t_texture	texture_wall;

	texture_wall = sys->map.textures[TEXTURE];
	if (wall->texture == 0)
		texture_wall = sys->door_texture[0];
	wall->texture_x = (int)(wall->point_x * texture_wall.width);
	if ((ray->side == 0 && ray->dir.x < 0) || (ray->side == 1
			&& ray->dir.y > 0))
		wall->texture_x = texture_wall.width - wall->texture_x - 1;
	wall->texture_step = (1.0 * texture_wall.height) / wall->height;
}

static void	render_wall(t_system *sys, int pixel, t_wall *wall, int texture)
{
	int			y;
	int			texture_y;
	uint32_t	color;
	t_texture	texture_wall;

	y = wall->line_start_y;
	texture_wall = sys->map.textures[TEXTURE];
	if (wall->texture == 0)
		texture_wall = sys->door_texture[0];
	while (y < wall->line_end_y)
	{
		texture_y = (int)wall->texture_pos;
		if (texture_y < 0)
			texture_y = 0;
		if (texture_y >= (int)texture_wall.height)
			texture_y = texture_wall.height - 1;
		wall->texture_pos += wall->texture_step;
		color = get_color_texture(texture_wall, texture_y, wall->texture_x);
		put_pixel(sys, pixel, y, color);
		y++;
	}
}

t_texture	get_texture(t_system *sys, t_ray *ray)
{
	if (ray->side == VERTICAL)
	{
		if (ray->step.y < 0)
			return (sys->map.textures[NORTH]);
		else
			return (sys->map.textures[SOUTH]);
	}
	else
	{
		if (ray->step.x < 0)
			return (sys->map.textures[WEST]);
		else
			return (sys->map.textures[EAST]);
	}
}
