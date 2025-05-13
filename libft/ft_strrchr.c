/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:54:13 by mefernan          #+#    #+#             */
/*   Updated: 2024/05/18 14:54:33 by mefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	last_index;

	i = 0;
	last_index = -1;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			last_index = i;
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	else if (last_index != -1)
		return ((char *)&s[last_index]);
	return (NULL);
}
