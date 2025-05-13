/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:23:30 by xjose             #+#    #+#             */
/*   Updated: 2025/03/06 22:48:47 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	init_background(t_system *sys)
{
	t_image	*bg;

	bg = &sys->bg;
	bg->img = mlx_new_image(sys->mlx, WIDTH, HEIGHT);
	bg->addr = mlx_get_data_addr(bg->img, &bg->bpp, &bg->size_line,
			&bg->endian);
}
