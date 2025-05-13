/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:23:30 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 09:46:09 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	error_textures(t_system *sys)
{
	int	texture;

	texture = 1;
	while (texture <= 4)
	{
		if (sys->map.textures[texture].img == NULL)
			break ;
		texture++;
	}
	if (texture == NORTH)
		return (ft_putstr_fd("Error\nNorth texture not found\n", STDERR_FILENO),
			0);
	else if (texture == SOUTH)
		return (ft_putstr_fd("Error\nSouth texture not found\n", STDERR_FILENO),
			0);
	else if (texture == WEST)
		return (ft_putstr_fd("Error\nWest texture not found\n", STDERR_FILENO),
			0);
	else if (texture == EAST)
		return (ft_putstr_fd("Error\nEast texture not found\n", STDERR_FILENO),
			0);
	else
		return (1);
}
