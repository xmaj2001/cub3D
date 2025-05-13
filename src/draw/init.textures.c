/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:10:28 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 10:03:54 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	init_textures(t_system *sys)
{
	sys->pos->north_texture[ft_strlen(sys->pos->north_texture) - 1] = '\0';
	sys->pos->south_texture[ft_strlen(sys->pos->south_texture) - 1] = '\0';
	sys->pos->west_texture[ft_strlen(sys->pos->west_texture) - 1] = '\0';
	sys->pos->east_texture[ft_strlen(sys->pos->east_texture) - 1] = '\0';
	sys->map.path_textures[NORTH] = sys->pos->north_texture;
	sys->map.path_textures[SOUTH] = sys->pos->south_texture;
	sys->map.path_textures[WEST] = sys->pos->west_texture;
	sys->map.path_textures[EAST] = sys->pos->east_texture;
}
