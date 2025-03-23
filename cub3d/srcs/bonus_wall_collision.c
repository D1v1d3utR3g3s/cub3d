/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_wall_collision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:48:28 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/23 18:22:03 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic.h"

/* ************************************************************************** */
/*                               check_obstacle                               */
/* -------------------------------------------------------------------------- */
/* This function checks if an obstacle is on the maze index associated to     */
/* coordinates (x, y) converted in maze coordinates                           */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - int x : x coordinates                                                   */
/*  - int y : y coordinates                                                   */
/*  - int w_tile : tile width (and height)                                    */
/* Return :                                                                   */
/*  - 1 : if an obstacle is encounter (or outside maze)                       */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
static int	check_obstacle(t_c3d_data *c3d, int x, int y, int w_tile)
{
	int	mx;
	int	my;

	mx = x / w_tile;
	my = y / w_tile;
	if (mx < 0 || mx >= c3d->maze.nb_col)
		return (1);
	if (my < 0 || my >= c3d->maze.nb_line)
		return (1);
	if (c3d->maze.map[my * c3d->maze.nb_col + mx] == '1')
		return (1);
	if (c3d->maze.map[my * c3d->maze.nb_col + mx] == '_')
		return (1);
	if (BONUS_DOOR)
	{
		if (c3d->maze.map[my * c3d->maze.nb_col + mx] == '2')
			return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                              check_bi_dir_mov                              */
/* -------------------------------------------------------------------------- */
/* This function checks if the player can mov on both the x and y axis        */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - float dx : the delta value (x axis) associated to the movement          */
/*  - float dy : the delta value (y axis) associated to the movement          */
/* Return :                                                                   */
/*  - 1 : if movement is allow on both axis                                   */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
static int	check_bi_dir_mov(t_c3d_data *c3d, float dx, float dy)
{
	int	i;
	int	ipx_add;
	int	ipy_add;
	int	nb_step;
	int	margin;

	nb_step = fmax(fabs(dx), fabs(dy));
	i = 0;
	margin = 14;
	while (i <= nb_step)
	{
		ipx_add = (int)(c3d->player.px + (dx / nb_step) * i);
		ipy_add = (int)(c3d->player.py + (dy / nb_step) * i);
		if (check_obstacle(c3d, ipx_add, ipy_add, c3d->maze.w_tile))
			return (0);
		if (ipx_add != 0 && ipx_add % c3d->maze.w_tile == 0)
			ipx_add -= margin;
		if (ipy_add != 0 && ipy_add % c3d->maze.w_tile == 0)
			ipy_add -= margin;
		if (check_obstacle(c3d, ipx_add, ipy_add, c3d->maze.w_tile))
			return (0);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                              check_x_dir_mov                               */
/* -------------------------------------------------------------------------- */
/* This function checks if the player can mov on x axis                       */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - float dx : the delta value (x axis) associated to the movement          */
/* Return :                                                                   */
/*  - 1 : if movement is allow on x axis                                      */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
static int	check_x_dir_mov(t_c3d_data *c3d, float dx)
{
	int	i;
	int	ipx_add;
	int	ipy;
	int	nb_step;
	int	margin;

	nb_step = fabs(dx);
	i = 0;
	margin = 14;
	while (i <= nb_step)
	{
		ipx_add = (int)(c3d->player.px + (dx / nb_step) * i);
		ipy = c3d->player.py;
		if (check_obstacle(c3d, ipx_add, ipy, c3d->maze.w_tile))
			return (0);
		if (ipx_add != 0 && ipx_add % c3d->maze.w_tile == 0)
			ipx_add -= margin;
		if (ipy != 0 && ipy % c3d->maze.w_tile == 0)
			ipy -= margin;
		if (check_obstacle(c3d, ipx_add, ipy, c3d->maze.w_tile))
			return (0);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                              check_y_dir_mov                               */
/* -------------------------------------------------------------------------- */
/* This function checks if the player can mov on y axis                       */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - float dy : the delta value (y axis) associated to the movement          */
/* Return :                                                                   */
/*  - 1 : if movement is allow on y axis                                      */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
static int	check_y_dir_mov(t_c3d_data *c3d, float dy)
{
	int	i;
	int	ipx;
	int	ipy_add;
	int	nb_step;
	int	margin;

	nb_step = fabs(dy);
	i = 0;
	margin = 14;
	while (i <= nb_step)
	{
		ipx = c3d->player.px;
		ipy_add = (int)(c3d->player.py + (dy / nb_step) * i);
		if (check_obstacle(c3d, ipx, ipy_add, c3d->maze.w_tile))
			return (0);
		if (ipx != 0 && ipx % c3d->maze.w_tile == 0)
			ipx -= margin;
		if (ipy_add != 0 && ipy_add % c3d->maze.w_tile == 0)
			ipy_add -= margin;
		if (check_obstacle(c3d, ipx, ipy_add, c3d->maze.w_tile))
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
