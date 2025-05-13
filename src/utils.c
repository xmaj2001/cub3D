/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:05:17 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 09:51:10 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_matrix(char **mt)
{
	int	i;

	i = 0;
	while (mt[i])
	{
		free(mt[i++]);
	}
	free(mt);
}

int	get_rgb(char *colors)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(colors, ',');
	r = ft_atoi(rgb[0]) * pow(2, 16);
	g = ft_atoi(rgb[1]) * pow(2, 8);
	b = ft_atoi(rgb[2]);
	free_matrix(rgb);
	return (r + g + b);
}
