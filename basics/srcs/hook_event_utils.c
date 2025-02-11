/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:10:44 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/11 15:12:55 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/* ************************************************************************** */
void	keys_wasd(int keysym, t_c3d_data *c3d)
{
	if (keysym == XK_W || keysym == XK_w)
	{
		c3d->player.px += c3d->player.dx;
		c3d->player.py += c3d->player.dy;
	}
	else if (keysym == XK_A || keysym == XK_a)
	{
		c3d->player.px += cos(c3d->player.pa - (M_PI / 2)) * 5;
		c3d->player.py += sin(c3d->player.pa - (M_PI / 2)) * 5;
	}
	else if (keysym == XK_S || keysym == XK_s)
	{
		c3d->player.px -= c3d->player.dx;
		c3d->player.py -= c3d->player.dy;
	}
	else if (keysym == XK_D || keysym == XK_d)
	{
		c3d->player.px += cos(c3d->player.pa + (M_PI / 2)) * 5;
		c3d->player.py += sin(c3d->player.pa + (M_PI / 2)) * 5;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
int	is_key_wasd(int keysym)
{
	if (keysym == XK_W || keysym == XK_w)
		return (1);
	if (keysym == XK_A || keysym == XK_a)
		return (1);
	if (keysym == XK_S || keysym == XK_s)
		return (1);
	if (keysym == XK_D || keysym == XK_d)
		return (1);
	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */
void	keys_array(int keysym, t_c3d_data *c3d)
{
	if (keysym == XK_Up)
	{
		c3d->player.px += c3d->player.dx;
		c3d->player.py += c3d->player.dy;
	}
	else if (keysym == XK_Down)
	{
		c3d->player.px -= c3d->player.dx;
		c3d->player.py -= c3d->player.dy;
	}
	else if (keysym == XK_Left)
	{
		c3d->player.pa -= 0.1;
		if (c3d->player.pa < 0)
			c3d->player.pa += 2 * M_PI;
		c3d->player.dx = cos(c3d->player.pa) * 5;
		c3d->player.dy = sin(c3d->player.pa) * 5;
	}
	else if (keysym == XK_Right)
	{
		c3d->player.pa += 0.1;
		if (c3d->player.pa > 2 * M_PI)
			c3d->player.pa -= 2 * M_PI;
		c3d->player.dx = cos(c3d->player.pa) * 5;
		c3d->player.dy = sin(c3d->player.pa) * 5;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
int	is_key_array(int keysym)
{
	if (keysym == XK_Up)
		return (1);
	if (keysym == XK_Down)
		return (1);
	if (keysym == XK_Left)
		return (1);
	if (keysym == XK_Right)
		return (1);
	return (0);
}
