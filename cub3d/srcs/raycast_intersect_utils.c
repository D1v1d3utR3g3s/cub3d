/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_intersect_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:15:38 by hauerbac          #+#    #+#             */
/*   Updated: 2025/03/23 18:14:49 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic.h"

/* ************************************************************************** */
/*                               calc_wall_dist                               */
/* -------------------------------------------------------------------------- */
/* This function calculates the dist between the player and the current ray   */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - int : the distance between p(px, py) and ray(rx, ry)                    */
/* ************************************************************************** */
static int	calc_wall_dist(t_c3d_data *c3d)
{
	int	px;
	int	py;
	int	x;
	int	y;

	px = c3d->player.px;
	py = c3d->player.py;
	x = c3d->ray.rx;
	y = c3d->ray.ry;
	return (calc_d(px, py, x, y));
}

/* ************************************************************************** */
/*                               check_hit_wall                               */
/* -------------------------------------------------------------------------- */
/* This function checks if the map element corresponding to the index mp is   */
/* a wall (has a value of 1)                                                  */
/* Inputs :                                                                   */
/*  - int mp : the index of the element that we want to check in map array    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/*  - int dir the dir of the wall hitten                                      */
/* Return :                                                                   */
/*  - 1 : if the element is a wall                                            */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
int	check_hit_wall(int mp, t_c3d_data *c3d, int dir)
{
	int	d;

	if ((mp > 0) && (mp < c3d->maze.nb_col * c3d->maze.nb_line))
	{
		if (BONUS_DOOR == 1)
		{
			if (c3d->maze.map[mp] == '2' || c3d->maze.map[mp] == '3')
			{
				d = calc_wall_dist(c3d);
				update_doors(c3d, mp, d);
			}
			if (c3d->maze.map[mp] == '2')
			{
				if (dir == 0)
					c3d->ray.hit_h_door = 1;
				else
					c3d->ray.hit_v_door = 1;
				return (1);
			}
		}
		if (c3d->maze.map[mp] == '1')
			return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                  calc_mp                                   */
/* -------------------------------------------------------------------------- */
/* This function calculates the mp value (index in map) corresponding to the  */
/* studied ray                                                                */
/* Inputs :                                                                   */
/*  - t_ray *ray : pointer to struct that contained datas relative to a ray   */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - 1 : if the element is a wall                                            */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
int	calc_mp(t_ray *ray, t_c3d_data *c3d)
{
	int	mx;
	int	my;
	int	mp;

	mx = (int)ray->rx / c3d->maze.w_tile;
	if (mx < 0)
		mx = 0;
	else if (mx >= c3d->maze.nb_col)
		mx = c3d->maze.nb_col - 1;
	my = (int)ray->ry / c3d->maze.w_tile;
	if (my < 0)
		my = 0;
	else if (my >= c3d->maze.nb_line)
		my = c3d->maze.nb_line - 1;
	mp = my * c3d->maze.nb_col + mx;
	return (mp);
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
float	compensate_fishbowl_distortion(float d, float angle)
{
	return (d * cos(angle));
}
