/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:28:20 by mefernan          #+#    #+#             */
/*   Updated: 2025/03/08 09:56:26 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static char	*ft_take_out_slash_n(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && line[i + 1] == '\0')
			line[i] = '\0';
		i++;
	}
	return (line);
}

static void	ft_validate_direction(char *line, t_system *game)
{
	char	**matrix;

	matrix = ft_split(line, ' ');
	ft_check_directions(line, matrix, game);
	if (ft_count_lines_in_matrix(matrix) != 2)
	{
		ft_free_matrix(matrix);
		ft_free_resources(game, 0);
		ft_error("Misconfiguration in the file");
	}
	matrix[1] = ft_take_out_slash_n(matrix[1]);
	if (open(matrix[1], 0) < 0)
	{
		ft_free_matrix(matrix);
		ft_free_resources(game, 0);
		ft_error("Not a valid path for texture");
	}
	if (ft_check_texture_extention(matrix[1]) == 1)
	{
		ft_free_matrix(matrix);
		ft_free_resources(game, 0);
		ft_error("Texture's extention is misconfigurated");
	}
	ft_free_matrix(matrix);
}

void	ft_some_checks(t_system *game)
{
	int	var[3];

	ft_memset(var, 0, sizeof(var));
	while (game->matrix_cd[var[0]])
	{
		if (ft_condition(game->matrix_cd[var[0]], 1, var[0]))
		{
			ft_validate_direction(game->matrix_cd[var[0]], game);
			var[1]++;
		}
		else if (ft_condition(game->matrix_cd[var[0]], 0, var[0]))
		{
			ft_validate_colors(game->matrix_cd[var[0]], game);
			var[2]++;
		}
		else
		{
			if (var[2] != 2 && var[1] != 4 && var[0] < 6)
				ft_free_resources(game, 0);
		}
		var[0]++;
	}
	ft_if_duplicated_dir_or_color(game);
}

static void	ft_check_extention(t_system *game, char *map)
{
	int		i;
	int		len;
	char	*extention;

	i = 0;
	len = 0;
	extention = ".cub";
	len = ft_strlen(map);
	if (len < 4)
	{
		ft_free_mlx_ptr(game);
		ft_error("Map extention error");
	}
	len = len - 4;
	while (map[len] != 0)
	{
		if (map[len] != extention[i])
		{
			ft_free_mlx_ptr(game);
			ft_error("Map extention error");
		}
		i++;
		len++;
	}
}

void	ft_handling_map(t_system *game, char *map)
{
	int		j;
	int		fd;
	char	*line;

	j = 0;
	ft_check_extention(game, map);
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_free_mlx_ptr(game);
		ft_error("Failed to open the map file");
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = NULL;
		j++;
		line = get_next_line(fd);
	}
	close(fd);
	ft_handling_aux(game, j, map);
}
