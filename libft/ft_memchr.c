/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:41:23 by mefernan          #+#    #+#             */
/*   Updated: 2024/05/18 14:41:34 by mefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	if (!arr)
	{
		return (NULL);
	}
	i = 0;
	str = (unsigned char *)arr;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == ch)
			return (str + i);
		i++;
	}
	return (NULL);
}
