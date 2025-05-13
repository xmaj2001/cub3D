/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:40:22 by mefernan          #+#    #+#             */
/*   Updated: 2024/05/18 14:40:34 by mefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lista;

	lista = malloc(sizeof(t_list));
	if (!lista)
	{
		return (0);
	}
	lista->content = content;
	lista->next = 0;
	return (lista);
}
