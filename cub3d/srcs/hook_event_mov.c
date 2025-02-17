/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event_mov.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:57:25 by roxane            #+#    #+#             */
/*   Updated: 2025/02/17 01:31:33 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/******************************************************************************/
/*                            associate_dir_angle                             */
/* -------------------------------------------------------------------------- */
/* This function converts 'w', 'a', 's', 'd' movement direction in a delta    */
/* angle to associate to the movement                                         */
/* (w => up => delta = 0, a => left => delta = -pi / 2, etc.)                 */
/* Input :                                                                    */
/*  - char dir : the key associate to the movement to translate               */
/* Return :                                                                   */
/*  - float : the delta angle to associate to the movement                    */
/******************************************************************************/
static float	associate_dir_angle(char dir)
{
	if (dir == 'a')
		return (-M_PI / 2);
	else if (dir == 's')
		return (M_PI);
	else if (dir == 'd')
		return (M_PI / 2);
	return (0);
}

/******************************************************************************/
/*                                 mov_allow                                  */
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
static int	mov_allow(t_c3d_data *c3d, float dx, float dy)
{
	int	ipx;
	int	ipx_add;
	int	ipy;
	int	ipy_add;

	ipx = c3d->player.px / c3d->maze.w_tile;
	ipx_add = (int)(c3d->player.px + dx) / c3d->maze.w_tile;
	ipy = c3d->player.py / c3d->maze.w_tile;
	ipy_add = (int)(c3d->player.py + dy) / c3d->maze.w_tile;
	if (c3d->maze.map[ipy_add * c3d->maze.nb_col + ipx_add] == '0')
		return (3);
	else if (c3d->maze.map[ipy * c3d->maze.nb_col + ipx_add] == '0')
		return (1);
	else if (c3d->maze.map[ipy_add * c3d->maze.nb_col + ipx] == '0')
		return (2);
	return (0);
}

/******************************************************************************/
/*                             which_delta_apply                              */
/* -------------------------------------------------------------------------- */
/* This function checks following which axis (/axes) the movement is allowed  */
/* (x, y, both or none)                                                       */
/* To do so, delta following both axes (x and y) are calculate as well as the */
/* margin  to apply for both direction                                        */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/*  - float dir_a : the delta angle associated to the movement                */
/* Return :                                                                   */
/*  - 1 : movement allowed in x axis (only)                                   */
/*  - 2 : movement allowed in y axis (only)                                   */
/*  - 3 : movement allowed in x et y axes (both)                              */
/*  - 0 : movement is not allowed in any direction                            */
/******************************************************************************/
static int	which_delta_apply(t_c3d_data *c3d, float dir_a)
{
	float	dx;
	float	dy;

	dx = calc_dx(c3d, dir_a);
	dy = calc_dy(c3d, dir_a);
	dx += calc_margin(dx);
	dy += calc_margin(dy);
	return (mov_allow(c3d, dx, dy));
}

/******************************************************************************/
/*                                  move_dir                                  */
/* -------------------------------------------------------------------------- */
/* This function applies the allowed movements to the player                  */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/*  - char dir : key associate to the movement apply                          */
/* Return :                                                                   */
/*  - None                                                                    */
/******************************************************************************/
void	move_dir(t_c3d_data *c3d, char dir)
{
	float	dir_a;
	float	dx;
	float	dy;
	int		mov;

	dir_a = associate_dir_angle(dir);
	dx = calc_dx(c3d, dir_a);
	dy = calc_dy(c3d, dir_a);
	mov = which_delta_apply(c3d, dir_a);
	if (mov == 3)
	{
		c3d->player.px += dx;
		c3d->player.py += dy;
	}
	else if (mov == 1)
		c3d->player.px += dx;
	else if (mov == 2)
		c3d->player.py += dy;
}
