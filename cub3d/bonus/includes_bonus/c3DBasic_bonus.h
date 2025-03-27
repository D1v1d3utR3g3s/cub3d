/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3DBasic_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:35:18 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/23 22:29:35 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3DBASIC_BONUS_H
# define C3DBASIC_BONUS_H

// INCLUDES
# include "../../libft/includes/libft.h"
# include "../../libft/includes/get_next_line_bonus.h"
# include "c3DMap_bonus.h"

# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include <time.h>
# include <sys/time.h>

# define BONUS 1
# define BONUS_DOOR 1
# define BONUS_MOUSE 0
# define BONUS_MOUSE_CLICK 1
# define BONUS_MINIMAP 1
# define BONUS_ANIM 1
# define DISPLAY_DEBUG 0

# define NO_COL -16777216
# define ROT_SPEED 0.08
# define MOV_SPEED 3.4

// ENUM
enum	e_cardinal
{
	NORTH,
	EAST,
	SOUTH,
	WEST
};

typedef enum e_unity_time
{
	SECONDS,
	MILLISECONDS,
	MICROSECONDS,
}	t_unity_time;

// STRUCT
typedef struct s_ray
{
	float	rx;
	float	ry;
	float	dx;
	float	dy;
	float	ra;
	int		hit_h;
	int		hit_h_door;
	float	dh;
	float	hx;
	float	hy;
	int		hit_v;
	int		hit_v_door;
	float	dv;
	float	vx;
	float	vy;
	int		wall_dir;
	float	dist_wall;
	int		col_wall;
}	t_ray;

typedef struct s_doors
{
	int	size;
	int	*dist;
}	t_doors;

typedef struct s_mouse
{
	int	mx;
	int	my;
	int	flag_press;
}	t_mouse;

typedef struct s_player
{
	float	px;
	float	py;
	float	pa;
	float	dx;
	float	dy;
	float	da;
	int		fov;
	float	mov_speed;
	float	rot_speed;
}	t_player;

typedef struct s_anim
{
	char		*path;
	char		*ext;
	long		t0;
	long		t;
	int			dt;
	int			anim_id;
	int			nb_anim;
	t_mlx_img	*sprite;
	int			*anim_dir;
	int			wall_id;
	int			dir;
	int			rand_id;
	int			dist_anim;
	int			score;
}	t_anim;

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
	t_doors		doors;
	t_minimap	min_map;
	t_anim		anim;
	t_mouse		mouse;
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
// bonus_anim_utils.c
int			allow_for_anim(t_c3d_data *c3d, int x, int y);
int			determine_dir_anim(t_c3d_data *c3d, int dir_allow);
void		get_current_anim_id(t_c3d_data *c3d);
int			get_anim_color(t_c3d_data *c3d, int y, int dx, int line_h);

// bonus_anim_hook.c
void		take_anim_elt(t_c3d_data *c3d);
void		display_infos(t_c3d_data *c3d);

// bonus_anim.c
void		init_id(t_c3d_data *c3d);
void		sub_init_anim(t_c3d_data *c3d);
void		init_anim(t_c3d_data *c3d);

// bonus_doors.c
void		init_doors_val(t_c3d_data *c3d);
void		init_doors(t_c3d_data *c3d);
void		update_doors(t_c3d_data *c3d, int mp, int d);
void		action_on_door(t_c3d_data *c3d);

// bonus_minimap_utils.c
int			check_in_minimap(t_c3d_data *c3d, int x, int y);
int			is_outside_map(t_c3d_data *c3d, int x, int y);
int			is_on_border_minmap(t_c3d_data *c3d, int mmx, int mmy);
int			is_fov_lim(t_c3d_data *c3d, int mmx, int mmy);
int			is_player(t_c3d_data *c3d, int mmx, int mmy);

// bonus_minimap.c
void		update_minimap_col(t_c3d_data *c3d);
void		init_minimap(t_c3d_data *c3d);

// bonus_mouse.c
int			mouse_mov(int mx, int my, t_c3d_data *c3d);
void		rot_dir_mouse(t_c3d_data *c3d);
int			click(int button, int mx, int my, t_c3d_data *c3d);
int			unclick(int button, int mx, int my, t_c3d_data *c3d);

// bonus_wall_collision.c
int			mov_allow_wall(t_c3d_data *c3d, float dx, float dy);

// clean.c
void		clear_data(t_c3d_data *c3d);

// colors.c
int			encode_rgb(u_int8_t red, u_int8_t green, u_int8_t blue);
int			determine_col(int x, int y, t_c3d_data *c3d);
int			get_color(t_c3d_data *c3d, int init_y, int offset_x, int line_h);

// display_img_mlx.c
void		img_pix_put(t_mlx_img *img, int x, int y, int col);

