/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:47:17 by mefernan          #+#    #+#             */
/*   Updated: 2024/05/18 14:47:27 by mefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*str;

	str = NULL;
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(str, s, ft_strlen(s) + 1);
	return (str);
}
