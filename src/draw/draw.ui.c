/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:23:30 by xjose             #+#    #+#             */
/*   Updated: 2025/03/07 09:48:42 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	mouse_hook(int button, int x, int y, t_system *sys)
{
	if (button == 1 && x >= (WIDTH / 2) - 60 && x <= (WIDTH / 2) + 60
		&& y >= (HEIGHT / 2) - 18 && y <= (HEIGHT / 2) + 50)
	{
		sys->state = PLAY;
		update_background(sys);
	}
}

void	draw_ui_main(t_system *sys)
{
	sys->ui.win = load_texture(sys, "textures/ui_start3.xpm");
	print_image(sys, &sys->ui.win, 0, 0);
	update_background(sys);
	mlx_mouse_hook(sys->win, mouse_hook, sys);
}
