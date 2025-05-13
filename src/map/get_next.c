/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:47:48 by mefernan          #+#    #+#             */
/*   Updated: 2025/03/08 09:55:17 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

char	*get_next_line(int fd)
{
	static char	taker[1];
	char		str[8000];
	static int	buffer_size;
	static int	buffer_position;
	int			i;

	i = 0;
	if (fd < 0)
		return (NULL);
	while (1)
	{
		if (buffer_position >= buffer_size)
		{
			buffer_size = read(fd, taker, 1);
			buffer_position = 0;
			if (buffer_size == 0)
				break ;
		}
		str[i++] = taker[buffer_position++];
		if (str[i - 1] == '\n')
			break ;
	}
	if (i == 0)
		return (NULL);
	return (str[i] = '\0', ft_strdup(str));
}
