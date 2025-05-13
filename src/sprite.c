/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:16:19 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 10:21:36 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	sprite_animation_0(t_system *sys, int sprite);
static void	sprite_animation_1(t_system *sys, int sprite);
static void	sprite_animation_2(t_system *sys, int sprite);

void	sprite(t_system *sys)
{
	static int	frame;
	static int	sprite;

	sprite_animation_0(sys, sprite);
	if (frame == 15)
	{
		sprite++;
		if (sprite > 16)
			sprite = 0;
		frame = 0;
	}
	frame++;
}

static void	sprite_animation_0(t_system *sys, int sprite)
{
	if (sprite == 0)
		print_image(sys, &sys->sprite[0], WIDTH - sys->sprite[0].height, HEIGHT
			- sys->sprite[0].height);
	else if (sprite == 1)
		print_image(sys, &sys->sprite[0], WIDTH - sys->sprite[0].height, HEIGHT
			- sys->sprite[1].height - 10);
	else if (sprite == 2)
		print_image(sys, &sys->sprite[1], WIDTH - sys->sprite[1].height, HEIGHT
			- sys->sprite[2].height - 20);
	else if (sprite == 3)
		print_image(sys, &sys->sprite[2], WIDTH - sys->sprite[2].height, HEIGHT
			- sys->sprite[3].height - 30);
	else if (sprite == 4)
		print_image(sys, &sys->sprite[2], WIDTH - sys->sprite[2].height, HEIGHT
			- sys->sprite[4].height - 35);
	else if (sprite == 5)
		print_image(sys, &sys->sprite[3], WIDTH - sys->sprite[3].height, HEIGHT
			- sys->sprite[5].height - 40);
	else if (sprite == 6)
		print_image(sys, &sys->sprite[4], WIDTH - sys->sprite[4].height, HEIGHT
			- sys->sprite[6].height - 43);
	else
		sprite_animation_1(sys, sprite);
}

static void	sprite_animation_1(t_system *sys, int sprite)
{
	if (sprite == 7)
		print_image(sys, &sys->sprite[5], WIDTH - sys->sprite[5].height, HEIGHT
			- sys->sprite[7].height - 45);
	else if (sprite == 8)
		print_image(sys, &sys->sprite[6], WIDTH - sys->sprite[5].height, HEIGHT
			- sys->sprite[7].height - 45);
	else if (sprite == 9)
		print_image(sys, &sys->sprite[6], WIDTH - sys->sprite[5].height, HEIGHT
			- sys->sprite[7].height - 60);
	else if (sprite == 10)
		print_image(sys, &sys->sprite[6], WIDTH - sys->sprite[5].height, HEIGHT
			- sys->sprite[7].height - 40);
	else if (sprite == 11)
		print_image(sys, &sys->sprite[7], WIDTH - sys->sprite[5].height, HEIGHT
			- sys->sprite[7].height - 35);
	else if (sprite == 12)
		print_image(sys, &sys->sprite[7], WIDTH - sys->sprite[5].height, HEIGHT
			- sys->sprite[7].height - 30);
	else if (sprite == 13)
		print_image(sys, &sys->sprite[8], WIDTH - sys->sprite[5].height, HEIGHT
			- sys->sprite[7].height - 25);
	else
		sprite_animation_2(sys, sprite);
}

static void	sprite_animation_2(t_system *sys, int sprite)
{
	if (sprite == 14)
		print_image(sys, &sys->sprite[8], WIDTH - sys->sprite[5].height, HEIGHT
			- sys->sprite[7].height - 20);
	else if (sprite == 15)
		print_image(sys, &sys->sprite[8], WIDTH - sys->sprite[5].height, HEIGHT
			- sys->sprite[7].height - 20);
	else if (sprite == 16)
		print_image(sys, &sys->sprite[8], WIDTH - sys->sprite[5].height, HEIGHT
			- sys->sprite[7].height - 20);
}
