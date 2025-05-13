/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:10:28 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 10:03:35 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	draw_square(t_system *sys, t_point p, int size, int color)
{
	int	i;
	int	x;

	i = 0;
	while (i < size)
	{
		x = 0;
		while (x++ < size)
			put_pixel(sys, p.x + x, p.y + i, color);
		i++;
	}
}
