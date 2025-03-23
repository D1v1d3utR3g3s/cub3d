/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mouse_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:02:39 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/23 21:36:35 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic_bonus.h"

// for now only right and left rotation
// for now, turn left if mx < w / 2
// for now, turn right if mx > w / 2
/* ************************************************************************** */
/*                                 mouse_mov                                  */
/* -------------------------------------------------------------------------- */
/* This function associates a view rotation to a mouse movement               */
/* Inputs :                                                                   */
/*  - int mx : mouse x coordinates                                            */
/*  - int my : mouse y coordinates                                            */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - 0 : needed for mlx_hook                                                 */
/* ************************************************************************** */
int	mouse_mov(int mx, int my, t_c3d_data *c3d)
{
	float	rot;

	(void)my;
	rot = c3d->player.rot_speed / 5;
	if (mx < c3d->mlx.w / 2)
	{
		c3d->player.pa = update_angle(c3d->player.pa, -rot);
		display_3d(c3d);
	}
	else if (mx > c3d->mlx.w / 2)
	{
		c3d->player.pa = update_angle(c3d->player.pa, rot);
		display_3d(c3d);
	}
	return (0);
}
