/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:57:25 by roxane            #+#    #+#             */
/*   Updated: 2025/02/17 02:10:30 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/******************************************************************************/
/*                                  rot_dir                                   */
/* -------------------------------------------------------------------------- */
/* This function applies the rotation to the player in function of the given  */
/* direction ('L' left rotation, 'R' right rotation)                          */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/*  - char dir : the char associated to the rotation direction                */
/* Return :                                                                   */
/*  - None                                                                    */
/******************************************************************************/
void	rot_dir(t_c3d_data *c3d, char dir)
{
	if (dir == 'L')
		c3d->player.pa = update_angle(c3d->player.pa, -c3d->player.rot_speed);
	else if (dir == 'R')
		c3d->player.pa = update_angle(c3d->player.pa, c3d->player.rot_speed);
}

/******************************************************************************/
/*                                  rot_left                                  */
/* -------------------------------------------------------------------------- */
/* This function applies the rotation to the player (left direction)          */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - None                                                                    */
/******************************************************************************/
/*void	rot_left(t_c3d_data *c3d)
{
	c3d->player.pa -= c3d->player.rot_speed;
	if (c3d->player.pa < 0)
		c3d->player.pa += 2 * M_PI;
}*/

/******************************************************************************/
/*                                 rot_right                                  */
/* -------------------------------------------------------------------------- */
/* This function applies the rotation to the player (right direction)         */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - None                                                                    */
/******************************************************************************/
/*void	rot_right(t_c3d_data *c3d)
{
	c3d->player.pa += c3d->player.rot_speed;
	if (c3d->player.pa > 2 * M_PI)
		c3d->player.pa -= 2 * M_PI;
}*/
