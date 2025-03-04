/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_intersect_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:15:38 by hauerbac          #+#    #+#             */
/*   Updated: 2025/03/04 15:23:36 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/*                               check_hit_wall                               */
/* -------------------------------------------------------------------------- */
/* This function checks if the map element corresponding to the index mp is   */
/* a wall (has a value of 1)                                                  */
/* Inputs :                                                                   */
/*  - int mp : the index of the element that we want to check in map array    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - 1 : if the element is a wall                                            */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
int	check_hit_wall(int mp, t_c3d_data *c3d)
{
	if ((mp > 0) && (mp < c3d->maze.nb_col * c3d->maze.nb_line))
	{
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
