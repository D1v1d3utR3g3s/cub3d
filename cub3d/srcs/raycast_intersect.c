/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_intersect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:15:38 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/17 01:35:28 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/*                             init_hor_intersect                             */
/* -------------------------------------------------------------------------- */
/* This function initalises datas relative to the horizontal intersection.    */
/* It calculates the first horizontal intersection point and check if a wall  */
/* is encounter                                                               */
/* rq : the first intersection is the only one that need specific calculs     */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - 8 : if the first horizontal intersection encounter a wall (dof = 8)     */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
static int	init_hor_intersect(t_c3d_data *c3d)
{
	t_ray	*ray;
	int		w_tile;

	ray = &(c3d->ray);
	w_tile = c3d->maze.w_tile;
	ray->ry = (((int)c3d->player.py / w_tile) * w_tile) - 0.0001;
	if (face_down(ray->ra))
		ray->ry += w_tile + 0.0001;
	ray->rx = c3d->player.px + (ray->ry - c3d->player.py) / tan(ray->ra);
	ray->dy = w_tile;
	if (!face_down(ray->ra))
		ray->dy *= -1;
	ray->dx = ray->dy / tan(ray->ra);
	if ((!face_right(ray->ra) && ray->dx > 0)
		|| (face_right(ray->ra) && ray->dx < 0))
		ray->dx *= -1;
	if (ray->ra == 0 || ray->ra == M_PI)
	{
		ray->ry = c3d->player.py;
		ray->rx = c3d->player.px;
		return (8);
	}
	return (0);
}

/* ************************************************************************** */
/*                               hor_intersect                                */
/* -------------------------------------------------------------------------- */
/* This function calculates the distance between the player and the first     */
/* horizontal intersection for which a wall is encounter                      */
/* rq : if no wall is encounter after 8 checks then we stop here, at least    */
/* for now                                                                    */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	hor_intersect(t_c3d_data *c3d)
{
	int		dof;
	int		mp;
	t_ray	*ray;

	ray = &(c3d->ray);
	dof = init_hor_intersect(c3d);
	while (dof < 8)
	{
		mp = calc_mp(ray, c3d);
		if (check_hit_wall(mp, c3d))
		{
			ray->hx = ray->rx;
			ray->hy = ray->ry;
			ray->dh = calc_d(c3d->player.px, c3d->player.py, ray->hx, ray->hy);
			dof = 8;
		}
		else
		{
			ray->rx += ray->dx;
			ray->ry += ray->dy;
			dof++;
		}
	}
}

/* ************************************************************************** */
/*                             init_ver_intersect                             */
/* -------------------------------------------------------------------------- */
/* This function initalises datas relative to the vertical intersection.      */
/* It calculates the first vertical intersection point and check if a wall    */
/* is encounter                                                               */
/* rq : the first intersection is the only one that need specific calculs     */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - 8 : if the first vertical intersection encounter a wall (dof = 8)       */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
static int	init_ver_intersect(t_c3d_data *c3d)
{
	t_ray	*ray;
	int		w_tile;

	ray = &(c3d->ray);
	w_tile = c3d->maze.w_tile;
	ray->rx = (((int)c3d->player.px / w_tile) * w_tile) - 0.0001;
	if (face_right(ray->ra))
		ray->rx += w_tile + 0.0001;
	ray->ry = c3d->player.py + (ray->rx - c3d->player.px) * tan(ray->ra);
	ray->dx = w_tile;
	if (!face_right(ray->ra))
		ray->dx *= -1;
	ray->dy = ray->dx * tan(ray->ra);
	if ((!face_down(ray->ra) && ray->dy > 0)
		|| (face_down(ray->ra) && ray->dy < 0))
		ray->dy *= -1;
	if (ray->ra == M_PI / 2 || ray->ra == 3 * M_PI / 2)
	{
		ray->ry = c3d->player.py;
		ray->rx = c3d->player.px;
		return (8);
	}
	return (0);
}

/* ************************************************************************** */
/*                               ver_intersect                                */
/* -------------------------------------------------------------------------- */
/* This function calculates the distance between the player and the first     */
/* vertical intersection for which a wall is encounter                        */
/* rq : if no wall is encounter after 8 checks then we stop here, at least    */
/* for now                                                                    */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	ver_intersect(t_c3d_data *c3d)
{
	int		dof;
	int		mp;
	t_ray	*ray;

	ray = &(c3d->ray);
	dof = init_ver_intersect(c3d);
	while (dof < 8)
	{
		mp = calc_mp(ray, c3d);
		if (check_hit_wall(mp, c3d))
		{
			ray->vx = ray->rx;
			ray->vy = ray->ry;
			ray->dv = calc_d(c3d->player.px, c3d->player.py, ray->vx, ray->vy);
			dof = 8;
		}
		else
		{
			ray->rx += ray->dx;
			ray->ry += ray->dy;
			dof++;
		}
	}
}
