/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_map_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:45:24 by mefernan          #+#    #+#             */
/*   Updated: 2025/03/14 23:07:06 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	ft_get_rid_of_slash_n(t_system *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_matrix[i])
	{
		j = 0;
		while (game->map_matrix[i][j])
		{
			if (game->map_matrix[i][j] == '\n' && game->map_matrix[i][j
				+ 1] == '\0')
				game->map_matrix[i][j] = '\0';
			j++;
		}
		i++;
	}
}

void	ft_print_error(t_system *game, int flag)
{
	ft_free_matrix(game->matrix);
	ft_free_matrix(game->matrix_cd);
	ft_free_matrix(game->map_matrix);
	ft_free_mlx_ptr(game);
	if (flag == 1)
		ft_error("A zero has a space around it");
	if (flag == 2)
		ft_error("A zero or (N,W,S,E,x) is at one extreme of the map");
	if (flag == 3)
		ft_error("A zero is in the first or last line of the map");
}

static void	ft_erros(t_system *game, int i, int j, char *str)
{
	printf("[%d][%d]\n", i, j);
	printf("%s\n", str);
	ft_print_error(game, 1);
}

void	ft_conditions_for_zeros(t_system *game, int i, int j, int len1)
{
	if (j > 0 && ft_space(game->map_matrix[i][j - 1]))
		ft_erros(game, i, j, "[i][j - 1]");
	if (j < (int)ft_strlen(game->map_matrix[i]) - 1
		&& ft_space(game->map_matrix[i][j + 1]))
		ft_erros(game, i, j, "[i][j + 1]");
	if ((i < len1 - 1 && j < (int)ft_strlen(game->map_matrix[i + 1]))
		&& ft_space(game->map_matrix[i + 1][j]))
		ft_erros(game, i, j, "[i + 1][j]");
	else if (j >= (int)ft_strlen(game->map_matrix[i + 1]))
		ft_erros(game, i, j, "[i + 1][j]");
	if (i > 0 && ft_space(game->map_matrix[i - 1][j]))
		ft_erros(game, i, j, "[i - 1][j]");
	if ((i > 0 && j < (int)ft_strlen(game->map_matrix[i - 1]) - 1)
		&& ft_space(game->map_matrix[i - 1][j + 1]))
		ft_erros(game, i, j, "[i - 1][j + 1]");
	if ((i > 0 && j > 0) && ft_space(game->map_matrix[i - 1][j - 1]))
		ft_erros(game, i, j, "[i - 1][j - 1]");
	if ((i < len1 - 1 && j < (int)ft_strlen(game->map_matrix[i - 1]) - 1)
		&& ft_space(game->map_matrix[i + 1][j + 1]))
		ft_erros(game, i, j, "[i + 1][j + 1]");
	if ((i < len1 - 1 && j > 0) && ft_space(game->map_matrix[i + 1][j - 1]))
		ft_erros(game, i, j, "[i + 1][j - 1]");
}
