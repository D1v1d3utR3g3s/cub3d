/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:31:55 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/23 22:09:09 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic.h"

/* ************************************************************************** */
/*                                  rand_int                                  */
/* -------------------------------------------------------------------------- */
/* This function generates a random value contained between min and max       */
/* (include)                                                                  */
/* rq : a seed is define using the current time to simulate a 'real' random   */
/* Inputs :                                                                   */
/*  - int min : the minimum value contained in the allow range                */
/*  - int max : the maximum value contained in the allow range                */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - int : the int value generated "randomly"                                */
/* ************************************************************************** */
int	rand_int(int min, int max, t_c3d_data *c3d)
{
	int	n;

	srand(gettime_in(MILLISECONDS, c3d));
	n = (int)(rand() % (max - min + 1)) + min;
	return (n);
}

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
