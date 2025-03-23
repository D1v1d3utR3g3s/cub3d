/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:57:25 by roxane            #+#    #+#             */
/*   Updated: 2025/03/23 18:19:13 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic.h"

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
