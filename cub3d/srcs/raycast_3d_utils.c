/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_3d_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:15:38 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/17 02:30:44 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/*                              update_line_col                               */
/* -------------------------------------------------------------------------- */
/* This function    */
/* Inputs :                                                                   */
/*  -      */
/*  -      */
/*  -      */
/*  -      */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	update_line_col(int ray_nb, float offset, float line_h, t_c3d_data *c3d)
{
	int		i;
	float	y;
	float	dy;
	float	nb_point;

	i = 0;
	nb_point = sqrt(line_h * line_h);
	dy = line_h / nb_point;
	while (i <= nb_point)
	{
		y = offset + dy * i;
		if (y < 0)
			y = 0;
		else if (y > c3d->mlx.h)
			y = c3d->mlx.h - 1;
		c3d->m_col.col[(int)(y * c3d->mlx.w + ray_nb)] = c3d->ray.col_wall;
		i++;
	}
}

/* ************************************************************************** */
/*                             update_3D_line_col                             */
/* -------------------------------------------------------------------------- */
/* This function    */
/* Inputs :                                                                   */
/*  -      */
/*  -      */
/*  -      */
/*  -      */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
// ray_nb, offset, ray_nb, offset + line_h, c3d
void	update_3d_line_col(int beginX, int beginY, int endX, int endY, t_c3d_data *c3d)
{
	int		i;
	int		id;
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	nb_point;

	i = 0;
	dx = (endX - beginX);
	dy = (endY - beginY);
	nb_point = sqrt(dx * dx + dy * dy);
	dx = dx / nb_point;
	dy = dy / nb_point;
	while (i <= nb_point)
	{
		x = beginX + dx * i;
		if (x < 0)
			x = 0;
		else if (x > c3d->mlx.w)
			x = c3d->mlx.w - 1;
		y = beginY + dy * i;
		if (y < 0)
			y = 0;
		else if (y > c3d->mlx.h)
			y = c3d->mlx.h - 1;
		id = y * c3d->mlx.w + x;
		c3d->m_col.col[id] = c3d->ray.col_wall;
		i++;
	}
}
