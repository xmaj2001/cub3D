/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:18:24 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 09:45:27 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	start_player_pos(t_system *sys, enum e_coord coord);

void	init_player(t_system *sys, t_point pos, enum e_coord coord)
{
	int	margin;

	margin = 2;
	sys->player.pos = new_vector(pos.x * (BLOCK + margin), pos.y * (BLOCK
				+ margin));
	start_player_pos(sys, coord);
	sys->player.door = '0';
	sys->player.pos_door = (t_point){0, 0};
	sys->player.keys.up = 0;
	sys->player.keys.down = 0;
	sys->player.keys.left = 0;
	sys->player.keys.right = 0;
	sys->player.keys.left_rot = 0;
	sys->player.keys.right_rot = 0;
	sys->player.move_speed = 2;
}

static void	start_player_pos(t_system *sys, enum e_coord coord)
{
	if (coord == NORTH)
	{
		sys->player.dir = new_vector(-1, 0);
		sys->player.camera_plane = new_vector(0, 0.66);
	}
	else if (coord == SOUTH)
	{
		sys->player.dir = new_vector(1, 0);
		sys->player.camera_plane = new_vector(0, -0.66);
	}
	else if (coord == WEST)
	{
		sys->player.dir = new_vector(0, -1);
		sys->player.camera_plane = new_vector(-0.66, 0);
	}
	else if (coord == EAST)
	{
		sys->player.dir = new_vector(0, 1);
		sys->player.camera_plane = new_vector(0.66, 0);
	}
}

void	open_door(t_system *sys)
{
	const t_vector	pos = sys->player.pos;
	const t_point	pos_door = sys->player.pos_door;
	const int		x = (int)pos.x / BLOCK;
	const int		y = (int)pos.y / BLOCK;

	if (sys->player.door == 'x')
		sys->map_matrix[pos_door.y][pos_door.x] = 'z';
	else if (sys->player.door == 'z')
		sys->map_matrix[pos_door.y][pos_door.x] = 'x';
}
