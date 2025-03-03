/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3DBasic.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:35:18 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/03 21:21:44 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3DBASIC_H
# define C3DBASIC_H

// INCLUDES
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line_bonus.h"
# include "c3DMap.h"
//# include "c3DMlx.h"

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <string.h>

// ENUM
enum	e_cardinal
{
	NORTH,
	EAST,
	SOUTH,
	WEST
};

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
	int		wall_dir;
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
	int		size;
	float	mov_speed;
	float	rot_speed;
}	t_player;

typedef struct s_c3d_data
{
	t_mlx		mlx;
	t_texture	textures;
	t_maze		maze;
	t_map_col	m_col;
	t_player	player;
	t_ray		ray;
	t_event		event;
	int			size_map;
	char		*error_msg;
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
	PLAYERS_NB,
	PLAYER_INDEX,
};

// FUNCTIONS
// clean.c
void	clear_data(t_c3d_data *c3d);

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

// raycast_intersect_utils.c
int		check_hit_wall(int mp, t_c3d_data *c3d);
int		calc_mp(t_ray *ray, t_c3d_data *c3d);

// raycast_intersect.c
void	hor_intersect(t_c3d_data *c3d);
void	ver_intersect(t_c3d_data *c3d);

// raycasting.c
void	raycast(t_c3d_data *c3d);

// textures.c
void	init_textures(t_c3d_data *c3d);

// textures_utils.c
void	extract_slice_texture(t_mlx *mlx, t_c3d_data *c3d, int x, int line_h);

// utils.c
float	calc_d(float ax, float ay, float bx, float by);
int		face_down(float rad);
int		face_right(float rad);
float	rad_to_deg(float rad);
float	deg_to_rad(float deg);

// update.c
void	update_maze(t_maze *maze, char *str, int nb_col, int nb_line);
void	update_player(t_c3d_data *c3d, int x, int y, float a);
float	update_angle(float a, float da);

// parse_scene_2.c
int		parse_map(t_c3d_data *c3d, ssize_t *elements, char **raw_data,
			ssize_t len);

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
void	debug_c3d_data(t_c3d_data *c3d);

#endif
