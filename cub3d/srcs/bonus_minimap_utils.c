/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:53:20 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/23 18:23:13 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic.h"

/* ************************************************************************** */
/*                              check_in_minimap                              */
/* -------------------------------------------------------------------------- */
/* This function checks if the pixel (x, y) is in the minimap location        */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - int x : x coordinate to check                                           */
/*  - int y : y coordinate to check                                           */
/* Return :                                                                   */
/*  - 1 : if pixel (x, y) is in the minimap location                          */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
int	check_in_minimap(t_c3d_data *c3d, int x, int y)
{
	if (x >= c3d->min_map.x0 && x <= c3d->min_map.x0 + c3d->min_map.w)
	{
		if (y >= c3d->min_map.y0 && y <= c3d->min_map.y0 + c3d->min_map.h)
			return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                               is_outside_map                               */
/* -------------------------------------------------------------------------- */
/* This function checks if the pixel (x, y) is outside the maze               */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - int x : x coordinate to check                                           */
/*  - int y : y coordinate to check                                           */
/* Return :                                                                   */
/*  - 1 : if pixel (x, y) is outside maze                                     */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
int	is_outside_map(t_c3d_data *c3d, int x, int y)
{
	int	w;
	int	h;

	w = c3d->maze.nb_col * c3d->maze.w_tile;
	h = c3d->maze.nb_line * c3d->maze.w_tile;
	if ((x < 0 || x > w) || (y < 0 || y > h))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                            is_on_border_minmap                             */
/* -------------------------------------------------------------------------- */
/* This function checks if the pixel (mmx, mmy) is on border of the minimap   */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - int mmx : x coordinate to check                                         */
/*  - int mmy : y coordinate to check                                         */
/* Return :                                                                   */
/*  - 1 : if pixel (mmx, mmy) is on border of the minimap                     */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
int	is_on_border_minmap(t_c3d_data *c3d, int mmx, int mmy)
{
	if (mmx == 0 || mmx == c3d->min_map.w - 1)
		return (1);
	if (mmy == 0 || mmy == c3d->min_map.h - 1)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                 is_fov_lim                                 */
/* -------------------------------------------------------------------------- */
/* This function checks if the pixel (mmx, mmy) is on fov lim line & d to     */
/* player <= 10                                                               */
/* rq : fov lim == fov / 2 || fov lim == - fov / 2                            */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - int mmx : x coordinate to check                                         */
/*  - int mmy : y coordinate to check                                         */
/* Return :                                                                   */
/*  - 1 : if pixel (mmx, mmy) is on fov lim                                   */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
int	is_fov_lim(t_c3d_data *c3d, int mmx, int mmy)
{
	t_minimap	*mmp;
	float		a;
	float		da;
	int			d;

	mmp = &(c3d->min_map);
	a = c3d->player.pa;
	da = deg_to_rad(c3d->player.fov / 2);
	d = 0;
	while (d <= 10)
	{
		if (mmx == (int)(mmp->mmp_px + d * cos(a + da)))
		{
			if (mmy == (int)(mmp->mmp_py + d * sin(a + da)))
				return (1);
		}
		if (mmx == (int)(mmp->mmp_px + d * cos(a - da)))
		{
			if (mmy == (int)(mmp->mmp_py + d * sin(a - da)))
				return (1);
		}
		d++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                 is_player                                  */
/* -------------------------------------------------------------------------- */
/* This function checks if the pixel (mmx, mmy) corresponds to player coord   */
/* on minimap or fov lim                                                      */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - int mmx : x coordinate to check                                         */
/*  - int mmy : y coordinate to check                                         */
/* Return :                                                                   */
/*  - 1 : if pix (mmx, mmy) corresponds to player coord on minimap or fov lim */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
int	is_player(t_c3d_data *c3d, int mmx, int mmy)
{
	if (mmx == c3d->min_map.mmp_px && mmy == c3d->min_map.mmp_py)
	{
		return (1);
	}
	if (is_fov_lim(c3d, mmx, mmy))
	{
		return (1);
	}
	return (0);
}
