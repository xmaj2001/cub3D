/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:10:28 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 10:42:08 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	draw_player(char c, t_point ps, t_system *sys);
static void	move_player(t_system *sys, char player);
static char	check_door(char ch, char current_pos);

void	draw_minimap(t_system *sys)
{
	t_map	*map;
	t_point	ps;
	t_point	pos;

	map = &sys->map;
	ps.y = 0;
	move_player(sys, map->looking_dir);
	while (map->matrix_map[ps.y])
	{
		ps.x = 0;
		while (map->matrix_map[ps.y][ps.x])
		{
			pos = (t_point){ps.x * (map->size + 1), ps.y * (map->size + 1)};
			if (map->matrix_map[ps.y][ps.x] == '1')
				draw_square(sys, pos, map->size, map->color);
			if (map->matrix_map[ps.y][ps.x] == 'x')
				draw_square(sys, pos, map->size, RED);
			if (map->matrix_map[ps.y][ps.x] == 'z')
				draw_square(sys, pos, map->size, GREEN);
			draw_player(map->matrix_map[ps.y][ps.x], ps, sys);
			ps.x++;
		}
		ps.y++;
	}
}

static void	draw_player(char c, t_point ps, t_system *sys)
{
	if (c != 'N' && c != 'E' && c != 'W' && c != 'S')
		return ;
	draw_square(sys, (t_point){ps.x * (sys->map.size + 1), ps.y * (sys->map.size
			+ 1)}, sys->map.size, CYAN);
}

static void	move_player(t_system *sys, char player)
{
	t_point		p;
	static char	ch;
	t_point		pos;

	if (!ch)
		ch = '0';
	pos = (t_point){sys->player.pos.x / BLOCK, sys->player.pos.y / BLOCK};
	p.y = 0;
	while (sys->map_matrix[p.y])
	{
		p.x = 0;
		while (sys->map_matrix[p.y][p.x])
		{
			if (sys->map_matrix[p.y][p.x] == player)
			{
				sys->map_matrix[p.y][p.x] = ch;
				ch = check_door(ch, sys->map_matrix[pos.y][pos.x]);
				sys->map_matrix[pos.y][pos.x] = player;
				return ;
			}
			p.x++;
		}
		p.y++;
	}
}

static char	check_door(char ch, char current_pos)
{
	if (ch == '0' && current_pos == 'x' || current_pos == 'z')
		return (current_pos);
	return ('0');
}
