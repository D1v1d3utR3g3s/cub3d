/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:17:11 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/18 13:02:50 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/*                             load_xpm_textures                              */
/* -------------------------------------------------------------------------- */
/* This function loads a mlx file and extracts the contained data into an     */
/* t_mlx_img element                                                          */
/* Inputs :                                                                   */
/*  - t_mlx *mlx : a pointer to a structure that contained mlx usefull elt    */
/*  - char *path : the filename and path of the file to load                  */
/* Return :                                                                   */
/*  - t_mlx_img : struct elt that contained the datas associated to mlx file  */
/* ************************************************************************** */
t_mlx_img	load_xpm_textures(t_c3d_data *c3d, t_mlx *mlx, char *path)
{
	t_mlx_img	tmp;

	tmp.mlx_img = mlx_xpm_file_to_image(mlx->mlx_ptr, path,
			&tmp.width, &tmp.height);
	if (!tmp.mlx_img)
	{
		display_error("loading mlx file\n");
		clear_data(c3d);
		exit(1);
	}
	tmp.addr = mlx_get_data_addr(tmp.mlx_img, &tmp.bpp, &tmp.line_len,
			&tmp.endian);
	if (!tmp.addr)
	{
		display_error("extract datas mlx file\n");
		clear_data(c3d);
		exit(1);
	}
	return (tmp);
}

/* ************************************************************************** */
/*                               init_textures                                */
/* -------------------------------------------------------------------------- */
/* This function initialises the texture elements (no, ea, so, we and bonus   */
/* door)                                                                      */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	init_textures(t_c3d_data *c3d)
{
	char	*str_door;

	str_door = "associated_textures/doors/door.xpm";
	c3d->m_col.tex_no = load_xpm_textures(c3d, &c3d->mlx, c3d->textures.no);
	c3d->m_col.tex_ea = load_xpm_textures(c3d, &c3d->mlx, c3d->textures.ea);
	c3d->m_col.tex_so = load_xpm_textures(c3d, &c3d->mlx, c3d->textures.so);
	c3d->m_col.tex_we = load_xpm_textures(c3d, &c3d->mlx, c3d->textures.we);
	if (BONUS_DOOR == 1)
		c3d->m_col.tex_door = load_xpm_textures(c3d, &c3d->mlx, str_door);
}
