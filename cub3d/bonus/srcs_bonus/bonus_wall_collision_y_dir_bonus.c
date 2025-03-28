/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_wall_collision_y_dir_bonus.c                 :+:      :+:    :+:   */
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
static int	check_obstacle_y_dir_hit_box_x(t_c3d_data *c3d, float dy, int i)
{
	int	ipx;
	int	ipy_add;
	int	nb_step;

	nb_step = fabs(dy);
	ipx = c3d->player.px + 0.1;
	ipy_add = (int)(c3d->player.py + (dy / nb_step) * i);
	if (check_obstacle(c3d, ipx, ipy_add, c3d->maze.w_tile))
		return (1);
	ipx = c3d->player.px - 0.1;
	ipy_add = (int)(c3d->player.py + (dy / nb_step) * i);
	if (check_obstacle(c3d, ipx, ipy_add, c3d->maze.w_tile))
		return (1);
	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */
static int	check_obstacle_y_dir_hit_box_y(t_c3d_data *c3d, float dy, int i)
{
	int	ipx;
	int	ipy_add;
	int	nb_step;

	nb_step = fabs(dy);
	ipx = c3d->player.px;
	ipy_add = (int)(c3d->player.py + 0.1 + (dy / nb_step) * i);
	if (check_obstacle(c3d, ipx, ipy_add, c3d->maze.w_tile))
		return (1);
	ipx = c3d->player.px;
	ipy_add = (int)(c3d->player.py - 0.1 + (dy / nb_step) * i);
	if (check_obstacle(c3d, ipx, ipy_add, c3d->maze.w_tile))
		return (1);
	return (0);
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
int	check_y_dir_mov(t_c3d_data *c3d, float dy)
{
	int	i;
	int	ipx;
	int	ipy_add;
	int	nb_step;

	nb_step = fabs(dy);
	i = 0;
	while (i <= nb_step)
	{
		ipx = c3d->player.px;
		ipy_add = (int)(c3d->player.py + (dy / nb_step) * i);
		if (check_obstacle(c3d, ipx, ipy_add, c3d->maze.w_tile))
			return (0);
		if (check_obstacle_y_dir_hit_box_x(c3d, dy, i))
			return (0);
		if (check_obstacle_y_dir_hit_box_y(c3d, dy, i))
			return (0);
		i++;
	}
	return (1);
}
