/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3DBasic.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:35:18 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/17 02:30:36 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3DBASIC_H
# define C3DBASIC_H

// INCLUDES
//# include "../minilibx-linux/mlx.h"
//# include <X11/keysym.h>
//# include <X11/X.h>
# include "../libft/includes/libft.h"
# include "c3DMap.h"
# include "c3DMlx.h"

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <string.h>

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
	float	pa;
	float	dx;
	float	dy;
	float	da;
	int		fov;
	// in progress...
	int		size;
	float	mov_speed;
	float	rot_speed;
}	t_player;

/*
typedef struct s_grid
{
	int	nb_tile_x;
	int	nb_tile_y;
	int	w_tile;
	int	*map;
}	t_grid;*/
/*
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
*/

typedef struct s_c3d_data
{
    t_mlx		mlx;
    t_maze		maze;
	t_map_col	m_col;
	t_player	player;
	t_ray		ray;
	t_event		event;
	int			size_map;
	char		*error_msg;
	// in progress
	int			wall_size;
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

/*
// display_2D.c
int		is_near_player(t_pix pix, t_player player);
void	wall_col(t_pix *pix, t_grid *grid, int black, int white);

// display_3D.c
void	draw3D(t_c3d_data *c3d, int r);

// display_line.c
void	draw_point_line(t_c3d_data *c3d, int beginX, int beginY, int endX,
			int endY, int col);
void	draw_full_line(t_c3d_data *c3d, int beginX, int beginY, int endX,
			int endY, int col);
*/

// colors.c
int		determine_col(int x, int y, t_c3d_data *c3d);
int		encode_rgb(u_int8_t red, u_int8_t green, u_int8_t blue);

// display_img_mlx.c
void	img_pix_put(t_mlx_img *img, int x, int y, int col);

// display.c
void	full_img(t_c3d_data *c3d);
void	loop_game(t_c3d_data *c3d);

// error.c
void	display_error(const char *error_msg);
void	err_clear_exit(char *str, t_c3d_data *c3d);

// hook_event_close.c
int		close_handler(t_c3d_data *c3d);

// hook_event_mov.c
void	move_dir(t_c3d_data *c3d, char dir);

// hook_event_rot.c
void	rot_dir(t_c3d_data *c3d, char dir);

// hook_event_utils.c
int		check_event(t_c3d_data *c3d);
int		calc_dx(t_c3d_data *c3d, float dir_a);
int		calc_dy(t_c3d_data *c3d, float dir_a);
int		calc_margin(float d);
void	apply_event(t_c3d_data *c3d);

// hook_event.c
void	hook_event(t_c3d_data *c3d);

/*
// init_2.c
int		init_ray(t_c3d_data *c3d, float angle);
int		init_player(t_player *player);
*/

// init_colors_data.c
void	init_col_array(int **col, int size);
int		init_col(t_c3d_data *c3d);

// init_mlx.c
int		init_mlx_data(t_mlx *mlx);

// init.c
void	init_maze(t_maze *maze);
void	init_player(t_player *player);
void	init_ray(t_c3d_data *c3d, float angle);
void	init_event(t_event *event);
int		init_c3d_data(t_c3d_data *c3d, const char *file_path);

// raycast_3d_utils.c
void	update_line_col(int ray_nb, float offset, float line_h, t_c3d_data *c3d);
void	update_3d_line_col(int beginX, int beginY, int endX, int endY, t_c3d_data *c3d);

// raycast_intersect_utils.c
int		check_hit_wall(int mp, t_c3d_data *c3d);
int		calc_mp(t_ray *ray, t_c3d_data *c3d);

// raycast_intersect.c
void	hor_intersect(t_c3d_data *c3d);
void	ver_intersect(t_c3d_data *c3d);

// raycasting.c
void	raycast(t_c3d_data *c3d);

// utils.c
float	calc_d(float ax, float ay, float bx, float by);
int		face_down(float rad);
int		face_right(float rad);
float	rad_to_deg(float rad);
float	deg_to_rad(float deg);

// update.c
void	update_maze(t_maze *maze, char *str, int nb_col, int nb_line);
void	update_player(t_player *player, float x, float y, float a);
float	update_angle(float a, float da);

//void	draw_ray_backup(t_c3d_data *c3d);

// load_scene_2.c

// load_scene.c
int		load_scene(t_c3d_data *c3d, const char *file_path);

// checks_raw_data_2.c
void	find_elements_indexes(ssize_t *elements, char *raw_data, ssize_t len);

// checks_raw_data.c
int		is_a_space(const char c);
void	remove_ending_spaces_of_last_line_into_str(char **str, ssize_t *len,
			ssize_t from, int remove_last_nl);
int		first_checks(char *raw_data, int nb_lines, char **error_msg);

// checks_args.c
int		parse_c3d_args(char **file_path, const int argc, const char **argv);

// debug_checks_raw_data.c
void	debug_elements(ssize_t *elements, char *raw_data, ssize_t len);

#endif
