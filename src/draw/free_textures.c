/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:10:28 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 10:24:35 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	free_texture(enum e_coord coord, t_system *sys);

void	free_textures(t_system *sys)
{
	free_texture(NORTH, sys);
	free_texture(SOUTH, sys);
	free_texture(WEST, sys);
	free_texture(EAST, sys);
	mlx_destroy_image(sys->mlx, sys->door_texture[0].img);
	mlx_destroy_image(sys->mlx, sys->door_texture[1].img);
	mlx_destroy_image(sys->mlx, sys->door_texture[2].img);
	mlx_destroy_image(sys->mlx, sys->sprite[0].img);
	mlx_destroy_image(sys->mlx, sys->sprite[1].img);
	mlx_destroy_image(sys->mlx, sys->sprite[2].img);
	mlx_destroy_image(sys->mlx, sys->sprite[3].img);
	mlx_destroy_image(sys->mlx, sys->sprite[4].img);
	mlx_destroy_image(sys->mlx, sys->sprite[5].img);
	mlx_destroy_image(sys->mlx, sys->sprite[6].img);
	mlx_destroy_image(sys->mlx, sys->sprite[7].img);
	mlx_destroy_image(sys->mlx, sys->sprite[8].img);
	mlx_destroy_image(sys->mlx, sys->ui.win.img);
}

static void	free_texture(enum e_coord coord, t_system *sys)
{
	if (sys->map.textures[coord].img != NULL)
	{
		mlx_destroy_image(sys->mlx, sys->map.textures[coord].img);
		free(sys->map.path_textures[coord]);
	}
}
