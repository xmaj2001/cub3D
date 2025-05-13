/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_map4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:33:15 by mefernan          #+#    #+#             */
/*   Updated: 2025/02/22 13:58:47 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static int	is_valid_char(char c)
{
	if (c != '1' && c != '0' && c != 'W'
		&& c != 'N' && c != 'E' && c != 'S'
		&& c != ' ' && c != 'x')
		return (1);
	return (0);
}

void	ft_check_invalid_char(t_system *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_matrix[i])
	{
		j = 0;
		while (game->map_matrix[i][j])
		{
			if (is_valid_char(game->map_matrix[i][j]))
			{
				ft_free_matrix(game->matrix);
				ft_free_matrix(game->map_matrix);
				ft_free_matrix(game->matrix_cd);
				ft_free_mlx_ptr(game);
				ft_error("Invalid character in the map");
			}
			j++;
		}
		i++;
	}
}

static int	count_line(t_system *game)
{
	int	i;
	int	len;

	i = game->i;
	len = 0;
	while (game->matrix[i])
	{
		i++;
		len++;
	}
	return (len);
}

void	ft_fill_map_matrix(t_system *game)
{
	int	len;

	len = 0;
	while (game->matrix[game->i] != NULL
		&& ft_only_spaces(game->matrix[game->i]) == 0)
		game->i++;
	if (game->matrix[game->i] == NULL)
	{
		ft_free_matrix(game->matrix);
		ft_free_matrix(game->map_matrix);
		ft_free_matrix(game->matrix_cd);
		ft_free_mlx_ptr(game);
		ft_error("No map found");
	}
	len = count_line(game);
	game->map_matrix = malloc(sizeof(char *) * (len + 1));
	len = 0;
	while (game->matrix[game->i])
	{
		game->map_matrix[len] = ft_strdup(game->matrix[game->i]);
		len++;
		game->i++;
	}
	game->map_matrix[len] = NULL;
}
