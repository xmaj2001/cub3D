/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:18:00 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 09:53:42 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	ft_check_argc(int argc)
{
	if (argc != 2)
		ft_error("Wrong number of arguments");
}

static void	ft_initi_dup_pos(t_dup_dir *dup, t_pos *pos)
{
	dup->no = 0;
	dup->so = 0;
	dup->we = 0;
	dup->ea = 0;
	dup->w_counter = 0;
	dup->e_counter = 0;
	dup->n_counter = 0;
	dup->s_counter = 0;
	dup->c_counter = 0;
	dup->f_counter = 0;
	pos->x = 0;
	pos->y = 0;
	pos->north_texture = NULL;
	pos->south_texture = NULL;
	pos->west_texture = NULL;
	pos->east_texture = NULL;
}

static void	ft_init_structure(t_system *game)
{
	game->matrix = NULL;
	game->matrix = NULL;
	game->matrix_cd = NULL;
	game->map_matrix = NULL;
	game->i = 0;
	game->dup_dir->no = 0;
	game->dup_dir->so = 0;
	game->dup_dir->we = 0;
	game->dup_dir->ea = 0;
	game->dup_dir->f_counter = 0;
	game->dup_dir->f_counter = 0;
}

void	init_map(t_system *sys, int argc, char **argv)
{
	t_dup_dir	*dup;
	t_pos		*pos;

	ft_check_argc(argc);
	dup = malloc(sizeof(t_dup_dir));
	pos = malloc(sizeof(t_pos));
	ft_initi_dup_pos(dup, pos);
	sys->dup_dir = dup;
	sys->pos = pos;
	ft_init_structure(sys);
	ft_handling_map(sys, argv[1]);
	pos->floor[ft_strlen(pos->floor) - 1] = '\0';
	pos->ceiling[ft_strlen(pos->ceiling) - 1] = '\0';
	sys->map.floor_color = get_rgb(pos->floor);
	sys->map.ceiling_color = get_rgb(pos->ceiling);
	sys->map.looking_dir = pos->looking_dir;
	sys->map.matrix_map = sys->map_matrix;
	sys->map.size = 5;
	sys->map.color = WHITE;
}
