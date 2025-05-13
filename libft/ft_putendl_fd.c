/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:44:16 by mefernan          #+#    #+#             */
/*   Updated: 2024/05/18 14:44:27 by mefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
	{
		return ;
	}
	else if (fd < 0)
	{
		return ;
	}
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
