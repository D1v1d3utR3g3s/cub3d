/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:45:31 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/03 09:00:23 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/*                                check_hit_h                                 */
/* -------------------------------------------------------------------------- */
/* This function checks if the wall hitten is an horizontal one               */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - 1 : if the wall hitten is an horizontal one                             */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
static int	check_hit_h(t_c3d_data *c3d)
{
	if (c3d->ray.wall_dir == NORTH || c3d->ray.wall_dir == SOUTH)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                get_texture                                 */
/* -------------------------------------------------------------------------- */
/* This function returns the texture associated to the wall (or door) hitten  */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - t_mlx_img : the texture associated to the element hitten                */
/* ************************************************************************** */
static t_mlx_img	get_texture(t_c3d_data *c3d)
{
	if ((c3d->ray.hit_h_door && check_hit_h(c3d))
		|| (c3d->ray.hit_v_door && !check_hit_h(c3d)))
		return (c3d->m_col.tex_door);
	if (c3d->ray.wall_dir == NORTH)
		return (c3d->m_col.tex_no);
	if (c3d->ray.wall_dir == EAST)
		return (c3d->m_col.tex_ea);
	if (c3d->ray.wall_dir == SOUTH)
		return (c3d->m_col.tex_so);
	if (c3d->ray.wall_dir == WEST)
		return (c3d->m_col.tex_we);
	display_error("in select. texture to apply\n");
	clear_data(c3d);
	exit (1);
}

/* ************************************************************************** */
/*                             get_texture_color                              */
/* -------------------------------------------------------------------------- */
/* This function determines the color associated to a pixel on a wall         */
/* This color depends of the x coordinate (dx), the y coordinate and the      */
/* height of the wall that we want to colorise.                               */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - int y : the y coordinate of the tile                                    */
/*  - int dx : the x coordinate of the tile                                   */
/*  - int line_h : the height of the wall (for proportion purpose)            */
/* Return :                                                                   */
/*  - int : the color associated to the pixel                                 */
/* ************************************************************************** */
int	get_texture_color(t_c3d_data *c3d, int y, int dx, int line_h)
{
	int			dy;
	int			dist_to_top;
	t_mlx_img	tmp;
	int			col;

	tmp = get_texture(c3d);
	dist_to_top = y + (line_h - c3d->mlx.h) / 2;
	dy = dist_to_top * tmp.height / line_h;
	col = *(int *)(tmp.addr + (dy * tmp.line_len + dx * tmp.bpp / 8));
	if (col == NO_COL)
		return (-1);
	return (col);
}

/* ************************************************************************** */
/*                             determine_offset_x                             */
/* -------------------------------------------------------------------------- */
/* This function determines the offset_x to apply to the x axis in function   */
/* of the direction of the wall                                               */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - int : the offset to apply                                               */
/* ************************************************************************** */
static int	determine_offset_x(t_c3d_data *c3d)
{
	int	offset_x;

	offset_x = 0;
	if (c3d->ray.wall_dir == NORTH)
		offset_x = (int)c3d->ray.rx % c3d->m_col.tex_no.width;
	else if (c3d->ray.wall_dir == SOUTH)
	{
		offset_x = (int)c3d->ray.rx % c3d->m_col.tex_so.width;
		offset_x = c3d->m_col.tex_so.width - offset_x;
	}
	else if (c3d->ray.wall_dir == EAST)
		offset_x = (int)c3d->ray.ry % c3d->m_col.tex_ea.width;
	else if (c3d->ray.wall_dir == WEST)
	{
		offset_x = (int)c3d->ray.ry % c3d->m_col.tex_we.width;
		offset_x = c3d->m_col.tex_we.width - offset_x;
	}
	return (offset_x);
}

/* ************************************************************************** */
/*                           extract_slice_tex                            */
/* -------------------------------------------------------------------------- */
/* This function updates a wall slice by updating the color array associated  */
/* Inputs :                                                                   */
/*  - t_mlx *mlx : a pointer to a structure that contained mlx usefull elt    */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - int x : x coordinate                                                    */
/*  - int line_h : wall height associated to this slice                       */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	extract_slice_tex(t_mlx *mlx, t_c3d_data *c3d, int x, int line_h)
{
	int	init_y;
	int	end_y;
	int	offset_x;
	int	col;

	init_y = (mlx->h - line_h) / 2;
	if (init_y < 0)
		init_y = 0;
	end_y = (mlx->h + line_h) / 2;
	if (end_y > mlx->h)
		end_y = mlx->h;
	offset_x = determine_offset_x(c3d);
	while (init_y <= end_y)
	{
		if (init_y >= 0 && init_y <= mlx->h)
		{
			col = get_color(c3d, init_y, offset_x, line_h);
			c3d->m_col.col[init_y * mlx->w + x] = col;
		}
		init_y++;
	}
}
