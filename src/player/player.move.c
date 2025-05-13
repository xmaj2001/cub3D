/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:14:48 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 08:33:37 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static int	iswall(t_system *sys, t_vector pos);
static void	next_position(t_player *player, t_vector *next_pos);
static void	door(t_system *sys, t_vector pos, char is);

void	player_move(t_system *sys)
{
	t_vector	next_pos;
	t_player	*player;

	player = &sys->player;
	next_pos = new_vector(0, 0);
	next_position(player, &next_pos);
	door(sys, player->pos, 'x');
	if (sys->player.door == '0')
		door(sys, player->pos, 'z');
	if (!iswall(sys, next_pos))
		player->pos = next_pos;
	if (player->keys.left_rot)
	{
		player->dir = rotate_vector(player->dir, -1.5);
		player->camera_plane = rotate_vector(player->camera_plane, -1.5);
	}
	if (player->keys.right_rot)
	{
		player->dir = rotate_vector(player->dir, 1.5);
		player->camera_plane = rotate_vector(player->camera_plane, 1.5);
	}
}

void	player_rotation(t_system *sys)
{
	static int	x;
	t_player	*py;
	t_point		point;
	float		speed;

	py = &sys->player;
	speed = 3;
	mlx_mouse_get_pos(sys->mlx, sys->win, &point.x, &point.y);
	if (x != point.x)
	{
		if (x > point.x)
		{
			py->dir = rotate_vector(py->dir, speed);
			py->camera_plane = rotate_vector(py->camera_plane, speed);
		}
		else if (x < point.x)
		{
			py->dir = rotate_vector(py->dir, -speed);
			py->camera_plane = rotate_vector(py->camera_plane, -speed);
		}
		x = point.x;
	}
}

static void	next_position(t_player *player, t_vector *next_pos)
{
	next_pos->x = player->pos.x;
	next_pos->y = player->pos.y;
	if (player->keys.up == 1)
	{
		next_pos->x += player->dir.x * player->move_speed;
		next_pos->y += player->dir.y * player->move_speed;
	}
	if (player->keys.down == 1)
	{
		next_pos->x -= player->dir.x * player->move_speed;
		next_pos->y -= player->dir.y * player->move_speed;
	}
	if (player->keys.left == 1)
	{
		next_pos->x -= player->camera_plane.x * player->move_speed;
		next_pos->y -= player->camera_plane.y * player->move_speed;
	}
	if (player->keys.right == 1)
	{
		next_pos->x += player->camera_plane.x * player->move_speed;
		next_pos->y += player->camera_plane.y * player->move_speed;
	}
}

static int	iswall(t_system *sys, t_vector pos)
{
	const int	x = (int)pos.x / BLOCK;
	const int	y = (int)pos.y / BLOCK;

	if (sys->map.matrix_map[y][x] == '1' || sys->map.matrix_map[y][x] == 'x')
		return (1);
	return (0);
}

static void	door(t_system *sys, t_vector pos, char is)
{
	t_point	p;

	p = (t_point){(int)pos.x / BLOCK, (int)pos.y / BLOCK};
	if (p.y + 1 <= 10 && sys->map.matrix_map[p.y + 1][p.x] == is)
	{
		sys->player.door = sys->map.matrix_map[p.y + 1][p.x];
		sys->player.pos_door = (t_point){p.x, p.y + 1};
	}
	else if (p.y - 1 >= 0 && sys->map.matrix_map[p.y - 1][p.x] == is)
	{
		sys->player.door = sys->map.matrix_map[p.y - 1][p.x];
		sys->player.pos_door = (t_point){p.x, p.y - 1};
	}
	else if (p.x + 1 <= 21 && sys->map.matrix_map[p.y][p.x + 1] == is)
	{
		sys->player.door = sys->map.matrix_map[p.y][p.x + 1];
		sys->player.pos_door = (t_point){p.x + 1, p.y};
	}
	else if (p.x - 1 >= 0 && sys->map.matrix_map[p.y][p.x - 1] == is)
	{
		sys->player.door = sys->map.matrix_map[p.y][p.x - 1];
		sys->player.pos_door = (t_point){p.x - 1, p.y};
	}
	else
		sys->player.door = '0';
}
