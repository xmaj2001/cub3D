/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:32:17 by mefernan          #+#    #+#             */
/*   Updated: 2024/05/18 14:33:34 by mefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	num;
	int				i;
	int				np;

	np = 1;
	i = 0;
	num = 0;
	while ((str[i] == ' ' || str[i] == '\t') || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			np = -1;
		i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-999);
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-999);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0' && str[i] != '\n')
		return (-999);
	return ((int)(np * num));
}
