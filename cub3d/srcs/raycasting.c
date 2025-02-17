/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:15:38 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/17 02:31:36 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/*                             nearest_intersect                              */
/* -------------------------------------------------------------------------- */
/* This function determines which wall is the closest to the player for the   */
/* ray (horizontal or vertical intersection)                                  */
/* The usefull datas about the nearest intersection are update (coordinates,  */
/* distance player-wall, color of the wall)                                   */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
static void	nearest_intersect(t_c3d_data *c3d)
{
	t_ray	*ray;

	ray = &(c3d->ray);
	if ((ray->dh == -1) && (ray->dv == -1))
	{
		ray->rx = c3d->player.px;
		ray->ry = c3d->player.py;
	}
	else if ((ray->dh == -1) || ((ray->dv != -1) && (ray->dv <= ray->dh)))
	{
		ray->rx = ray->vx;
		ray->ry = ray->vy;
		ray->dist_wall = ray->dv;
		if (face_right(ray->ra))
			ray->col_wall = c3d->m_col.ea;
		else
			ray->col_wall = c3d->m_col.we;
	}
	else if ((ray->dv == -1) || (((ray->dh != -1) && ray->dh < ray->dv)))
	{
		ray->rx = ray->hx;
		ray->ry = ray->hy;
		ray->dist_wall = ray->dh;
		if (face_down(ray->ra))
			ray->col_wall = c3d->m_col.so;
		else
			ray->col_wall = c3d->m_col.no;
	}
}

/* ************************************************************************** */
/*                           calc_nearest_intersect                           */
/* -------------------------------------------------------------------------- */
/* This function determines which wall is the closest to the player for the   */
/* ray (horizontal or vertical intersection)                                  */
/* To do so, we calculate the nearest horizontal intersection, then the       */
/* nearest vertical one before keeping the data associated to the closest of  */
/* the two                                                                    */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
static void	calc_nearest_intersect(t_c3d_data *c3d)
{
	hor_intersect(c3d);
	ver_intersect(c3d);
	nearest_intersect(c3d);
}

/* ************************************************************************** */
/*                       compensate_fishbowl_distortion                       */
/* -------------------------------------------------------------------------- */
/* This function compensates the fishbow distortion generated during the 3D   */
/* conversion                                                                 */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
static float	compensate_fishbowl_distortion(float d, float angle)
{
	return (d * cos(angle));
}

/* ************************************************************************** */
/*                              calc_wall_height                              */
/* -------------------------------------------------------------------------- */
/* This function converts the player-ray distance in height of the wall       */
/* The colors of the pixels that composed the wall height (over 1 pixel) is   */
/* set                                                                        */
/* Inputs :                                                                   */
/*  - int ray_nb : the "id" of the ray (x axis)                               */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
static void	calc_wall_height(int ray_nb, t_c3d_data *c3d)
{
	float	line_h;
	float	offset;
	float	angle_offset;
	float	d;
	int		delta;

	angle_offset = update_angle(c3d->player.pa, -c3d->ray.ra);
	d = compensate_fishbowl_distortion(c3d->ray.dist_wall, angle_offset);
	delta = 320;
	line_h = (c3d->maze.w_tile * delta) / d;
//	if (line_h > c3d->mlx.w)//delta)
//		line_h = c3d->mlx.w;//delta;
	if (line_h < 0)
		line_h = 0;
	offset = (delta - line_h) / 2;
	update_3d_line_col(ray_nb, offset, ray_nb, offset + line_h, c3d);
//	update_line_col(ray_nb, offset, line_h, c3d);
}

/* ************************************************************************** */
/*                                  raycast                                   */
/* -------------------------------------------------------------------------- */
/* This function casts window's width rays, finds the nearest intersection    */
/* and associate colors for each wall pixels                                  */
/* set                                                                        */
/* Inputs :                                                                   */
/*  - int ray_nb : the "id" of the ray (x axis)                               */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	raycast(t_c3d_data *c3d)
{
	int		n_ray;
	int		fov;
	float	a;
	float	da;

	n_ray = 0;
	fov = c3d->player.fov;
	a = update_angle(c3d->player.pa, deg_to_rad(-fov / 2));
	init_ray(c3d, a);
	da = deg_to_rad(fov) / c3d->mlx.w;
	while (n_ray < c3d->mlx.w)
	{
		calc_nearest_intersect(c3d);
		calc_wall_height(n_ray, c3d);
		a = update_angle(a, da);
		init_ray(c3d, a);
		n_ray++;
	}
}
