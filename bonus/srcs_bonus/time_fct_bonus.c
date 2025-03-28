/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_fct_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:26:18 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/23 21:48:42 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic_bonus.h"

/* ************************************************************************** */
/*                                 gettime_in                                 */
/* -------------------------------------------------------------------------- */
/* This function gets the time converted in the unity specified (s, ms, us)   */
/* Input :                                                                    */
/*  - t_unity_time unity : the unity in which we want to convert the time     */
/*  - t_c3d_data *c3d : the structure that contained general datas            */
/* Return :                                                                   */
/*  - long : the current time convert in unity                                */
/* ************************************************************************** */
long	gettime_in(t_unity_time unity, t_c3d_data *c3d)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		err_clear_exit("Error when converting time.\n", c3d);
	if (unity == SECONDS)
		return (tv.tv_sec + tv.tv_usec / 1e6);
	if (unity == MILLISECONDS)
		return (tv.tv_sec * 1e3 + tv.tv_usec / 1e3);
	if (unity == MICROSECONDS)
		return (tv.tv_sec * 1e6 + tv.tv_usec);
	else
		err_clear_exit("Error with the unity given to gettime_in.\n", c3d);
	return (-42);
}
