/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:23:30 by roxane            #+#    #+#             */
/*   Updated: 2025/03/03 21:31:50 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/*                                 encode_rgb                                 */
/* -------------------------------------------------------------------------- */
/* This function converts a RGB value into an integer                         */
/* Inputs :                                                                   */
/*  - u_int8_t red : the Red value of the color wanted                        */
/*  - u_int8_t green : the Green value of the color wanted                    */
/*  - u_int8_t blue : the Blue value of the color wanted                      */
/* Return :                                                                   */
/*  - int : the integer that correspond to the color defined with RGB         */
/* ************************************************************************** */
int	encode_rgb(u_int8_t red, u_int8_t green, u_int8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

/* ************************************************************************** */
/*                               determine_col                                */
/* -------------------------------------------------------------------------- */
/* This function converts a RGB value into an integer                         */
/* Inputs :                                                                   */
/*  - int x : the x coordinate of the pixel for which we want the color       */
/*  - int y : the y coordinate of the pixel for which we want the color       */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - int : the color to associate to the pixel with coordinate (x, y)        */
/* ************************************************************************** */
int	determine_col(int x, int y, t_c3d_data *c3d)
{
	int	col;
	int	id;

	id = y * c3d->mlx.w + x;
	if (c3d->m_col.col[id] != -1)
	{
		col = c3d->m_col.col[id];
		c3d->m_col.col[id] = -1;
		return (col);
	}
	else if (y < c3d->mlx.h / 2)
		return (c3d->m_col.c);
	else if (y < c3d->mlx.h - 1)
		return (c3d->m_col.f);
	else
		return (c3d->m_col.background);
}
