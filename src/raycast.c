/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:16:19 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 10:33:17 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	calculate_delta(t_ray *ray);
static void	calculate_dist(t_ray *ray, t_system *sys);
static void	dda(t_ray *ray, t_system *sys);

void	raycast(t_system *sys)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		ray.texture = 4;
		ray.mult = 2 * x / (float)WIDTH - 1;
		ray.new_camera = mult_vector(sys->player.camera_plane, ray.mult);
		ray.dir = sum_vector(sys->player.dir, ray.new_camera);
		ray.step.x = get_direction_ray(ray.dir.x);
		ray.step.y = get_direction_ray(ray.dir.y);
		calculate_delta(&ray);
		calculate_dist(&ray, sys);
		dda(&ray, sys);
		draw_wall(&ray, sys, x);
		x++;
	}
}

static void	calculate_delta(t_ray *ray)
{
	if (ray->dir.x != 0)
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	if (ray->dir.y != 0)
		ray->delta_dist.y = fabs(1 / ray->dir.y);
}

static void	calculate_dist(t_ray *ray, t_system *sys)
{
	ray->map = (t_point){(int)(sys->player.pos.x / BLOCK),
		(int)(sys->player.pos.y / BLOCK)};
	if (ray->dir.x < 0)
		ray->dist.x = (sys->player.pos.x / BLOCK - ray->map.x)
			* ray->delta_dist.x;
	else
		ray->dist.x = (ray->map.x + 1.0 - sys->player.pos.x / BLOCK)
			* ray->delta_dist.x;
	if (ray->dir.y < 0)
		ray->dist.y = (sys->player.pos.y / BLOCK - ray->map.y)
			* ray->delta_dist.y;
	else
		ray->dist.y = (ray->map.y + 1.0 - sys->player.pos.y / BLOCK)
			* ray->delta_dist.y;
}

static void	dda(t_ray *ray, t_system *sys)
{
	char	**map;

	map = sys->map.matrix_map;
	while (map[ray->map.y][ray->map.x] && map[ray->map.y][ray->map.x] != '1'
		&& map[ray->map.y][ray->map.x] != 'x')
	{
		if (ray->dist.x < ray->dist.y)
		{
			ray->dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = HORIZONTAL;
		}
		else
		{
			ray->dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = VERTICAL;
		}
	}
	if (map[ray->map.y][ray->map.x] == 'x')
		ray->texture = 0;
	if (ray->side == HORIZONTAL)
		ray->prd_dist = ray->dist.x - ray->delta_dist.x;
	else
		ray->prd_dist = ray->dist.y - ray->delta_dist.y;
}
