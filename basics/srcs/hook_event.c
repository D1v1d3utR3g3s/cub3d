/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:13:56 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/11 16:55:07 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/*                                key_handler                                 */
/* -------------------------------------------------------------------------- */
/* This function defines what will happened when some specifics key are       */
/* pressed (Esc, arrows, and in my case '+' and '-' as well as Space)         */
/* Inputs :                                                                   */
/*  - int keysym : abstract representation of the key (regardless hardware)   */
/*  - t_c3d_data *c3d : a pointer to a structure                              */
/* Return :                                                                   */
/*  - int : 0 (int needed for corresponding to the prototype)                 */
/* ************************************************************************** */
static int	key_handler(int keysym, t_c3d_data *c3d)
{
	if (keysym == XK_Escape)
	{
		clear_data(c3d);
		exit (0);
	}
	if (is_key_wasd(keysym))
	{
		keys_wasd(keysym, c3d);
		full_img(c3d);
	}
	if (is_key_array(keysym))
	{
		keys_array(keysym, c3d);
		full_img(c3d);
	}
	return (0);
}

/* ************************************************************************** */
/*                               close_handler                                */
/* -------------------------------------------------------------------------- */
/* This function links the close the window in a clean way when the cross     */
/* button is clicked                                                          */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : a pointer to a structure                              */
/* Return :                                                                   */
/*  - int : 0 (int needed for corresponding to the prototype)                 */
/* ************************************************************************** */
static int	close_handler(t_c3d_data *c3d)
{
	clear_data(c3d);
	exit (0);
	return (0);
}

/* ************************************************************************** */
/*                                 hook_event                                 */
/* -------------------------------------------------------------------------- */
/* This function links an action to an event (key, mouse, button)             */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : a pointer to a structure                              */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	hook_event(t_c3d_data *c3d)
{
	mlx_hook(c3d->win_ptr, KeyPress, KeyPressMask, key_handler, c3d);
	mlx_hook(c3d->win_ptr, DestroyNotify, StructureNotifyMask,
		close_handler, c3d);
}
