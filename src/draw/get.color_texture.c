/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.color_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:10:28 by xjose             #+#    #+#             */
/*   Updated: 2025/03/06 22:48:42 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	get_color_texture(t_texture tex, int y, int x)
{
	int	texture_pos;

	if (x < 0 || x >= tex.width || y < 0 || y >= tex.height)
		return (0x0);
	return (*(int *)(tex.addr + (tex.width * y) + x));
}
