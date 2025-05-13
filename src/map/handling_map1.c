/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_map1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 06:07:20 by mefernan          #+#    #+#             */
/*   Updated: 2025/03/08 10:42:49 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	ft_free_resources(t_system *game, int flag)
{
	if (game->matrix)
		ft_free_matrix(game->matrix);
	if (game->matrix_cd)
		ft_free_matrix(game->matrix_cd);
	if (game->map_matrix)
		ft_free_matrix(game->map_matrix);
	ft_free_mlx_ptr(game);
	if (flag == 1)
		ft_error("Duplicated, missing, or more than one direction in the map");
	if (flag == 0)
		ft_error("Issue in the 6 first elements of the file");
}

void	ft_check_duplicated_dir_in_map(t_system *game)
{
	if (game->dup_dir->n_counter == 1 && (game->dup_dir->e_counter >= 1
			|| game->dup_dir->w_counter >= 1 || game->dup_dir->s_counter >= 1))
		ft_free_resources(game, 1);
	if (game->dup_dir->w_counter == 1 && (game->dup_dir->e_counter >= 1
			|| game->dup_dir->n_counter >= 1 || game->dup_dir->s_counter >= 1))
		ft_free_resources(game, 1);
	if (game->dup_dir->e_counter == 1 && (game->dup_dir->n_counter >= 1
			|| game->dup_dir->w_counter >= 1 || game->dup_dir->s_counter >= 1))
		ft_free_resources(game, 1);
	if (game->dup_dir->s_counter == 1 && (game->dup_dir->e_counter >= 1
			|| game->dup_dir->w_counter >= 1 || game->dup_dir->n_counter >= 1))
		ft_free_resources(game, 1);
	if (game->dup_dir->n_counter > 1 || game->dup_dir->w_counter > 1
		|| game->dup_dir->e_counter > 1 || game->dup_dir->s_counter > 1)
		ft_free_resources(game, 1);
	if (game->dup_dir->n_counter == 0 && game->dup_dir->w_counter == 0
		&& game->dup_dir->e_counter == 0 && game->dup_dir->s_counter == 0)
		ft_free_resources(game, 1);
}

void	ft_count_element_in_map(t_system *game)
{
	int	j;
	int	i;

	i = 0;
	while (game->map_matrix[i])
	{
		j = 0;
		while (game->map_matrix[i][j])
		{
			if (game->map_matrix[i][j] == 'W')
				game->dup_dir->w_counter++;
			else if (game->map_matrix[i][j] == 'S')
				game->dup_dir->s_counter++;
			else if (game->map_matrix[i][j] == 'N')
				game->dup_dir->n_counter++;
			else if (game->map_matrix[i][j] == 'E')
				game->dup_dir->e_counter++;
			j++;
		}
		i++;
	}
}

void	ft_if_duplicated_dir_or_color(t_system *game)
{
	if (game->dup_dir->no != 1 || game->dup_dir->so != 1
		|| game->dup_dir->we != 1
		|| game->dup_dir->ea != 1 || game->dup_dir->f_counter != 1
		|| game->dup_dir->c_counter != 1)
	{
		ft_free_matrix(game->matrix);
		ft_free_matrix(game->matrix_cd);
		ft_free_mlx_ptr(game);
		ft_error("Duplicated or missing direction or color component");
	}
}

void	ft_more_function_calls(t_system *game)
{
	ft_fill_color_dir_mat(game);
	ft_some_checks(game);
	ft_if_duplicated_dir_or_color(game);
	ft_fill_map_matrix(game);
	ft_count_element_in_map(game);
	ft_check_duplicated_dir_in_map(game);
	ft_check_slash_n(game);
	ft_get_rid_of_slash_n(game);
	ft_check_invalid_char(game);
	ft_check_ones(game);
	ft_get_game_ready(game);
}
