/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:23:30 by roxane            #+#    #+#             */
/*   Updated: 2025/03/23 18:09:53 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic.h"

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
/* This function determines the the color to associate to the pixel (x, y)    */
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

/* ************************************************************************** */
/*                                 get_color                                  */
/* -------------------------------------------------------------------------- */
/* This function determines the color associated to a pixel on a wall         */
/* This color depends of the x coordinate (dx), the y coordinate and the      */
/* height of the wall that we want to colorise.                               */
/* rq : the color associated to anime sprite is return if anim bonus is on,   */
/* that the coord correspond to the animated wall and that the col isn't void */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - int y : the y coordinate of the tile                                    */
/*  - int dx : the x coordinate of the tile                                   */
/*  - int line_h : the height of the wall (for proportion purpose)            */
/* Return :                                                                   */
/*  - int : the color associated to the pixel                                 */
/* ************************************************************************** */
int	get_color(t_c3d_data *c3d, int init_y, int offset_x, int line_h)
{
	int	col;
	int	col_anim;

	col = get_texture_color(c3d, init_y, offset_x, line_h);
	if (BONUS_ANIM)
	{
		if (c3d->anim.wall_id == calc_mp(&(c3d->ray), c3d))
		{
			col_anim = get_anim_color(c3d, init_y, offset_x, line_h);
			if (col_anim != NO_COL)
				col = col_anim;
		}
	}
	return (col);
}