// display.c
void		full_img(t_c3d_data *c3d);
void		display_3d(t_c3d_data *c3d);
void		loop_game(t_c3d_data *c3d);

// error.c
void		display_error(const char *error_msg);
void		err_clear_exit(char *str, t_c3d_data *c3d);

// hook_event_close.c
int			close_handler(t_c3d_data *c3d);

// hook_event_mov.c
void		move_dir(t_c3d_data *c3d, char dir);

// hook_event_rot.c
void		rot_dir(t_c3d_data *c3d, char dir);

// hook_event_utils.c
int			check_event(t_c3d_data *c3d);
int			calc_dx(t_c3d_data *c3d, float dir_a);
int			calc_dy(t_c3d_data *c3d, float dir_a);
int			calc_margin(float d);
void		apply_event(t_c3d_data *c3d);

// hook_event.c
void		hook_event(t_c3d_data *c3d);

// init_colors_data.c
void		init_col_array(int **col, int size);
int			init_col(t_c3d_data *c3d);

// init_game.c
void		init_game(t_c3d_data *c3d);

// init_mlx.c
int			init_mlx_data(t_mlx *mlx);

// init.c
void		init_maze(t_maze *maze);
void		init_player(t_player *player);
void		init_ray(t_c3d_data *c3d, float angle);
void		init_event(t_event *event);
int			init_c3d_data(t_c3d_data *c3d, const char *file_path);

// raycast_intersect_utils.c
int			check_hit_wall(int mp, t_c3d_data *c3d, int dir);
int			calc_mp(t_ray *ray, t_c3d_data *c3d);
float		compensate_fishbowl_distortion(float d, float angle);

// raycast_intersect.c
void		hor_intersect(t_c3d_data *c3d);
void		ver_intersect(t_c3d_data *c3d);

// raycasting.c
void		raycast(t_c3d_data *c3d);

// textures_utils.c
int			get_texture_color(t_c3d_data *c3d, int y, int dx, int line_h);
void		extract_slice_tex(t_mlx *mlx, t_c3d_data *c3d, int x, int line_h);

// textures.c
t_mlx_img	load_xpm_textures(t_c3d_data *c3d, t_mlx *mlx, char *path);
void		init_textures(t_c3d_data *c3d);

// time_fct.c
long		gettime_in(t_unity_time unity, t_c3d_data *c3d);

// update.c
void		update_maze(t_maze *maze, char *str, int nb_col, int nb_line);
void		update_player(t_c3d_data *c3d, int x, int y, float a);
float		update_angle(float a, float da);

// utils_math.c
int			rand_int(int min, int max, t_c3d_data *c3d);
float		calc_d(float ax, float ay, float bx, float by);
float		calc_coef(t_c3d_data *c3d, t_minimap *mmp);
float		rad_to_deg(float rad);
float		deg_to_rad(float deg);

// utils.c
int			check_in_window(t_c3d_data *c3d, int x, int y);
int			face_down(float rad);
int			face_right(float rad);

// writing_testing_purpose
void		display_anim_pos(t_c3d_data *c3d);
void		display_map(t_c3d_data c3d);
void		display_player_pos(t_c3d_data c3d);
void		display_map_and_player(t_c3d_data c3d);

// map_closure_checks.c
int			closure_checks(char **error_msg, t_maze maze);

// parse_scene_2.c
int			parse_map(t_c3d_data *c3d, ssize_t *elements, char **raw_data,
				ssize_t len);

// parse_scene_3.c
int			check_commas_into_format(t_c3d_data *c3d, ssize_t start,
				ssize_t end, const char *raw_data);

// parse_scene.c
int			parse(t_c3d_data *c3d, ssize_t *elements, char **raw_data,
				ssize_t len);

// load_scene.c
int			load_scene(t_c3d_data *c3d, const char *file_path);

// checks_raw_data_2.c
void		find_elements_indexes(ssize_t *elements, char *raw_data,
				ssize_t len);

// checks_raw_data_3.c
int			remove_ending_spaces_of_each_line_into_map(char **str, ssize_t *len,
				ssize_t from);

// checks_raw_data.c
int			is_a_space(const char c);
void		remove_ending_spaces_of_last_line_into_str(char **str, ssize_t *len,
				ssize_t from, int remove_last_nl);
int			first_checks(char **error_msg, ssize_t *elements, char *raw_data,
				ssize_t *len);

// checks_args.c
int			parse_c3d_args(char **file_path, const int argc, const char **argv);

// debug_checks_raw_data.c
void		debug_elements(ssize_t *elements, char *raw_data, ssize_t len);
void		debug_c3d_data(t_c3d_data *c3d);

#endif
