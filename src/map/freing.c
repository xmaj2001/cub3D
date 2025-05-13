/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 04:36:46 by mefernan          #+#    #+#             */
/*   Updated: 2025/02/26 09:02:57 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	ft_free_mlx_ptr(t_system *game)
{
	if (game->dup_dir)
		free(game->dup_dir);
	if (game->pos)
		free(game->pos);
}

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i])
		{
			if (matrix[i])
				free(matrix[i]);
			i++;
		}
		free(matrix);
	}
}
