/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:10:28 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 10:18:55 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	add_textures(t_system *sys)
{
	sys->map.textures[NORTH] = load_texture(sys, sys->map.path_textures[NORTH]);
	sys->map.textures[SOUTH] = load_texture(sys, sys->map.path_textures[SOUTH]);
	sys->map.textures[WEST] = load_texture(sys, sys->map.path_textures[WEST]);
	sys->map.textures[EAST] = load_texture(sys, sys->map.path_textures[EAST]);
	sys->map.textures[4] = sys->map.textures[NORTH];
	sys->door_texture[0] = load_texture(sys, "textures/door.xpm");
	sys->door_texture[1] = load_texture(sys, "textures/Open.xpm");
	sys->door_texture[2] = load_texture(sys, "textures/Close.xpm");
	sys->sprite[0] = load_texture(sys, "./textures/sprite.xpm");
	sys->sprite[1] = load_texture(sys, "./textures/sprite1.xpm");
	sys->sprite[2] = load_texture(sys, "./textures/sprite2.xpm");
	sys->sprite[3] = load_texture(sys, "./textures/sprite3.xpm");
	sys->sprite[4] = load_texture(sys, "./textures/sprite4.xpm");
	sys->sprite[5] = load_texture(sys, "./textures/sprite5.xpm");
	sys->sprite[6] = load_texture(sys, "./textures/box1.xpm");
	sys->sprite[7] = load_texture(sys, "./textures/sprite7.xpm");
	sys->sprite[8] = load_texture(sys, "./textures/sprite8.xpm");
	return (error_textures(sys));
}
