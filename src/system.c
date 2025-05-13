/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:05:17 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 09:27:00 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	stop_system(t_system *sys);

void	run_system(t_system *sys)
{
	close_window(sys);
	player_keypress(sys);
	mlx_loop_hook(sys->mlx, frame, sys);
	mlx_loop(sys->mlx);
	stop_system(sys);
}

static void	stop_system(t_system *sys)
{
	sys->state = 0;
	free_textures(sys);
	free(sys->pos->ceiling);
	free(sys->pos->floor);
	free(sys->dup_dir);
	free(sys->pos);
	mlx_destroy_image(sys->mlx, sys->bg.img);
	if (sys->win)
		mlx_destroy_window(sys->mlx, sys->win);
	mlx_destroy_display(sys->mlx);
	free(sys->mlx);
}

int	exit_game(t_system *sys)
{
	stop_system(sys);
	free_matrix(sys->matrix);
	free_matrix(sys->matrix_cd);
	free_matrix(sys->map_matrix);
	exit(0);
}

void	close_window(t_system *sys)
{
	mlx_hook(sys->win, 17, 0, exit_game, sys);
}
