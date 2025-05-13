/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_map5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:21:27 by mefernan          #+#    #+#             */
/*   Updated: 2025/03/14 23:11:02 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	ft_space(char c)
{
	if (c == ' ' || c == '\0')
		return (1);
	return (0);
}

static int	is_char_valide(char c)
{
	if (c == 'E' || c == 'N' || c == 'W' || c == 'S' || c == 'x')
		return (1);
	return (0);
}

static int	ft_double_slash_n(t_system *game)
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
			{
				if (game->map_matrix[i + 1] != NULL)
					if (game->map_matrix[i + 1][0] == '\n'
						|| ft_only_spaces(game->map_matrix[i + 1]) == 0)
						return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_check_slash_n(t_system *game)
{
	if (ft_double_slash_n(game) == 1)
	{
		ft_free_resources(game, 0);
		ft_error("Tow or more slash n in the map");
	}
}

void	ft_check_ones(t_system *game)
{
	int	i;
	int	j;
	int	len1;

	i = 0;
	len1 = ft_count_lines_in_matrix(game->map_matrix);
	while (game->map_matrix[i] != NULL)
	{
		j = 0;
		while (game->map_matrix[i][j] != '\0')
		{
			if (game->map_matrix[i][j] == '0' && (i == 0 || i == len1 - 1))
				ft_print_error(game, 3);
			if (game->map_matrix[i][j] == '0' ||
				is_char_valide(game->map_matrix[i][j]))
			{
				if (j == 0 || j == (int)ft_strlen(game->map_matrix[i]) - 1)
					ft_print_error(game, 2);
				ft_conditions_for_zeros(game, i, j, len1);
			}
			j++;
		}
		i++;
	}
}
