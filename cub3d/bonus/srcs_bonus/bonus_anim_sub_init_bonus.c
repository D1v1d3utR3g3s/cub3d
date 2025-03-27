/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_anim_sub_init_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:55:36 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/27 14:59:46 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic_bonus.h"

/* ************************************************************************** */
/*                               sub_init_anim                                */
/* -------------------------------------------------------------------------- */
/* This function initialises sub anim datas associated to the distance        */
/* between the player and the anim and the positoion and orientation of the   */
/* animation                                                                  */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	sub_init_anim(t_c3d_data *c3d)
{
	c3d->anim.dist_anim = -1;
	init_id(c3d);
}
