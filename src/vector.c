/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:26:49 by xjose             #+#    #+#             */
/*   Updated: 2025/03/07 17:04:15 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_vector	new_vector(float x, float y)
{
	return ((t_vector){x, y});
}

t_vector	sum_vector(t_vector v1, t_vector v2)
{
	return ((t_vector){v1.x + v2.x, v1.y + v2.y});
}

t_vector	mult_vector(t_vector vector, double mult)
{
	return ((t_vector){vector.x * mult, vector.y * mult});
}

t_vector	rotate_vector(t_vector v, float angle)
{
	t_vector	new_vector;
	float		radians;

	radians = angle * PI / 180.0;
	new_vector.x = v.x * cos(radians) - v.y * sin(radians);
	new_vector.y = v.x * sin(radians) + v.y * cos(radians);
	return (new_vector);
}
