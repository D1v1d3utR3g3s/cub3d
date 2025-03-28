/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_wall_collision_bi_dir_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:48:28 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/23 21:36:55 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic_bonus.h"

/* ************************************************************************** */
/* ************************************************************************** */
static int	check_obst_bidir_xhitbox(t_c3d_data *c3d, float dx, float dy, int i)
{
	int	ipx_add;
	int	ipy_add;
	int	nb_step;

	nb_step = fmax(fabs(dx), fabs(dy));
	ipx_add = (int)(c3d->player.px + 0.1 + (dx / nb_step) * i);
	ipy_add = (int)(c3d->player.py + (dy / nb_step) * i);
	if (check_obstacle(c3d, ipx_add, ipy_add, c3d->maze.w_tile))
		return (1);
	ipx_add = (int)(c3d->player.px - 0.1 + (dx / nb_step) * i);
	ipy_add = (int)(c3d->player.py + (dy / nb_step) * i);
	if (check_obstacle(c3d, ipx_add, ipy_add, c3d->maze.w_tile))
		return (1);
	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */
static int	check_obst_bidir_yhitbox(t_c3d_data *c3d, float dx, float dy, int i)
{
	int	ipx_add;
	int	ipy_add;
	int	nb_step;

	nb_step = fmax(fabs(dx), fabs(dy));
	ipx_add = (int)(c3d->player.px + (dx / nb_step) * i);
	ipy_add = (int)(c3d->player.py + 0.1 + (dy / nb_step) * i);
	if (check_obstacle(c3d, ipx_add, ipy_add, c3d->maze.w_tile))
		return (1);
	ipx_add = (int)(c3d->player.px + (dx / nb_step) * i);
	ipy_add = (int)(c3d->player.py - 0.1 + (dy / nb_step) * i);
	if (check_obstacle(c3d, ipx_add, ipy_add, c3d->maze.w_tile))
		return (1);
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
int	check_bi_dir_mov(t_c3d_data *c3d, float dx, float dy)
{
	int	i;
	int	ipx_add;
	int	ipy_add;
	int	nb_step;

	nb_step = fmax(fabs(dx), fabs(dy));
	i = 0;
	while (i <= nb_step)
	{
		ipx_add = (int)(c3d->player.px + (dx / nb_step) * i);
		ipy_add = (int)(c3d->player.py + (dy / nb_step) * i);
		if (check_obstacle(c3d, ipx_add, ipy_add, c3d->maze.w_tile))
			return (0);
		if (check_obst_bidir_xhitbox(c3d, dx, dy, i))
			return (0);
		if (check_obst_bidir_yhitbox(c3d, dx, dy, i))
			return (0);
		i++;
	}
	return (1);
}
