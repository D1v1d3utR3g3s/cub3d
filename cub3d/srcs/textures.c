/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:17:11 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/02 23:33:54 by rmorice          ###   ########.fr       */
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
	char	*no_path = "textures/north.xpm"; //"textures/BRICK_1A.xpm";
	char	*ea_path = "textures/east.xpm"; //"textures/GRID_2B.xpm";
	char	*so_path = "textures/south.xpm"; //"textures/PIPES_2B.xpm";
	char	*we_path = "textures/west.xpm"; //"textures/WOOD_1C.xpm";

	c3d->m_col.tex_no = load_xpm_textures(&c3d->mlx, no_path);
	c3d->m_col.tex_ea = load_xpm_textures(&c3d->mlx, ea_path);
	c3d->m_col.tex_so = load_xpm_textures(&c3d->mlx, so_path);
	c3d->m_col.tex_we = load_xpm_textures(&c3d->mlx, we_path);
}
