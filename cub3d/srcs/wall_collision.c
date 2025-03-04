/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:48:28 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/04 16:10:21 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/******************************************************************************/
/******************************************************************************/
static int	check_bi_dir_mov(t_c3d_data *c3d, float dx, float dy)
{
	int	i;
	int	ipx_add;
	int	ipy_add;
	int	nb_step;

	nb_step = fmax(fabs(dx), fabs(dy));
	i = 0;
	while (i < nb_step)
	{
		ipx_add = (int)(c3d->player.px + (dx / nb_step) * i) / c3d->maze.w_tile;
		ipy_add = (int)(c3d->player.py + (dy / nb_step) * i) / c3d->maze.w_tile;
		if (c3d->maze.map[ipy_add * c3d->maze.nb_col + ipx_add] != '0')
			return (0);
		i++;
	}
	return (1);
}

/******************************************************************************/
/******************************************************************************/
static int	check_x_dir_mov(t_c3d_data *c3d, float dx)
{
	int	i;
	int	ipx_add;
	int	ipy;
	int	nb_step;

	nb_step = fabs(dx);
	i = 0;
	while (i < nb_step)
	{
		ipx_add = (int)(c3d->player.px + (dx / nb_step) * i) / c3d->maze.w_tile;
		ipy = c3d->player.py / c3d->maze.w_tile;
		if (c3d->maze.map[ipy * c3d->maze.nb_col + ipx_add] != '0')
			return (0);
		i++;
	}
	return (1);
}

/******************************************************************************/
/******************************************************************************/
static int	check_y_dir_mov(t_c3d_data *c3d, float dy)
{
	int	i;
	int	ipx;
	int	ipy_add;
	int	nb_step;

	nb_step = fabs(dy);
	i = 0;
	while (i < nb_step)
	{
		ipx = c3d->player.px / c3d->maze.w_tile;
		ipy_add = (int)(c3d->player.py + (dy / nb_step) * i) / c3d->maze.w_tile;
		if (c3d->maze.map[ipy_add * c3d->maze.nb_col + ipx] != '0')
			return (0);
		i++;
	}
	return (1);
}

/******************************************************************************/
/*                               mov_allow_wall                               */
/* -------------------------------------------------------------------------- */
/* This function checks following which axis (/axes) the movement is allowed  */
/* (x, y, both or none)                                                       */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/*  - float dx : the delta value (x axis) associated to the movement          */
/*  - float dy : the delta value (y axis) associated to the movement          */
/* Return :                                                                   */
/*  - 1 : movement allowed in x axis (only)                                   */
/*  - 2 : movement allowed in y axis (only)                                   */
/*  - 3 : movement allowed in x et y axes (both)                              */
/*  - 0 : movement is not allowed in any direction                            */
/******************************************************************************/
int	mov_allow_wall(t_c3d_data *c3d, float dx, float dy)
{
	if (check_bi_dir_mov(c3d, dx, dy) == 1)
		return (3);
	else if (check_x_dir_mov(c3d, dx) == 1)
		return (1);
	else if (check_y_dir_mov(c3d, dy) == 1)
		return (2);
	return (0);
}
