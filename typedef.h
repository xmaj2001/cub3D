/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:09:18 by xjose             #+#    #+#             */
/*   Updated: 2025/03/08 10:14:56 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

enum						e_states_system
{
	STOP = 0,
	PLAY = 1
};

enum						e_coord
{
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3,
	TEXTURE = 4,
	DOOR = 5
};

typedef struct s_keys
{
	int						up;
	int						down;
	int						left;
	int						right;
	int						left_rot;
	int						right_rot;
}							t_keys;

enum						e_colors
{
	MAGENTA = 0xFF00FF,
	YELLOW = 0xFFFF00,
	RED = 0xFF0000,
	GREEN = 0x00FF00,
	BLUE = 0x0000FF,
	WHITE = 0xFFFFFF,
	BLACK = 0x000000,
	AQUA = 0x00FFFF,
	CYAN = 0x00FFFF
};

typedef struct s_point
{
	int						x;
	int						y;
}							t_point;

typedef struct s_vector
{
	float					x;
	float					y;
}							t_vector;

typedef struct s_texture
{
	void					*img;
	int						*addr;
	int						bpp;
	int						size_line;
	int						endian;
	int						width;
	int						height;

}							t_texture;

typedef struct s_map
{
	int						size;
	int						color;
	char					looking_dir;
	int						floor_color;
	int						ceiling_color;
	char					*path_textures[4];
	t_texture				textures[5];
	char					**matrix_map;
	t_point					pos;
}							t_map;

typedef struct s_player
{
	int						size;
	char					door;
	float					move_speed;
	enum e_coord			coord;
	t_point					pos_door;
	t_vector				pos;
	t_vector				dir;
	t_keys					keys;
	t_vector				camera_plane;
}							t_player;

typedef struct s_dup_dir
{
	int						no;
	int						we;
	int						so;
	int						ea;
	int						w_counter;
	int						s_counter;
	int						n_counter;
	int						e_counter;
	int						f_counter;
	int						c_counter;
}							t_dup_dir;

typedef struct s_start_pos
{
	int						x;
	int						y;

	char					looking_dir;
	char					*floor;
	char					*ceiling;
	char					*west_texture;
	char					*north_texture;
	char					*south_texture;
	char					*east_texture;
}							t_pos;

typedef struct s_image
{
	void					*img;
	char					*addr;
	int						bpp;
	int						size_line;
	int						endian;
	int						width;
	int						height;

}							t_image;

typedef struct s_wall
{
	int						height;
	int						line_start_y;
	int						line_end_y;
	int						texture_x;
	int						texture;
	int						texture_y;
	float					point_x;
	float					texture_step;
	float					texture_pos;
}							t_wall;

enum						e_direction_ray
{
	HORIZONTAL = 0,
	VERTICAL = 1
};

typedef struct s_ray
{
	t_vector				dir;
	t_vector				new_camera;
	t_vector				delta_dist;
	t_vector				dist;
	t_point					map;
	int						texture;
	enum e_direction_ray	side;
	float					mult;
	float					prd_dist;
	t_vector				step;
}							t_ray;

typedef struct s_ui
{
	t_texture				win;
}							t_ui;

typedef struct s_system
{
	void					*mlx;
	void					*win;
	char					**matrix;
	char					**matrix_cd;
	char					**map_matrix;
	int						i;
	t_ui					ui;
	t_image					bg;
	t_map					map;
	t_dup_dir				*dup_dir;
	t_pos					*pos;
	t_player				player;
	t_texture				door_texture[3];
	t_texture				sprite[9];
	enum e_states_system	state;
}							t_system;
#endif