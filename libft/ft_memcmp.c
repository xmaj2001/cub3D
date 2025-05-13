/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:41:48 by mefernan          #+#    #+#             */
/*   Updated: 2024/05/18 14:41:53 by mefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*si1;
	unsigned char	*si2;
	size_t			i;

	i = 0;
	si1 = (unsigned char *)s1;
	si2 = (unsigned char *)s2;
	while (i < n)
	{
		if (si1[i] == si2[i])
		{
			i++;
		}
		else
		{
			return (si1[i] - si2[i]);
		}
	}
	return (0);
}
