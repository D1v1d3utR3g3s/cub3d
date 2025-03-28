/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_doors_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:13:41 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/23 21:35:11 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic_bonus.h"

/* ************************************************************************** */
/*                               init_doors_val                               */
/* -------------------------------------------------------------------------- */
/* This function initialises the distance between each door and the player to */
/* -1                                                                         */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	init_doors_val(t_c3d_data *c3d)
{
	int	i;

	i = 0;
	while (i < c3d->doors.size)
	{
		c3d->doors.dist[i] = -1;
		i++;
	}
}

/* ************************************************************************** */
/*                                 init_doors                                 */
/* -------------------------------------------------------------------------- */
/* This function initialises doors datas                                      */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	init_doors(t_c3d_data *c3d)
{
	c3d->doors.size = c3d->maze.nb_col * c3d->maze.nb_line;
	c3d->doors.dist = malloc(sizeof(int) * c3d->doors.size);
	if (!c3d->doors.dist)
		err_clear_exit("malloc for doors array", c3d);
	init_doors_val(c3d);
}

/* ************************************************************************** */
/*                                update_doors                                */
/* -------------------------------------------------------------------------- */
/* This function updates doors distance with player to d if d < to currently  */
/* saved distance                                                             */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - int mp : the index of the door to update (if needed)                    */
/*  - int d : the new distance to check and/or saved                          */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	update_doors(t_c3d_data *c3d, int mp, int d)
{
	int	dist;

	dist = c3d->doors.dist[mp];
	if (dist == -1 || dist > d)
		c3d->doors.dist[mp] = d;
}

/* ************************************************************************** */
/*                               action_on_door                               */
/* -------------------------------------------------------------------------- */
/* This function is called when a specific action is trigger. It opens or     */
/* closes every door(s) that is(/are) closer than 50 to the player            */
/* The display is then update                                                 */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	action_on_door(t_c3d_data *c3d)
{
	int	i;

	i = 0;
	while (i < c3d->doors.size)
	{
		if (c3d->doors.dist[i] != -1)
		{
			if (c3d->doors.dist[i] > 5 && c3d->doors.dist[i] < 50)
			{
				if (c3d->maze.map[i] == '2')
					c3d->maze.map[i] = '3';
				else if (c3d->maze.map[i] == '3')
					c3d->maze.map[i] = '2';
			}
		}
		i++;
	}
	display_3d(c3d);
}
