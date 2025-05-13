/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_map0.5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:46:03 by mefernan          #+#    #+#             */
/*   Updated: 2025/02/22 12:11:55 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	ft_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			return (1);
		i++;
	}
	return (0);
}

static int	condition(char *line, int i)
{
	if (((ft_strchr(line, 'N') != NULL || ft_strchr(line, 'O') != NULL
				|| ft_strchr(line, 'S') != NULL
				|| ft_strchr(line, 'E') != NULL
				|| ft_strchr(line, 'W') != NULL
				|| ft_strchr(line, 'A') != NULL)) && i < 6)
		return (1);
	return (0);
}

int	ft_condition(char *line, int flag, int i)
{
	if (flag)
	{
		if (condition(line, i))
			return (1);
		return (0);
	}
	else
	{
		if ((((ft_strchr(line, 'F') != NULL || ft_strchr(line, 'C') != NULL)
					&& (ft_strchr(line, '0') != NULL
						|| ft_strchr(line, '1') != NULL
						|| ft_strchr(line, '2') != NULL
						|| ft_strchr(line, '3') != NULL
						|| ft_strchr(line, '4') != NULL
						|| ft_strchr(line, '5') != NULL
						|| ft_strchr(line, '6') != NULL
						|| ft_strchr(line, '7') != NULL
						|| ft_strchr(line, '8') != NULL
						|| ft_strchr(line, '9') != NULL))) && i < 6)
			return (1);
		return (0);
	}
}

void	ft_handling_aux(t_system *game, int y, char *map)
{
	int		j;
	int		fd;
	char	*line;
	char	**buffer;

	buffer = malloc(sizeof(char *) * (y + 1));
	if (!buffer)
		ft_error("Something went wrong alocating buf1");
	j = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("Failed to open the map file");
	line = get_next_line(fd);
	while (line != NULL)
	{
		buffer[j++] = line;
		line = get_next_line(fd);
	}
	buffer[j] = NULL;
	game->matrix = buffer;
	ft_more_function_calls(game);
}
