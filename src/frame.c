/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:03:11 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 10:17:25 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	frame(t_system *sys)
{
	if (sys->state == PLAY)
	{
		draw_background(sys, sys->map.ceiling_color, sys->map.floor_color);
		player_move(sys);
		player_rotation(sys);
		raycast(sys);
		if (sys->player.door == 'x')
			print_image(sys, &sys->door_texture[1], WIDTH / 2, HEIGHT / 2);
		else if (sys->player.door == 'z')
			print_image(sys, &sys->door_texture[2], WIDTH / 2, HEIGHT / 2);
		sprite(sys);
		draw_minimap(sys);
		update_background(sys);
	}
	return (0);
}
