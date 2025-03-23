/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:15:38 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/23 21:46:38 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic_bonus.h"

/* ************************************************************************** */
/*                           update_nearest_ray_hit                           */
/* -------------------------------------------------------------------------- */
/* This function updates nearest hit datas (rx, ry, dist_wall)                */
/* Inputs :                                                                   */
/*  - t_ray *ray : pointer to structure that contained ray datas              */
/*  - int x : the x coordinate to associate to rx                             */
/*  - int y : the y coordinate to associate to ry                             */
/*  - int dist : distance between the player and the nearest hit of a wall    */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
static void	update_nearest_ray_hit(t_ray *ray, int x, int y, int dist)
{
	ray->rx = x;
	ray->ry = y;
	ray->dist_wall = dist;
}

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
	if ((ray->hit_h == 0) && (ray->hit_v == 0))
	{
		ray->rx = c3d->player.px;
		ray->ry = c3d->player.py;
	}
	else if ((ray->hit_h == 0) || ((ray->hit_v != 0) && (ray->dv <= ray->dh)))
	{
		update_nearest_ray_hit(ray, ray->vx, ray->vy, ray->dv);
		if (face_right(ray->ra))
			ray->wall_dir = EAST;
		else
			ray->wall_dir = WEST;
	}
	else if ((ray->hit_v == 0) || ((ray->hit_h != 0) && (ray->dh < ray->dv)))
	{
		update_nearest_ray_hit(ray, ray->hx, ray->hy, ray->dh);
		if (face_down(ray->ra))
			ray->wall_dir = SOUTH;
		else
			ray->wall_dir = NORTH;
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
/*                            colorise_wall_height                            */
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
static void	colorise_wall_height(int ray_nb, t_c3d_data *c3d)
{
	float	angle_offset;
	float	d;
	int		delta;
	float	line_h;

	angle_offset = update_angle(c3d->player.pa, -c3d->ray.ra);
	d = compensate_fishbowl_distortion(c3d->ray.dist_wall, angle_offset);
	delta = c3d->mlx.h * (c3d->mlx.w / c3d->mlx.h);
	line_h = (c3d->maze.w_tile * delta) / d;
	if (line_h < 0)
		line_h = 0;
	extract_slice_tex(&c3d->mlx, c3d, ray_nb, line_h);
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
	if (BONUS_DOOR)
		init_doors_val(c3d);
	while (n_ray < c3d->mlx.w)
	{
		c3d->ray.wall_dir = -1;
		calc_nearest_intersect(c3d);
		if (c3d->ray.wall_dir != -1)
			colorise_wall_height(n_ray, c3d);
		a = update_angle(a, da);
		init_ray(c3d, a);
		n_ray++;
	}
}
