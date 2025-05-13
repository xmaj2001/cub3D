/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_map3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 08:40:00 by mefernan          #+#    #+#             */
/*   Updated: 2025/03/07 15:50:59 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static int	ft_color_num(char *color_value)
{
	if ((ft_atoi(color_value) >= 0 && ft_atoi(color_value) <= 255)
		&& ft_atoi(color_value) != -999)
		return (0);
	return (1);
}

static void	ft_count_color_leter(char *str, t_system *game)
{
	if (ft_strncmp(str, "F", 2) == 0)
		game->dup_dir->f_counter++;
	else if (ft_strncmp(str, "C", 2) == 0)
		game->dup_dir->c_counter++;
}

static void	ft_free_here(t_system *game, char **matrix1, char **matrix2,
		int flag)
{
	if (flag == 1)
	{
		ft_free_matrix(matrix1);
		ft_free_matrix(game->matrix);
		ft_free_matrix(game->matrix_cd);
		ft_free_mlx_ptr(game);
		ft_error("Too many or less items in the color line");
	}
	else
	{
		ft_free_matrix(matrix1);
		ft_free_matrix(matrix2);
		ft_free_matrix(game->matrix);
		ft_free_matrix(game->matrix_cd);
		ft_free_mlx_ptr(game);
		if (flag == 2)
			ft_error("Color value has some essue, chack it out");
		ft_error("Too many or less number representing the colors");
	}
}

void	ft_validate_colors(char *line, t_system *game)
{
	char	**matrix1;
	char	**matrix2;

	line = ft_spaces_in_color_line(line);
	matrix1 = ft_split(line, ' ');
	if (ft_count_lines_in_matrix(matrix1) != 2)
		ft_free_here(game, matrix1, NULL, 1);
	if (ft_strncmp(matrix1[0], "F", 2) != 0 && ft_strncmp(matrix1[0], "C",
			2) != 0)
		ft_free_here(game, matrix1, NULL, 1);
	ft_count_color_leter(matrix1[0], game);
	matrix2 = ft_split(matrix1[1], ',');
	if (ft_count_lines_in_matrix(matrix2) != 3)
		ft_free_here(game, matrix1, matrix2, 0);
	if (ft_color_num(matrix2[0]) == 1 || ft_color_num(matrix2[1]) == 1
		|| ft_color_num(matrix2[2]) == 1)
		ft_free_here(game, matrix1, matrix2, 2);
	free(line);
	ft_free_matrix(matrix1);
	ft_free_matrix(matrix2);
}

void	ft_fill_color_dir_mat(t_system *game)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	game->matrix_cd = malloc(sizeof(char *) * 7);
	if (!game->matrix_cd)
		ft_error("Malloc matrix_cd failed");
	while (game->matrix[i])
	{
		if (ft_only_spaces(game->matrix[i]) != 0 && counter < 6)
			game->matrix_cd[counter++] = ft_strdup(game->matrix[i]);
		i++;
		if (counter >= 6)
			break ;
	}
	game->i = i;
	while (counter < 6)
		game->matrix_cd[counter++] = NULL;
	game->matrix_cd[counter++] = NULL;
}
