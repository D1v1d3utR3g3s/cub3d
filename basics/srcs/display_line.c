/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:48:30 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/11 14:55:05 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/* ************************************************************************** */
void	draw_point_line(t_c3d_data *c3d, int beginX, int beginY, int endX,
			int endY, int col)
{
	int		i;
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	nb_point;

	i = 0;
	nb_point = sqrt((endX - beginX) * (endX - beginX) \
			+ (endY - beginY) * (endY - beginY)) / 10;
	dx = (endX - beginX) / nb_point;
	dy = (endY - beginY) / nb_point;
	while (i <= nb_point)
	{
		x = beginX + dx * i;
		if (x < 0)
			x = 0;
		else if (x > c3d->grid.nb_tile_x * c3d->grid.w_tile)
			x = c3d->grid.nb_tile_x * c3d->grid.w_tile;
		y = beginY + dy * i;
		if (y < 0)
			y = 0;
		else if (y > c3d->grid.nb_tile_y * c3d->grid.w_tile)
			y = c3d->grid.nb_tile_y * c3d->grid.w_tile;
		img_pix_put(&c3d->img_ptr, x, y, col);
		i++;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
void	draw_full_line(t_c3d_data *c3d, int beginX, int beginY, int endX,
			int endY, int col)
{
	int		i;
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	nb_point;

	i = 0;
	nb_point = sqrt((endX - beginX) * (endX - beginX) \
			+ (endY - beginY) * (endY - beginY));
	dx = (endX - beginX) / nb_point;
	dy = (endY - beginY) / nb_point;
	while (i <= nb_point)
	{
		x = beginX + dx * i;
		if (x < 0)
			x = 0;
		else if (x > c3d->grid.nb_tile_x * c3d->grid.w_tile)
			x = c3d->grid.nb_tile_x * c3d->grid.w_tile;
		y = beginY + dy * i;
		if (y < 0)
			y = 0;
		else if (y > c3d->grid.nb_tile_y * c3d->grid.w_tile)
			y = c3d->grid.nb_tile_y * c3d->grid.w_tile;
		img_pix_put(&c3d->img_ptr, x, y, col);
		i++;
	}
}
