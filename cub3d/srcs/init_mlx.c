/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:47:29 by roxane            #+#    #+#             */
/*   Updated: 2025/03/23 18:16:46 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic.h"

/* ************************************************************************** */
/*                                 init_image                                 */
/* -------------------------------------------------------------------------- */
/* This function initialises the basic mlx image datas needed for creating a  */
/* new mlx compatible image (new image instance pointer, memory address of    */
/* the given image)                                                           */
/* Input :                                                                    */
/*  - t_mlx *mlx : a pointer to a structure that contained mlx usefull elt    */
/* Return :                                                                   */
/*  - 0 : if everything went well and was created successfully                */
/*  - 1 : if a problem has be encountered                                     */
/* ************************************************************************** */
static int	init_image(t_mlx *mlx)
{
	mlx->img_ptr.mlx_img = mlx_new_image(mlx->mlx_ptr, mlx->w, mlx->h);
	if (mlx->img_ptr.mlx_img == NULL)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		display_error("with the mlx image generation\n");
		return (1);
	}
	mlx->img_ptr.addr = mlx_get_data_addr(mlx->img_ptr.mlx_img,
			&mlx->img_ptr.bpp, &mlx->img_ptr.line_len, &mlx->img_ptr.endian);
	if (!mlx->img_ptr.addr)
	{
		display_error("extract datas mlx file\n");
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                init_window                                 */
/* -------------------------------------------------------------------------- */
/* This function initialises the basic mlx window datas needed for creating   */
/* a window (new window instance pointer, size, title)                        */
/* Input :                                                                    */
/*  - t_mlx *mlx : a pointer to a structure that contained mlx usefull elt    */
/* Return :                                                                   */
/*  - 0 : if everything went well and was created successfully                */
/*  - 1 : if a problem has be encountered                                     */
/* ************************************************************************** */
static int	init_window(t_mlx *mlx)
{
	mlx->w = 1024;
	mlx->h = 832;
	mlx->title = "Test Ray Tracing";
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->w,
			mlx->h, mlx->title);
	if (mlx->win_ptr == NULL)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		display_error("with the mlx window generation\n");
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                               init_mlx_data                                */
/* -------------------------------------------------------------------------- */
/* This function initialises the basic mlx datas needed for having a display  */
/* (this contained the mlx pointer, the window - with height, width, title-   */
/* and it's pointer as well as the image - with pointer and address)          */
/* Input :                                                                    */
/*  - t_mlx *mlx : a pointer to a structure that contained mlx usefull elt    */
/* Return :                                                                   */
/*  - 0 : if everything went well and was created successfully                */
/* ************************************************************************** */
int	init_mlx_data(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
	{
		display_error("with the mlx initialisation\n");
		return (1);
	}
	if (init_window(mlx) == 1)
		return (1);
	if (init_image(mlx) == 1)
		return (1);
	return (0);
}
