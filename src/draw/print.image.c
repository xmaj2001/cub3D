/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:10:28 by xjose             #+#    #+#             */
/*   Updated: 2025/03/07 08:55:46 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	print_image(t_system *sys, t_texture *img, int x, int y)
{
	int	i;
	int	_x;
	int	_y;
	int	index;
	int	color;

	i = 0;
	while (i < img->height)
	{
		_y = 0;
		while (_y < img->width)
		{
			color = get_color_texture(*img, i, _y);
			if ((color & 0xFFFFFF) != 0x000000)
			{
				index = (y + i) * sys->bg.size_line + (x + _y) * sys->bg.bpp
					/ 8;
				sys->bg.addr[index] = color & 0xFF;
				sys->bg.addr[index + 1] = (color >> 8) & 0xFF;
				sys->bg.addr[index + 2] = (color >> 16) & 0xFF;
			}
			_y++;
		}
		i++;
	}
}
