/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event_close_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roxane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:10:42 by roxane            #+#    #+#             */
/*   Updated: 2025/03/23 21:42:11 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic_bonus.h"

/* ************************************************************************** */
/*                               close_handler                                */
/* -------------------------------------------------------------------------- */
/* This function links the close the window in a clean way when the cross     */
/* button is clicked                                                          */
/* Inputs :                                                                   */
/*  - t_data *data : a pointer to a structure that contained freeable datas   */
/* Return :                                                                   */
/*  - int : 0 (int needed for corresponding to the prototype)                 */
/* ************************************************************************** */
int	close_handler(t_c3d_data *c3d)
{
	char	*col;

	col = "\033[32m";
	if (c3d->anim.score == 0)
		col = "\033[31m";
	printf("%sYour score is : %d\033[0m\n", col, c3d->anim.score);
	clear_data(c3d);
	exit(0);
	return (0);
}
