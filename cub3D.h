/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:52:40 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 10:17:05 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include "typedef.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BLOCK 64
# define WIDTH 1000
# define HEIGHT 789

# define PI 3.14159265359
/* SYSTEM */
void		init_system(int argc, char **argv, t_system *sys);
int			frame(t_system *sys);
void		run_system(t_system *sys);
int			exit_game(t_system *sys);
void		close_window(t_system *sys);
/* PLAYER */
void		init_player(t_system *sys, t_point pos, enum e_coord coord);
void		player_move(t_system *sys);
void		player_rotation(t_system *sys);
void		player_keypress(t_system *sys);
void		open_door(t_system *sys);
/* Draw */
int			get_color_texture(t_texture tex, int y, int x);
void		init_background(t_system *sys);
void		draw_background(t_system *sys, int color_sky, int color_plane);
void		draw_square(t_system *sys, t_point p, int size, int color);
void		draw_minimap(t_system *sys);
void		put_pixel(t_system *sys, int x, int y, int color);
void		update_background(t_system *sys);
void		print_image(t_system *sys, t_texture *img, int x, int y);
void		draw_wall(t_ray *ray, t_system *sys, int pixel);
//> texture
int			error_textures(t_system *sys);
int			add_textures(t_system *sys);
void		init_textures(t_system *sys);
void		free_textures(t_system *sys);
t_texture	load_texture(t_system *sys, char *path);
/* SPRITE */
void		sprite(t_system *sys);
/* UI */
void		draw_ui_main(t_system *sys);

/* RAYCAST */
int			get_direction_ray(float dir);
void		raycast(t_system *sys);
/* VECTOR */
t_vector	new_vector(float x, float y);
t_vector	sum_vector(t_vector vector1, t_vector vector2);
t_vector	mult_vector(t_vector vector, double mult);
t_vector	rotate_vector(t_vector vector, float angle);

/*Utils*/
void		free_matrix(char **mt);
int			get_rgb(char *colors);

/* MAP */
void		init_map(t_system *sys, int argc, char **argv);

/* MAP VALIDATION */
int			ft_only_spaces(char *str);
int			ft_space(char c);
int			string_comp(char *s1, char *s2);
int			ft_condition(char *line, int flag, int i);
int			ft_count_lines_in_matrix(char **matrix);
int			ft_check_texture_extention(char *texture);
int			ft_key_press(int key_pressed, void *args);
int			ft_closing_with_esc(t_system *game);

void		ft_error(char *error);
void		ft_handling_aux(t_system *game, int y, char *map);
void		ft_get_game_ready(t_system *game);
void		ft_check_slash_n(t_system *game);
void		ft_check_ones(t_system *game);
void		ft_print_error(t_system *game, int flag);
void		ft_get_rid_of_slash_n(t_system *game);
void		ft_conditions_for_zeros(t_system *game, int i, int j, int len1);
void		ft_free_resources(t_system *game, int flag);
void		ft_count_element_in_map(t_system *game);
void		ft_fill_color_dir_mat(t_system *game);
void		ft_more_function_calls(t_system *game);
void		ft_some_checks(t_system *game);
void		ft_if_duplicated_dir_or_color(t_system *game);
void		ft_fill_map_matrix(t_system *game);
void		ft_check_invalid_char(t_system *game);
void		ft_free_mlx_ptr(t_system *game);
void		ft_free_matrix(char **matrix);
void		ft_validate_colors(char *line, t_system *game);
void		ft_check_directions(char *line, char **matrix, t_system *game);
void		ft_handling_map(t_system *game, char *map);

char		*get_next_line(int fd);
char		*ft_spaces_in_color_line(char *line);
#endif
