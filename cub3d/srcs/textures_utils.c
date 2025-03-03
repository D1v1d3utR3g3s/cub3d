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

t_mlx_img	get_texture(t_c3d_data *c3d)
{
	if (c3d->ray.wall_dir == NORTH)
		return (c3d->m_col.tex_no);
	if (c3d->ray.wall_dir == EAST)
		return (c3d->m_col.tex_ea);
	if (c3d->ray.wall_dir == SOUTH)
		return (c3d->m_col.tex_so);
	if (c3d->ray.wall_dir == WEST)
		return (c3d->m_col.tex_we);
	display_error("in select. texture to apply");
	clear_data(c3d);
	exit (1);
}

int	get_texture_color(t_c3d_data *c3d, int y, int dx, int line_h)
{
	int			dy;
	int			dist_to_top;
	t_mlx_img	tmp;

	tmp = get_texture(c3d);
	dist_to_top = y + (line_h - c3d->mlx.h) / 2;
	dy = dist_to_top * tmp.height / line_h;
	return (*(int *)(tmp.addr + (dy * tmp.line_len + dx * tmp.bpp / 8)));
}

int	determine_offset_x(t_c3d_data *c3d)
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

void	extract_slice_texture(t_mlx *mlx, t_c3d_data *c3d, int x, int line_h)
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
			col = get_texture_color(c3d, init_y, offset_x, line_h);
			c3d->m_col.col[init_y * mlx->w + x] = col;
		}
		init_y++;
	}
}
