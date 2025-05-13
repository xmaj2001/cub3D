/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:18:24 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 08:39:28 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"
#include "../../minilibx-linux/mlx_int.h"

static int	keypress(int key, void *data);
static int	keyrelease(int key, void *data);

void	player_keypress(t_system *sys)
{
	mlx_hook(sys->win, KeyPress, KeyPressMask, keypress, sys);
	mlx_hook(sys->win, KeyRelease, KeyReleaseMask, keyrelease, sys);
}

static int	keypress(int key, void *data)
{
	t_system	*game;

	game = (t_system *)data;
	if (key == XK_w)
		game->player.keys.up = 1;
	if (key == XK_s)
		game->player.keys.down = 1;
	if (key == XK_a)
		game->player.keys.left = 1;
	if (key == XK_d)
		game->player.keys.right = 1;
	if (key == XK_Right)
		game->player.keys.left_rot = 1;
	if (key == XK_Left)
		game->player.keys.right_rot = 1;
	if (key == XK_e)
		open_door(game);
	if (key == 65307)
		exit_game(game);
	return (0);
}

static int	keyrelease(int key, void *data)
{
	t_system	*game;

	game = (t_system *)data;
	if (key == XK_w)
		game->player.keys.up = 0;
	if (key == XK_s)
		game->player.keys.down = 0;
	if (key == XK_a)
		game->player.keys.left = 0;
	if (key == XK_d)
		game->player.keys.right = 0;
	if (key == XK_Right)
		game->player.keys.left_rot = 0;
	if (key == XK_Left)
		game->player.keys.right_rot = 0;
	return (0);
}
