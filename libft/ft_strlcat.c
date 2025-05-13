/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:49:39 by mefernan          #+#    #+#             */
/*   Updated: 2024/05/18 14:50:01 by mefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l;
	size_t	lr;

	l = 0;
	lr = 0;
	while (dst[l] != '\0' && l < size)
	{
		l++;
	}
	while (src[lr] != '\0' && (l + lr + 1) < size)
	{
		dst[l + lr] = src[lr];
		lr++;
	}
	if (l != size)
	{
		dst[l + lr] = '\0';
	}
	return (l + ft_strlen(src));
}
