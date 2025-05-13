/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:23:30 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 10:02:11 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	start_pos(char dir);

void	init_system(int argc, char **argv, t_system *sys)
{
	sys->state = STOP;
	init_map(sys, argc, argv);
	sys->mlx = mlx_init();
	init_background(sys);
	init_textures(sys);
	add_textures(sys);
	sys->win = mlx_new_window(sys->mlx, WIDTH, HEIGHT, "CUB3D");
	init_player(sys, (t_point){sys->pos->y, sys->pos->x},
		start_pos(sys->pos->looking_dir));
}

static int	start_pos(char dir)
{
	if (dir == 'N')
		return (NORTH);
	else if (dir == 'S')
		return (SOUTH);
	else if (dir == 'W')
		return (WEST);
	else if (dir == 'E')
		return (EAST);
	return (-1);
}
