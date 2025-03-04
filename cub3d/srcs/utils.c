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
/*                                   calc_d                                   */
/* -------------------------------------------------------------------------- */
/* This function calculates the distance between a(ax, ay) and b(bx, by)      */
/* rq : ab is the hypothenus                                                  */
/* Inputs :                                                                   */
/*  - float ax : the x coordinate of a                                        */
/*  - float ay : the y coordinate of a                                        */
/*  - float bx : the x coordinate of b                                        */
/*  - float by : the y coordinate of b                                        */
/* Return :                                                                   */
/*  - float : the size of the hypothenus connecting a and b                   */
/* ************************************************************************** */
float	calc_d(float ax, float ay, float bx, float by)
{
	return (sqrt(pow((bx - ax), 2) + pow((by - ay), 2)));
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

/* ************************************************************************** */
/*                                 rad_to_deg                                 */
/* -------------------------------------------------------------------------- */
/* This function cconverts the radian angle given in input into an angle in   */
/* deg                                                                        */
/* Input :                                                                    */
/*  - float rad : the angle to convert                                        */
/* Return :                                                                   */
/*  - float : the converted angle                                             */
/* ************************************************************************** */
float	rad_to_deg(float rad)
{
	return (rad * 180 / M_PI);
}

/* ************************************************************************** */
/*                                 deg_to_rad                                 */
/* -------------------------------------------------------------------------- */
/* This function cconverts the degree angle given in input into an angle in   */
/* radian                                                                     */
/* Input :                                                                    */
/*  - float deg : the angle to convert                                        */
/* Return :                                                                   */
/*  - float : the converted angle                                             */
/* ************************************************************************** */
float	deg_to_rad(float deg)
{
	return (deg * M_PI / 180);
}
