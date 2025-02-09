#include "../includes/mlxBasic.h"

/* ************************************************************************** */
/*                                img_pix_put                                 */
/* -------------------------------------------------------------------------- */
/* This function clear the different part generated with mlx (this contained  */
/*  the mlx pointer, the window as well as the image )                        */
/* Input :                                                                    */
/*  - t_mlx_img *img : a pointer to a structure used for mlx images           */
/*  - int x : the x coordinate of the pixel                                   */
/*  - int y : the y coordinate of the pixel                                   */
/*  - int col : the color that we desire for the pixel                        */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	img_pix_put(t_mlx_img *img, int x, int y, int col)
{
	int		offset;
	char	*pix_dest;

	offset = (y * img->line_len + x * (img->bpp / 8));
	pix_dest = img->addr + offset;
	*(unsigned int *)pix_dest = col;
}

/* ************************************************************************** */
/*                                 encode_rgb                                 */
/* -------------------------------------------------------------------------- */
/* This function converts a RGB value into an integer                         */
/* Input :                                                                    */
/*  - u_int8_t red : the Red value of the color wanted                        */
/*  - u_int8_t green : the Green value of the color wanted                    */
/*  - u_int8_t blue : the Blue value of the color wanted                      */
/* Return :                                                                   */
/*  - int the integer that correspond to the color defined with RGB           */
/* ************************************************************************** */
int	encode_rgb(u_int8_t red, u_int8_t green, u_int8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

float	update_angle(float a, float da)
{
	float	new_a;

	new_a = a + da;
	if (new_a > 2 * M_PI)
		new_a -= 2 * M_PI;
	else if (new_a < 0)
		new_a += 2* M_PI;
	return (new_a);
}

/* ************************************************************************** */
/* ************************************************************************** */
void	draw_rays(t_mlx_data *mlx)
{
	int i;
	int	fov;
	float	a;

	i = 0;
	fov = 60;
//	mlx->ray.ra = mlx->player.pa;
//	da = -1 * deg_to_rad(1);
	a = update_angle(mlx->player.pa, deg_to_rad(fov / 2));
	while (i < fov) // 1 ray
	{
		init_ray(mlx, a);
		draw_ray(mlx);
		a = update_angle(a, deg_to_rad(-1));
		i++;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
void	draw_player(t_mlx_data *mlx)
{
	t_player	p;
	int		green;
	int		i;
	int		j;

	green = encode_rgb(0, 255, 0);
	i = -2;
	p = mlx->player;
	while (i < 2)
	{
		j = -2;
		while (j < 2)
		{
			img_pix_put(&mlx->img_ptr, p.px + i, p.py + j, green);
			j++;
		}
		i++;
	}
	draw_full_line(mlx, p.px, p.py, p.px + p.dx * 2, p.py + p.dy * 2, green);

}

/* ************************************************************************** */
/* ************************************************************************** */
void	full_img(t_mlx_data *mlx)
{
	t_pix	pix;
	int		black;
	int		white;

	black = encode_rgb(0, 0, 0);
	white = encode_rgb(255, 255, 255);
	pix.y = 0;
	while (pix.y < mlx->h)
	{
		pix.x = 0;
		while (pix.x < mlx->h)//mlx->w)
		{
			wall_col(&pix, &mlx->grid, black, white);
			img_pix_put(&mlx->img_ptr, pix.x, pix.y, pix.col);
			pix.x++;
		}
		pix.y++;
	}
	draw_rays(mlx);
	draw_player(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr.mlx_img,
		0, 0);
}