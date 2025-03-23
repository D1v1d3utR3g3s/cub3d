/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event_mov.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:57:25 by roxane            #+#    #+#             */
/*   Updated: 2025/03/23 18:19:45 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic.h"

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
/*                             mov_allow_in_maze                              */
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
static int	mov_allow_in_maze(t_c3d_data *c3d, float dx, float dy)
{
	int	x;
	int	y;
	int	mov;

	x = c3d->player.px + dx;
	y = c3d->player.py + dy;
	mov = 0;
	if (x >= 0 && x < c3d->maze.nb_col * 64)
		mov += 1;
	if (y >= 0 && y < c3d->maze.nb_line * 64)
		mov += 2;
	return (mov);
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
	if (BONUS == 1)
		return (mov_allow_wall(c3d, dx, dy));
	else
		return (mov_allow_in_maze(c3d, dx, dy));
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
	if (DISPLAY_DEBUG)
		display_player_pos(*c3d);
}
