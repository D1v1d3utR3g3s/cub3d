/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:53:20 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/23 21:36:00 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic_bonus.h"

/* ************************************************************************** */
/*                             determine_col_map                              */
/* -------------------------------------------------------------------------- */
/* This function determines the color associated to id. If id is on maze then */
/* the color depends of the value associated to id on maze.                   */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - int id : id to check and/or use to check on maze                        */
/* Return :                                                                   */
/*  - int : the color to associate to id                                      */
/* ************************************************************************** */
static int	determine_col_from_maze(t_c3d_data *c3d, int id)
{
	if (id < 0 || id >= c3d->maze.nb_col * c3d->maze.nb_line)
		return (encode_rgb(65, 65, 65));
	if (c3d->maze.map[id] == '0')
		return (encode_rgb(125, 125, 125));
	if (c3d->maze.map[id] == '1')
		return (encode_rgb(175, 175, 175));
	if (c3d->maze.map[id] == '2' || c3d->maze.map[id] == '3')
		return (encode_rgb(25, 155, 125));
	if (c3d->maze.map[id] == '_')
		return (encode_rgb(65, 65, 65));
	return (encode_rgb(0, 0, 0));
}

/* ************************************************************************** */
/*                             determine_col_map                              */
/* -------------------------------------------------------------------------- */
/* This function determines the color to associate to pix (mmx, mmy)          */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - int mmx : x coordinate to check                                         */
/*  - int mmy : y coordinate to check                                         */
/* Return :                                                                   */
/*  - int : the color to associate to pix (mmx, mmy)                          */
/* ************************************************************************** */
static int	determine_col_map(t_c3d_data *c3d, int mmx, int mmy)
{
	t_minimap	*mmp;
	int			id;
	int			y;
	int			x;

	mmp = &(c3d->min_map);
	x = (int)((mmx * mmp->coef - mmp->mmp_dx));
	y = (int)((mmy * mmp->coef - mmp->mmp_dy));
	id = (int)(y / c3d->maze.w_tile) * c3d->maze.nb_col;
	id += (int)(x / c3d->maze.w_tile);
	if (is_on_border_minmap(c3d, mmp->mmp_x, mmp->mmp_y))
		return (encode_rgb(0, 0, 0));
	if (is_outside_map(c3d, x, y))
		return (encode_rgb(65, 65, 65));
	if (is_player(c3d, mmp->mmp_x, mmp->mmp_y))
		return (encode_rgb(255, 0, 0));
	return (determine_col_from_maze(c3d, id));
}

/* ************************************************************************** */
/*                             update_minimap_col                             */
/* -------------------------------------------------------------------------- */
/* This function updates the color array values associated to minimap pixels  */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	update_minimap_col(t_c3d_data *c3d)
{
	t_minimap	*mmp;
	int			col;
	int			id;

	mmp = &(c3d->min_map);
	mmp->mmp_dx = -(c3d->player.px - (mmp->mmp_px * mmp->coef));
	mmp->mmp_dy = -(c3d->player.py - (mmp->mmp_py * mmp->coef));
	mmp->mmp_y = 0;
	while (mmp->mmp_y < mmp->h)
	{
		mmp->mmp_x = 0;
		while (mmp->mmp_x < mmp->w)
		{
			col = determine_col_map(c3d, mmp->mmp_x, mmp->mmp_y);
			id = (mmp->mmp_y + mmp->y0) * c3d->mlx.w + (mmp->mmp_x + mmp->x0);
			if (id >= 0 && id < c3d->mlx.w * c3d->mlx.h)
				c3d->m_col.col[id] = col;
			mmp->mmp_x++;
		}
		mmp->mmp_y++;
	}
}

/* ************************************************************************** */
/*                                init_minimap                                */
/* -------------------------------------------------------------------------- */
/* This function initialises minimap datas                                    */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	init_minimap(t_c3d_data *c3d)
{
	t_minimap	*mmp;

	mmp = &(c3d->min_map);
	mmp->x0 = 10;
	mmp->y0 = 10;
	mmp->w = c3d->mlx.w / 4;
	mmp->h = c3d->mlx.h / 4;
	mmp->coef = calc_coef(c3d, mmp);
	mmp->w_tile = c3d->maze.w_tile / mmp->coef;
	mmp->mmp_x = 0;
	mmp->mmp_y = 0;
	mmp->mmp_px = mmp->w * 1 / 2;
	mmp->mmp_py = mmp->h * 3 / 4;
	mmp->mmp_dx = -(c3d->player.px - mmp->mmp_px * mmp->coef);
	mmp->mmp_dy = -(c3d->player.py - mmp->mmp_py * mmp->coef);
}
