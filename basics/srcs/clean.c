/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:32:44 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/11 16:35:54 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/*                                 clear_data                                 */
/* -------------------------------------------------------------------------- */
/* This function clears the different part generated with mlx (clean img,     */
/* clean window, close the connection to the X server and destroy windows,    */
/* free mlx pointer) and the struct generated in init_c3d_data                */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : a pointer to a structure                              */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	clear_data(t_c3d_data *c3d)
{
	if (c3d->grid.map)
	{
		free(c3d->grid.map);
		c3d->grid.map = NULL;
	}
	if (c3d->mlx_ptr)
	{
		if (c3d->img_ptr.mlx_img)
			mlx_destroy_image(c3d->mlx_ptr, c3d->img_ptr.mlx_img);
		if (c3d->win_ptr)
			mlx_destroy_window(c3d->mlx_ptr, c3d->win_ptr);
		mlx_destroy_display(c3d->mlx_ptr);
		free(c3d->mlx_ptr);
	}
}
