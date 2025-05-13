/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:10:28 by xjose             #+#    #+#             */
/*   Updated: 2025/03/06 22:49:06 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	put_pixel(t_system *sys, int x, int y, int color)
{
	int		index;
	t_image	*bg;

	bg = &sys->bg;
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = (y * bg->size_line) + (x * bg->bpp) / 8;
	bg->addr[index] = color & 0xFF;
	bg->addr[index + 1] = (color >> 8) & 0xFF;
	bg->addr[index + 2] = (color >> 16) & 0xFF;
}
