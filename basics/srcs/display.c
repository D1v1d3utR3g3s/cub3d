/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:55:31 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/11 15:01:36 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

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

/* ************************************************************************** */
/* ************************************************************************** */
float	update_angle(float a, float da)
{
	float	new_a;

	new_a = a + da;
	if (new_a > 2 * M_PI)
		new_a -= 2 * M_PI;
	else if (new_a < 0)
		new_a += 2 * M_PI;
	return (new_a);
}

/* ************************************************************************** */
/* ************************************************************************** */
void	draw_rays(t_c3d_data *c3d)
{
	int		i;
	int		fov;
	float	a;

	i = 0;
	fov = 60;
//	c3d->ray.ra = c3d->player.pa;
//	da = -1 * deg_to_rad(1);
	a = update_angle(c3d->player.pa, deg_to_rad(-fov / 2));
	while (i <= fov) // 1 ray
	{
		init_ray(c3d, a);
		draw_ray(c3d);
		draw3D(c3d, i);
		a = update_angle(a, deg_to_rad(1));
		i++;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
void	draw_player(t_c3d_data *c3d)
{
	t_player	p;
	int			green;
	int			i;
	int			j;

	green = encode_rgb(0, 255, 0);
	i = -2;
	p = c3d->player;
	while (i < 2)
	{
		j = -2;
		while (j < 2)
		{
			img_pix_put(&c3d->img_ptr, p.px + i, p.py + j, green);
			j++;
		}
		i++;
	}
	draw_full_line(c3d, p.px, p.py, p.px + p.dx * 2, p.py + p.dy * 2, green);
}

/* ************************************************************************** */
/* ************************************************************************** */
void	full_img(t_c3d_data *c3d)
{
	t_pix	pix;
	int		black;
	int		white;

	black = encode_rgb(0, 0, 0);
	white = encode_rgb(255, 255, 255);
	pix.y = 0;
	while (pix.y < c3d->h)
	{
		pix.x = 0;
		while (pix.x < c3d->w)//c3d->h)
		{
			if (pix.x < c3d->h)
				wall_col(&pix, &c3d->grid, black, white);
			else
				pix.col = black;
			img_pix_put(&c3d->img_ptr, pix.x, pix.y, pix.col);
			pix.x++;
		}
		pix.y++;
	}
	draw_rays(c3d);
	draw_player(c3d);
	mlx_put_image_to_window(c3d->mlx_ptr, c3d->win_ptr, c3d->img_ptr.mlx_img,
		0, 0);
}
