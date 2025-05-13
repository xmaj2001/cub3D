/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:50:15 by mefernan          #+#    #+#             */
/*   Updated: 2024/05/18 14:51:09 by mefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	l;

	l = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	else
	{
		while (src[l] != '\0' && l < (size - 1))
		{
			dst[l] = src[l];
			l++;
		}
		dst[l] = '\0';
	}
	return (ft_strlen(src));
}
