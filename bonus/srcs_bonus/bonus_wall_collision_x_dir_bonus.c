/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_wall_collision_x_dir_bonus.c                 :+:      :+:    :+:   */
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
static int	check_obstacle_x_dir_hit_box_x(t_c3d_data *c3d, float dx, int i)
{
	int	ipx_add;
	int	ipy;
	int	nb_step;

	nb_step = fabs(dx);
	ipx_add = (int)(c3d->player.px + 0.1 + (dx / nb_step) * i);
	ipy = c3d->player.py;
	if (check_obstacle(c3d, ipx_add, ipy, c3d->maze.w_tile))
		return (1);
	ipx_add = (int)(c3d->player.px - 0.1 + (dx / nb_step) * i);
	ipy = c3d->player.py;
	if (check_obstacle(c3d, ipx_add, ipy, c3d->maze.w_tile))
		return (1);
	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */
static int	check_obstacle_x_dir_hit_box_y(t_c3d_data *c3d, float dx, int i)
{
	int	ipx_add;
	int	ipy;
	int	nb_step;

	nb_step = fabs(dx);
	ipx_add = (int)(c3d->player.px + (dx / nb_step) * i);
	ipy = c3d->player.py + 0.1;
	if (check_obstacle(c3d, ipx_add, ipy, c3d->maze.w_tile))
		return (1);
	ipx_add = (int)(c3d->player.px + (dx / nb_step) * i);
	ipy = c3d->player.py - 0.1;
	if (check_obstacle(c3d, ipx_add, ipy, c3d->maze.w_tile))
		return (1);
	return (0);
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
int	check_x_dir_mov(t_c3d_data *c3d, float dx)
{
	int	i;
	int	ipx_add;
	int	ipy;
	int	nb_step;

	nb_step = fabs(dx);
	i = 0;
	while (i <= nb_step)
	{
		ipx_add = (int)(c3d->player.px + (dx / nb_step) * i);
		ipy = c3d->player.py;
		if (check_obstacle(c3d, ipx_add, ipy, c3d->maze.w_tile))
			return (0);
		if (check_obstacle_x_dir_hit_box_x(c3d, dx, i))
			return (0);
		if (check_obstacle_x_dir_hit_box_y(c3d, dx, i))
			return (0);
		i++;
	}
	return (1);
}
