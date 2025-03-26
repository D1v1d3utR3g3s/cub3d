/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:13:56 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/23 21:41:48 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic_bonus.h"

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
		exit(0);
	}
	if (keysym == XK_W || keysym == XK_w)
		c3d->event.f_xk_w = 1;
	if (keysym == XK_A || keysym == XK_a)
		c3d->event.f_xk_a = 1;
	if (keysym == XK_S || keysym == XK_s)
		c3d->event.f_xk_s = 1;
	if (keysym == XK_D || keysym == XK_d)
		c3d->event.f_xk_d = 1;
	if (keysym == XK_Left)
		c3d->event.f_xk_left = 1;
	if (keysym == XK_Right)
		c3d->event.f_xk_right = 1;
	if (BONUS_DOOR && keysym == XK_space)
		action_on_door(c3d);
	if (BONUS_ANIM && (keysym == XK_I || keysym == XK_i))
		display_anim_infos(c3d);
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
		exit(0);
	}
	if (keysym == XK_W || keysym == XK_w)
		c3d->event.f_xk_w = 0;
	if (keysym == XK_A || keysym == XK_a)
		c3d->event.f_xk_a = 0;
	if (keysym == XK_S || keysym == XK_s)
		c3d->event.f_xk_s = 0;
	if (keysym == XK_D || keysym == XK_d)
		c3d->event.f_xk_d = 0;
	if (keysym == XK_Left)
		c3d->event.f_xk_left = 0;
	if (keysym == XK_Right)
		c3d->event.f_xk_right = 0;
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
	if (BONUS_MOUSE_CLICK)
	{
		mlx_hook(mlx->win_ptr, ButtonPress, ButtonPressMask, click, c3d);
		mlx_hook(mlx->win_ptr, ButtonRelease, ButtonReleaseMask, unclick, c3d);
	}
	if (BONUS_MOUSE && !BONUS_MOUSE_CLICK)
	{
		mlx_hook(mlx->win_ptr, MotionNotify, PointerMotionMask, mouse_mov, c3d);
	}
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, key_handler_press, c3d);
	mlx_hook(mlx->win_ptr, KeyRelease, KeyReleaseMask, key_handler_rel, c3d);
	mlx_hook(mlx->win_ptr, DestroyNotify, StructureNotifyMask,
		close_handler, c3d);
}
