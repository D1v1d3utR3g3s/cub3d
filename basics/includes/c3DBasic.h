/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3DBasic.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:35:18 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/17 14:30:21 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3DBASIC_H
# define C3DBASIC_H

// INCLUDES
# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line_bonus.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
// /!\ As it is meant for training I used strlen and not the one of libft

// STRUCT
typedef struct s_ray
{
	float	rx;
	float	ry;
	float	dx;
	float	dy;
	float	ra;
	float	dh;
	float	hx;
	float	hy;
	float	dv;
	float	vx;
	float	vy;
	float	dist_wall;
	int		col_wall;
}	t_ray;

typedef struct s_player
{
	float	px;
	float	py;
	float	dx;
	float	dy;
	float	pa;
}	t_player;

typedef struct s_grid
{
	int	nb_tile_x;
	int	nb_tile_y;
	int	w_tile;
	int	*map;
}	t_grid;

typedef struct s_mlx_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx_img;

typedef struct s_pix
{
	int	x;
	int	y;
	int	col;
}	t_pix;

typedef struct s_c3d_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			h;
	int			w;
	char		*title;
	t_mlx_img	img_ptr;
	t_player	player;
	t_grid		grid;
	t_ray		ray;
	int			size_map;
	char		*error_msg;
}	t_c3d_data;

enum e_values
{
	NO_FILE_INDEX,
	NO_FILE_LEN,
	SO_FILE_INDEX,
	SO_FILE_LEN,
	WE_FILE_INDEX,
	WE_FILE_LEN,
	EA_FILE_INDEX,
	EA_FILE_LEN,
	F_COLOR_INDEX,
	F_COLOR_LEN,
	C_COLOR_INDEX,
	C_COLOR_LEN,
	MAP_INDEX,
	MAP_LINES_NB,
	MAP_COLUMNS_NB,
};

// FUNCTIONS
// clean.c
void	clear_data(t_c3d_data *c3d);

// display_2D.c
int		is_near_player(t_pix pix, t_player player);
void	wall_col(t_pix *pix, t_grid *grid, int black, int white);

// display_line.c
void	draw_point_line(t_c3d_data *c3d, int beginX, int beginY, int endX,
			int endY, int col);
void	draw_full_line(t_c3d_data *c3d, int beginX, int beginY, int endX,
			int endY, int col);

// display.c
void	img_pix_put(t_mlx_img *img, int x, int y, int col);
int		encode_rgb(u_int8_t red, u_int8_t green, u_int8_t blue);
void	draw_rays(t_c3d_data *c3d);
void	draw_player(t_c3d_data *c3d);
void	full_img(t_c3d_data *c3d);
float	update_angle(float a, float da);

// hook_event_utils.c
void	keys_wasd(int keysym, t_c3d_data *c3d);
int		is_key_wasd(int keysym);
void	keys_array(int keysym, t_c3d_data *c3d);
int		is_key_array(int keysym);

// hook_event.c
void	hook_event(t_c3d_data *c3d);

// init_2.c
int		init_ray(t_c3d_data *c3d, float angle);
int		init_player(t_player *player);

// init.c
int		init_grid(t_c3d_data *c3d);
int		init_image(t_c3d_data *c3d);
int		init_window(t_c3d_data *c3d);
int		init_c3d_data(t_c3d_data *c3d, const char *file_path);

// ray_trace.c
void	draw_ray(t_c3d_data *c3d);

// display_3D.c
void	draw3D(t_c3d_data *c3d, int r);

// utils.c
float	calc_d(float ax, float ay, float bx, float by, float ang);
int		face_down(float rad);
int		face_right(float rad);
float	rad_to_deg(float rad);
float	deg_to_rad(float deg);

void	draw_ray_backup(t_c3d_data *c3d);

// parse_scene.c
int		parse(t_c3d_data *c3d, ssize_t *elements, char **raw_data,
			ssize_t len);

// load_scene.c
int		load_scene(t_c3d_data *c3d, const char *file_path);

// checks_raw_data_2.c
void	find_elements_indexes(ssize_t *elements, char *raw_data, ssize_t len);

// checks_raw_data.c
int		is_a_space(const char c);
void	remove_ending_spaces_of_last_line_into_str(char **str, ssize_t *len,
			ssize_t from, int remove_last_nl);
int		first_checks(char **error_msg, ssize_t *elements, char *raw_data,
			ssize_t *len);

// checks_args.c
int		parse_c3d_args(char **file_path, const int argc, const char **argv);

// debug_checks_raw_data.c
void	debug_elements(ssize_t *elements, char *raw_data, ssize_t len);

#endif
