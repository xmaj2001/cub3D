/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 06:26:56 by mefernan          #+#    #+#             */
/*   Updated: 2025/03/08 09:56:17 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	ft_count_lines_in_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

int	string_comp(char *s1, char *s2)
{
	int	i;

	if (s1 == NULL || s2 == NULL)
		return (1);
	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

int	ft_check_texture_extention(char *texture)
{
	int		j;
	int		len;
	char	*extention;

	len = 0;
	j = 0;
	extention = ".xpm";
	len = ft_strlen(texture);
	len = len - 4;
	while (texture[len] != '\0' && j < 4)
	{
		if (texture[len] != extention[j])
			return (1);
		j++;
		len++;
	}
	return (0);
}

static void	ft_count_direction(char *line, t_system *game)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		game->dup_dir->no++;
	else if (ft_strncmp(line, "EA ", 3) == 0)
		game->dup_dir->ea++;
	else if (ft_strncmp(line, "SO ", 3) == 0)
		game->dup_dir->so++;
	else if (ft_strncmp(line, "WE ", 3) == 0)
		game->dup_dir->we++;
}

void	ft_check_directions(char *line, char **matrix, t_system *game)
{
	if (ft_strncmp(line, "NO ", 3) != 0 && ft_strncmp(line, "EA ", 3) != 0
		&& ft_strncmp(line, "SO ", 3) != 0 && ft_strncmp(line, "WE ", 3) != 0)
	{
		ft_free_matrix(matrix);
		ft_free_matrix(game->matrix);
		ft_free_matrix(game->matrix_cd);
		ft_free_mlx_ptr(game);
		ft_error("Direction's misconfiguration in the map");
	}
	ft_count_direction(line, game);
}
