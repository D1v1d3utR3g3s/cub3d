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

// BONUS_MOUSE
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

// BONUS_MOUSE_CLICK
/* ************************************************************************** */
/*                               rot_dir_mouse                                */
/* -------------------------------------------------------------------------- */
/* This function rotates the view depending of the position of the mouse on   */
/* the x axis compare to the position of the mouse when the user clicks (left */
/* click)                                                                     */
/* rq : if the user is already rotating the view with the array keys then no  */
/* add rotation is done.                                                      */
/* rq2 : this function is called only if the mouse left click is still down   */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - 0 : needed for mlx_hook                                                 */
/* ************************************************************************** */
void	rot_dir_mouse(t_c3d_data *c3d)
{
	float	rot;
	int		mx;
	int		my;

	if ((c3d->event.f_xk_left != 0) || (c3d->event.f_xk_right != 0))
		return ;
	rot = c3d->player.rot_speed;
	mlx_mouse_get_pos(c3d->mlx.mlx_ptr, c3d->mlx.win_ptr, &mx, &my);
	if ((mx != -1) && (mx < c3d->mouse.mx))
	{
		c3d->player.pa = update_angle(c3d->player.pa, -rot);
		display_3d(c3d);
	}
	else if ((mx != -1) && (mx > c3d->mouse.mx))
	{
		c3d->player.pa = update_angle(c3d->player.pa, rot);
		display_3d(c3d);
	}
}

/* ************************************************************************** */
/*                                   click                                    */
/* -------------------------------------------------------------------------- */
/* This function updates the reference x and y coordinates of the mouse and   */
/* set the flag_press to '1' if the button pressed is the mouse's left click  */
/* Inputs :                                                                   */
/*  - int button : the id associated of the "mouse button" clicked            */
/*  - int mx : mouse x coordinates                                            */
/*  - int my : mouse y coordinates                                            */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - 0 : needed for mlx_hook                                                 */
/* ************************************************************************** */
int	click(int button, int mx, int my, t_c3d_data *c3d)
{
	if (button == 1)
	{
		c3d->mouse.mx = mx;
		c3d->mouse.my = my;
		c3d->mouse.flag_press = 1;
	}
	return (0);
}

/* ************************************************************************** */
/*                                  unclick                                   */
/* -------------------------------------------------------------------------- */
/* This function updates set the flag_press to '0' if the button released is  */
/* the mouse's left click                                                     */
/* Inputs :                                                                   */
/*  - int button : the id associated of the "mouse button" released           */
/*  - int mx : mouse x coordinates                                            */
/*  - int my : mouse y coordinates                                            */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - 0 : needed for mlx_hook                                                 */
/* ************************************************************************** */
int	unclick(int button, int mx, int my, t_c3d_data *c3d)
{
	(void)mx;
	(void)my;
	if (button == 1)
		c3d->mouse.flag_press = 0;
	return (0);
}
