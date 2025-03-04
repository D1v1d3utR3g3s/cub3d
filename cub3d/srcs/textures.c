/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:17:11 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/04 04:03:54 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

static t_mlx_img	load_xpm_textures(t_mlx *mlx, char *path)
{
	t_mlx_img	tmp;

	tmp.mlx_img = mlx_xpm_file_to_image(mlx->mlx_ptr, path,
			&tmp.width, &tmp.height);
	if (!tmp.mlx_img)
	{
		display_error("loading mlx file");
		exit(1);
	}
	tmp.addr = mlx_get_data_addr(tmp.mlx_img, &tmp.bpp, &tmp.line_len,
			&tmp.endian);
	if (!tmp.addr)
	{
		display_error("extract datas mlx file");
		exit(1);
	}
	return (tmp);
}

void	init_textures(t_c3d_data *c3d)
{
	c3d->m_col.tex_no = load_xpm_textures(&c3d->mlx, c3d->textures.NO);
	c3d->m_col.tex_ea = load_xpm_textures(&c3d->mlx, c3d->textures.EA);
	c3d->m_col.tex_so = load_xpm_textures(&c3d->mlx, c3d->textures.SO);
	c3d->m_col.tex_we = load_xpm_textures(&c3d->mlx, c3d->textures.WE);
}
