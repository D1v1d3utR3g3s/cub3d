/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_anim_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 07:59:36 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/23 22:00:46 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic_bonus.h"

/* ************************************************************************** */
/*                               allow_for_anim                               */
/* -------------------------------------------------------------------------- */
/* This function returns an int value that correspond to all the direction    */
/* allow for an anim display on the wall located in (x, y) coordinates        */
/* rq : a dir is allow if the next tile in dir exists & is associated to '0'  */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - int x : the x coordinate of the tile that we check                      */
/*  - int y : the y coordinate of the tile that we check                      */
/* Return :                                                                   */
/*  - int : the int value associated to all the dir allowed                   */
/* ************************************************************************** */
int	allow_for_anim(t_c3d_data *c3d, int x, int y)
{
	int		res;
	t_maze	*maze;

	res = 0;
	maze = &(c3d->maze);
	if ((x < 0 || x >= maze->nb_col) || (y < 0 || y >= maze->nb_line))
		return (0);
	if (maze->map[y * maze->nb_col + x] != '1')
		return (0);
	if (y != 0 && maze->map[(y - 1) * maze->nb_col + x] == '0')
		res += pow(2, NORTH);
	if (y != maze->nb_line - 1 && maze->map[(y + 1) * maze->nb_col + x] == '0')
		res += pow(2, SOUTH);
	if (x != maze->nb_col - 1 && maze->map[y * maze->nb_col + (x + 1)] == '0')
		res += pow(2, EAST);
	if (x != 0 && maze->map[y * maze->nb_col + (x - 1)] == '0')
		res += pow(2, WEST);
	return (res);
}

/* ************************************************************************** */
/*                             determine_dir_anim                             */
/* -------------------------------------------------------------------------- */
/* This function initialises the direction of the display anim (between the   */
/* allow direction(s) contained in dir_allow). The direction is obtained      */
/* randomly                                                                   */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - int dir_allow : allow direction(s) associated to the tile for anim      */
/* Return :                                                                   */
/*  - int : the direction associated to the anim display                      */
/* ************************************************************************** */
int	determine_dir_anim(t_c3d_data *c3d, int dir_allow)
{
	int	rand_dir;
	int	ind;
	int	n;

	rand_dir = rand_int(0, 3, c3d);
	n = dir_allow;
	ind = 3;
	while (ind >= 0)
	{
		if (ind == rand_dir)
		{
			if ((int)(n / pow(2, rand_dir)) == 1)
				return (rand_dir);
			else
			{
				rand_dir = rand_int(0, 3, c3d);
				n = dir_allow;
				ind = 4;
			}
		}
		else
			n = (int)(n % (int)pow(2, ind));
		ind--;
	}
	return (rand_dir);
}

/* ************************************************************************** */
/*                            get_current_anim_id                             */
/* -------------------------------------------------------------------------- */
/* This function determines the id of the sequence animation in function of   */
/* current time, the initial time and the delta time (dt) between each switch */
/* of step (img)                                                              */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	get_current_anim_id(t_c3d_data *c3d)
{
	long	cur_t;
	int		t;
	int		n;
	int		delta;

	n = c3d->anim.nb_anim - 1;
	cur_t = gettime_in(MILLISECONDS, c3d);
	t = abs((int)(cur_t - c3d->anim.t0));
	delta = t % (c3d->anim.dt * c3d->anim.nb_anim);
	while (n >= 0)
	{
		if (delta >= n * c3d->anim.dt)
		{
			c3d->anim.anim_id = n;
			return ;
		}
		n--;
	}
}

/* ************************************************************************** */
/*                             determine_offset_x                             */
/* -------------------------------------------------------------------------- */
/* This function determines the offset_x to apply to the x axis in function   */
/* of the direction of the wall                                               */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - int : the offset to apply                                               */
/* ************************************************************************** */
static int	determine_anim_offset_x(t_c3d_data *c3d, int dir, t_mlx_img tmp)
{
	int	offset_x;

	offset_x = 0;
	if (dir == NORTH)
		offset_x = (int)c3d->ray.rx % c3d->maze.w_tile;
	else if (dir == SOUTH)
	{
		offset_x = (int)c3d->ray.rx % c3d->maze.w_tile;
		offset_x = tmp.width - offset_x;
	}
	else if (dir == EAST)
		offset_x = (int)c3d->ray.ry % c3d->maze.w_tile;
	else if (dir == WEST)
	{
		offset_x = (int)c3d->ray.ry % c3d->maze.w_tile;
		offset_x = tmp.width - offset_x;
	}
	return (offset_x);
}

/* ************************************************************************** */
/*                               get_anim_color                               */
/* -------------------------------------------------------------------------- */
/* This function determines the color associated to a pixel on a wall from    */
/* the sequencial image of the animation                                      */
/* This color depends of the x coordinate (dx), the y coordinate and the      */
/* height of the wall that we want to colorise.                               */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - int y : the y coordinate of the tile                                    */
/*  - int dx : the x coordinate of the tile                                   */
/*  - int line_h : the height of the wall (for proportion purpose)            */
/* Return :                                                                   */
/*  - int : the color associated to the pixel on anim texture                 */
/* ************************************************************************** */
int	get_anim_color(t_c3d_data *c3d, int y, int dx, int line_h)
{
	int			dy;
	int			dist_to_top;
	int			dir;
	int			anim_col;
	t_mlx_img	tmp;

	dir = abs(c3d->anim.dir - 2 - (c3d->anim.dir % 2)) + (c3d->anim.dir % 2);
	if (c3d->ray.wall_dir != dir)
		return (NO_COL);
	tmp = c3d->anim.sprite[c3d->anim.anim_id];
	dist_to_top = y + (line_h - c3d->mlx.h) / 2;
	dy = dist_to_top * tmp.height / line_h;
	dx = determine_anim_offset_x(c3d, dir, tmp);
	dx *= tmp.width / 64;
	anim_col = *(int *)(tmp.addr + (dy * tmp.line_len + dx * tmp.bpp / 8));
	return (anim_col);
}
