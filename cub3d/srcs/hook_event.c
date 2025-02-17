/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:13:56 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/17 00:59:28 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/*                             key_handler_press                              */
/* -------------------------------------------------------------------------- */
/* This function updates the flags associated to some specifics pressed keys  */
/* (left and right arrows, and 'w', 'a', 's', 'd')                            */
/* Or clean and exit the game when the Esc key is pressed                     */
/* Inputs :                                                                   */
/*  - int keysym : abstract representation of the key (regardless hardware)   */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - int : 0 (int needed for corresponding to the prototype)                 */
/* ************************************************************************** */
static int	key_handler_press(int keysym, t_c3d_data *c3d)
{
	if (keysym == XK_Escape)
	{
		clear_data(c3d);
		exit(1);
	}
	if (keysym == XK_W || keysym == XK_w)
		c3d->event.f_XK_W = 1;
	if (keysym == XK_A || keysym == XK_a)
		c3d->event.f_XK_A = 1;
	if (keysym == XK_S || keysym == XK_s)
		c3d->event.f_XK_S = 1;
	if (keysym == XK_D || keysym == XK_d)
		c3d->event.f_XK_D = 1;
	if (keysym == XK_Left)
		c3d->event.f_XK_Left = 1;
	if (keysym == XK_Right)
		c3d->event.f_XK_Right = 1;
	return (0);
}

/* ************************************************************************** */
/*                              key_handler_rel                               */
/* -------------------------------------------------------------------------- */
/* This function updates the flags associated to some specifics release keys  */
/* (left and right arrows, and 'w', 'a', 's', 'd')                            */
/* Or clean and exit the game when the Esc key is released                    */
/* Inputs :                                                                   */
/*  - int keysym : abstract representation of the key (regardless hardware)   */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - int : 0 (int needed for corresponding to the prototype)                 */
/* ************************************************************************** */
static int	key_handler_rel(int keysym, t_c3d_data *c3d)
{
	if (keysym == XK_Escape)
	{
		clear_data(c3d);
		exit(1);
	}
	if (keysym == XK_W || keysym == XK_w)
		c3d->event.f_XK_W = 0;
	if (keysym == XK_A || keysym == XK_a)
		c3d->event.f_XK_A = 0;
	if (keysym == XK_S || keysym == XK_s)
		c3d->event.f_XK_S = 0;
	if (keysym == XK_D || keysym == XK_d)
		c3d->event.f_XK_D = 0;
	if (keysym == XK_Left)
		c3d->event.f_XK_Left = 0;
	if (keysym == XK_Right)
		c3d->event.f_XK_Right = 0;
	return (0);
}

/* ************************************************************************** */
/*                                 hook_event                                 */
/* -------------------------------------------------------------------------- */
/* This function links an action to an event (key, mouse, button)             */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	hook_event(t_c3d_data *c3d)
{
	t_mlx	*mlx;

	mlx = &(c3d->mlx);
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, key_handler_press, c3d);
	mlx_hook(mlx->win_ptr, KeyRelease, KeyReleaseMask, key_handler_rel, c3d);
	mlx_hook(mlx->win_ptr, DestroyNotify, StructureNotifyMask,
		close_handler, c3d);
}
