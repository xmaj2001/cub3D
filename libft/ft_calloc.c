/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:33:43 by mefernan          #+#    #+#             */
/*   Updated: 2024/05/18 14:33:58 by mefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	size_max;

	size_max = 4294967295;
	if (count == 0 || size == 0)
		return (malloc(1));
	if (count > size_max / size)
		return (NULL);
	ptr = malloc(count * size);
	ft_bzero(ptr, size * count);
	return (ptr);
}
