/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:10:28 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 09:32:58 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

t_texture	load_texture(t_system *sys, char *path)
{
	t_texture	texture;

	texture.img = mlx_xpm_file_to_image(sys->mlx, path, &texture.width,
			&texture.height);
	if (texture.img == NULL)
		return (texture);
	texture.addr = (int *)mlx_get_data_addr(texture.img, &texture.bpp,
			&texture.size_line, &texture.endian);
	return (texture);
}
