/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:31:55 by hauerbac          #+#    #+#             */
/*   Updated: 2025/03/04 15:19:40 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/*                              check_in_window                               */
/* -------------------------------------------------------------------------- */
/* This function checks if the pixel (x, y) is in the window                  */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - int x : x coordinate to check                                           */
/*  - int y : y coordinate to check                                           */
/* Return :                                                                   */
/*  - 1 : if pixel (x, y) is in the window                                    */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
int	check_in_window(t_c3d_data *c3d, int x, int y)
{
	if ((x < 0) || (x >= c3d->maze.nb_col * c3d->maze.w_tile))
		return (0);
	if ((y < 0) || (y >= c3d->maze.nb_line * c3d->maze.w_tile))
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                 face_down                                  */
/* -------------------------------------------------------------------------- */
/* This function checks if the radian angle given correspond to one that      */
/* pointed downward                                                           */
/* Input :                                                                    */
/*  - float rad : the angle to check                                          */
/* Return :                                                                   */
/*  - 1 : if the given angle correspond to pointing downward                  */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
int	face_down(float rad)
{
	if (rad < M_PI)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                 face_right                                 */
/* -------------------------------------------------------------------------- */
/* This function checks if the radian angle given correspond to one that      */
/* pointed toward right                                                       */
/* Input :                                                                    */
/*  - float rad : the angle to check                                          */
/* Return :                                                                   */
/*  - 1 : if the given angle correspond to pointing toward right              */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
int	face_right(float rad)
{
	if (rad < M_PI / 2 || rad > 3 * M_PI / 2)
		return (1);
	return (0);
}
