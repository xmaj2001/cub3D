/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:10:28 by xjose             #+#    #+#             */
/*   Updated: 2025/03/06 22:48:22 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	draw_background(t_system *sys, int color_sky, int color_plane)
{
	int	i;
	int	x;

	i = 0;
	while (i < (HEIGHT / 2))
	{
		x = 0;
		while (x < WIDTH)
			put_pixel(sys, x++, i, color_sky);
		i++;
	}
	while (i < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			put_pixel(sys, x++, i, color_plane);
		i++;
	}
}
