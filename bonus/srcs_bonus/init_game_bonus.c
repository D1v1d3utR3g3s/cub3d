/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:30:15 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/23 21:44:17 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic_bonus.h"

/* ************************************************************************** */
/*                                 init_game                                  */
/* -------------------------------------------------------------------------- */
/* This function initialises all the basics datas needed for events, colors,  */
/* textures.                                                                  */
/* If bonus apply then doors, minimap and anim are initialised                */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	init_game(t_c3d_data *c3d)
{
	init_event(&(c3d->event));
	init_col(c3d);
	init_textures(c3d);
	if (BONUS_DOOR)
		init_doors(c3d);
	if (BONUS_MINIMAP)
		init_minimap(c3d);
	if (BONUS_ANIM)
		init_anim(c3d);
	if (BONUS_MOUSE_CLICK)
	{
		c3d->mouse.mx = -1;
		c3d->mouse.my = -1;
		c3d->mouse.flag_press = 0;
	}
}
