/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:35:07 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/11 15:39:44 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/* ************************************************************************** */
void	draw_3D_line(t_c3d_data *c3d, int beginX, int beginY, int endX,
			int endY, int col)
{
	int		i;
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	nb_point;

	i = 0;
	nb_point = sqrt((endX - beginX) * (endX - beginX) + (endY - beginY) \
			* (endY - beginY));
	dx = (endX - beginX) / nb_point;
	dy = (endY - beginY) / nb_point;
	while (i <= nb_point)
	{
		x = beginX + dx * i;
		if (x < 0)
			x = 0;
		else if (x > c3d->w)
			x = c3d->w;
		y = beginY + dy * i;
		if (y < 0)
			y = 0;
		else if (y > c3d->h)
			y = c3d->h;
		img_pix_put(&c3d->img_ptr, x, y, col);
		i++;
	}
}

void	draw3D(t_c3d_data *c3d, int r)
{
	float	lineH;
	float	offset;
	float	angle_offset;
	int		i;

	angle_offset = update_angle(c3d->player.pa, -c3d->ray.ra);
	lineH = (64 * 320) / (c3d->ray.dist_wall * cos(angle_offset));
	if (lineH > 320)
		lineH = 320;
	if (lineH < 0)
	{
		printf("no height\n");
		lineH = 0;
	}
	offset = 160 - lineH / 2;
	i = 0;
	while (i < 8)
	{
		draw_3D_line(c3d, 530 + 8 * r + i, 0 + offset, 530 + 8 * r + i,
			lineH + offset, c3d->ray.col_wall);
		i++;
	}
}
