/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:10:44 by hauerbac          #+#    #+#             */
/*   Updated: 2025/03/23 18:18:45 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic.h"

/******************************************************************************/
/*                                check_event                                 */
/* -------------------------------------------------------------------------- */
/* This function checks if an event ('w', 'a', 's', 'd', left arrow or right  */
/* arrow) had occured                                                         */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - 1 : if an event had occured                                             */
/*  - 0 : otherwise                                                           */
/******************************************************************************/
int	check_event(t_c3d_data *c3d)
{
	if (c3d->event.f_xk_w != 0)
		return (1);
	if (c3d->event.f_xk_a != 0)
		return (1);
	if (c3d->event.f_xk_s != 0)
		return (1);
	if (c3d->event.f_xk_d != 0)
		return (1);
	if (c3d->event.f_xk_left != 0)
		return (1);
	if (c3d->event.f_xk_right != 0)
		return (1);
	return (0);
}

/******************************************************************************/
/*                                  calc_dx                                   */
/* -------------------------------------------------------------------------- */
/* This function calculates the delta to apply on x axis for the movement     */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/*  - float dir_a : the delta angle associated to the movement                */
/* Return :                                                                   */
/*  - int : the delta to apply on x axis                                      */
/******************************************************************************/
int	calc_dx(t_c3d_data *c3d, float dir_a)
{
	return (cos(c3d->player.pa + dir_a) * c3d->player.mov_speed);
}

/******************************************************************************/
/*                                  calc_dy                                   */
/* -------------------------------------------------------------------------- */
/* This function calculates the delta to apply on y axis for the movement     */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/*  - float dir_a : the delta angle associated to the movement                */
/* Return :                                                                   */
/*  - int : the delta to apply on y axis                                      */
/******************************************************************************/
int	calc_dy(t_c3d_data *c3d, float dir_a)
{
	return (sin(c3d->player.pa + dir_a) * c3d->player.mov_speed);
}

/******************************************************************************/
/*                                calc_margin                                 */
/* -------------------------------------------------------------------------- */
/* This function returns the margin value to use to protect the movement      */
/* Input :                                                                    */
/*  - float d : the delta value (one axis) associated to the movement         */
/* Return :                                                                   */
/*  - int : the margin value to apply to protect the mvt (one axis)           */
/******************************************************************************/
int	calc_margin(float d)
{
	int	margin;

	margin = 25;
	if (d < 0)
		return (-margin);
	return (margin);
}

/******************************************************************************/
/*                                apply_event                                 */
/* -------------------------------------------------------------------------- */
/* This function applies the movement and rotation to the player              */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - None                                                                    */
/******************************************************************************/
void	apply_event(t_c3d_data *c3d)
{
	if ((c3d->event.f_xk_w != 0) && (c3d->event.f_xk_s == 0))
		move_dir(c3d, 'w');
	if ((c3d->event.f_xk_a != 0) && (c3d->event.f_xk_d == 0))
		move_dir(c3d, 'a');
	if ((c3d->event.f_xk_s != 0) && (c3d->event.f_xk_w == 0))
		move_dir(c3d, 's');
	if ((c3d->event.f_xk_d != 0) && (c3d->event.f_xk_a == 0))
		move_dir(c3d, 'd');
	if ((c3d->event.f_xk_left != 0) && (c3d->event.f_xk_right == 0))
		rot_dir(c3d, 'L');
	if ((c3d->event.f_xk_right != 0) && (c3d->event.f_xk_left == 0))
		rot_dir(c3d, 'R');
}
