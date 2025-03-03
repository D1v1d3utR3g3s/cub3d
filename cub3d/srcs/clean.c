/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:32:44 by hauerbac          #+#    #+#             */
/*   Updated: 2025/03/03 21:30:15 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

void	clear_textures(t_c3d_data *c3d)
{
	if (c3d && c3d->textures.NO)
	{
		free(c3d->textures.NO);
		c3d->textures.NO = NULL;
	}
	if (c3d && c3d->textures.SO)
	{
		free(c3d->textures.SO);
		c3d->textures.SO = NULL;
	}
	if (c3d && c3d->textures.WE)
	{
		free(c3d->textures.WE);
		c3d->textures.WE = NULL;
	}
	if (c3d && c3d->textures.EA)
	{
		free(c3d->textures.EA);
		c3d->textures.EA = NULL;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
static void	clear_img_texture(t_c3d_data *c3d)
{
	if (c3d->m_col.tex_no.mlx_img)
		mlx_destroy_image(c3d->mlx.mlx_ptr, c3d->m_col.tex_no.mlx_img);
	if (c3d->m_col.tex_ea.mlx_img)
		mlx_destroy_image(c3d->mlx.mlx_ptr, c3d->m_col.tex_ea.mlx_img);
	if (c3d->m_col.tex_so.mlx_img)
		mlx_destroy_image(c3d->mlx.mlx_ptr, c3d->m_col.tex_so.mlx_img);
	if (c3d->m_col.tex_we.mlx_img)
		mlx_destroy_image(c3d->mlx.mlx_ptr, c3d->m_col.tex_we.mlx_img);
}

/* ************************************************************************** */
/*                                 clear_data                                 */
/* -------------------------------------------------------------------------- */
/* This function clears the different part generated with mlx (clean img,     */
/* clean window, close the connection to the X server and destroy windows,    */
/* free mlx pointer, the struct generated in mlx_init)                        */
/* Every element that have been malloced are also free to be leaks free       */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : a pointer to a struct that contained datas to clear   */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	clear_data(t_c3d_data *c3d)
{
	t_mlx	*mlx;

	mlx = &(c3d->mlx);
	clear_textures(c3d);
	if (c3d && c3d->maze.map)
	{
		free(c3d->maze.map);
		c3d->maze.map = NULL;
	}
	if (c3d && mlx && mlx->mlx_ptr)
	{
		if (mlx->img_ptr.mlx_img)
			mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr.mlx_img);
		if (mlx->win_ptr)
			mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		clear_img_texture(c3d);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	if (c3d->m_col.col)
		free(c3d->m_col.col);
}
