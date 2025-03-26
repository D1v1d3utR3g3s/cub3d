/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:30:15 by rmorice          #+#    #+#             */
/*   Updated: 2025/03/23 18:17:14 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic.h"

/* ************************************************************************** */
/*                                 init_game                                  */
/* -------------------------------------------------------------------------- */
/* This function initialises all the basics datas needed for events, colors,  */
/* textures.                                                                  */
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
}
