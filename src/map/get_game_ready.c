/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_game_ready.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:10:01 by mefernan          #+#    #+#             */
/*   Updated: 2025/02/22 12:19:12 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

char	*ft_spaces_in_color_line(char *line)
{
	int		i;
	int		j;
	int		flag;
	char	str[7000];

	i = 0;
	j = 0;
	flag = 0;
	while (line[i])
	{
		if (line[i] == ' ' && flag == 0)
		{
			str[j++] = line[i++];
			flag = 1;
		}
		else if (line[i] == ' ')
			i++;
		else
			str[j++] = line[i++];
	}
	str[j] = '\0';
	return (ft_strdup(str));
}

static void	condition_plus(t_system *game, int i)
{
	char	**matrix;

	matrix = ft_split(game->matrix_cd[i], ' ');
	if (ft_strncmp(game->matrix_cd[i], "NO ", 3) == 0)
		game->pos->north_texture = ft_strdup(matrix[1]);
	else if (ft_strncmp(game->matrix_cd[i], "WE ", 3) == 0)
		game->pos->west_texture = ft_strdup(matrix[1]);
	else if (ft_strncmp(game->matrix_cd[i], "EA ", 3) == 0)
		game->pos->east_texture = ft_strdup(matrix[1]);
	else if (ft_strncmp(game->matrix_cd[i], "SO ", 3) == 0)
		game->pos->south_texture = ft_strdup(matrix[1]);
	if (matrix)
		ft_free_matrix(matrix);
}

static void	ft_colors_and_textures(t_system *game, int i)
{
	char	*taker;
	char	**matrix1;

	while (game->matrix_cd[i] != NULL)
	{
		condition_plus(game, i);
		if (ft_strncmp(game->matrix_cd[i], "F ", 2) == 0)
		{
			taker = ft_spaces_in_color_line(game->matrix_cd[i]);
			matrix1 = ft_split(taker, ' ');
			free(taker);
			game->pos->floor = ft_strdup(matrix1[1]);
			ft_free_matrix(matrix1);
		}
		else if (ft_strncmp(game->matrix_cd[i], "C ", 2) == 0)
		{
			taker = ft_spaces_in_color_line(game->matrix_cd[i]);
			matrix1 = ft_split(taker, ' ');
			free(taker);
			game->pos->ceiling = ft_strdup(matrix1[1]);
			ft_free_matrix(matrix1);
		}
		i++;
	}
}

static int	ft_condition_here(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	ft_get_game_ready(t_system *game)
{
	int	var[3];
	int	flag;

	flag = 0;
	ft_memset(var, 0, sizeof(var));
	while (game->map_matrix[var[0]])
	{
		var[1] = 0;
		while (game->map_matrix[var[0]][var[1]])
		{
			if (ft_condition_here(game->map_matrix[var[0]][var[1]]))
			{
				game->pos->x = var[0];
				game->pos->y = var[1];
				game->pos->looking_dir = game->map_matrix[var[0]][var[1]];
				flag = 1;
				break ;
			}
			var[1]++;
		}
		if (flag == 1)
			break ;
		var[0]++;
	}
	ft_colors_and_textures(game, var[2]);
}
