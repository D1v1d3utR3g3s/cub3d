
#ifndef MLXBASIC_H
# define MLXBASIC_H

// INCLUDES
# include "../minilibx-linux/mlx.h"
//# include "../libft/libft.h"
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

typedef struct s_mlx_data
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
    int         size_map;
}	t_mlx_data;

// FUNCTIONS
// clean.c
void	clear_data(t_mlx_data *mlx);

// display_2D.c
int	is_near_player(t_pix pix, t_player player);
void	wall_col(t_pix *pix, t_grid *grid, int black, int white);

// display_line.c
void	draw_point_line(t_mlx_data *mlx, int beginX, int beginY, int endX, int endY, int col);
void	draw_full_line(t_mlx_data *mlx, int beginX, int beginY, int endX, int endY, int col);

// display.c
void	img_pix_put(t_mlx_img *img, int x, int y, int col);
int	encode_rgb(u_int8_t red, u_int8_t green, u_int8_t blue);
void	draw_rays(t_mlx_data *mlx);
void	draw_player(t_mlx_data *mlx);
void	full_img(t_mlx_data *mlx);

// hook_event_utils.c
void	keys_wasd(int keysym, t_mlx_data *mlx);
int	is_key_wasd(int	keysym);
void	keys_array(int keysym, t_mlx_data *mlx);
int	is_key_array(int keysym);

// hook_event.c
void	hook_event(t_mlx_data *mlx);

// init.c
int	init_ray(t_mlx_data *mlx, float angle);
int	init_player(t_player *player);
int	init_grid(t_mlx_data *mlx);
int	init_image(t_mlx_data *mlx);
int	init_window(t_mlx_data *mlx);
int	init_mlx_data(t_mlx_data *mlx);

// ray_trace.c
void	draw_ray(t_mlx_data *mlx);

// utils.c
float	calc_d(float ax, float ay, float bx, float by, float ang);
int	face_down(float rad);
int	face_right(float rad);
float   rad_to_deg(float rad);
float   deg_to_rad(float deg);

void	draw_ray_backup(t_mlx_data *mlx);

#endif