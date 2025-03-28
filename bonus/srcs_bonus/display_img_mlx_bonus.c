/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_img_mlx_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:55:31 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/23 21:40:40 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic_bonus.h"

/* ************************************************************************** */
/*                                img_pix_put                                 */
/* -------------------------------------------------------------------------- */
/* This function clears the different part generated with mlx (this contained */
/*  the mlx pointer, the window as well as the image )                        */
/* Inputs :                                                                   */
/*  - t_mlx_img *img : a pointer to a structure used for mlx images           */
/*  - int x : the x coordinate of the pixel                                   */
/*  - int y : the y coordinate of the pixel                                   */
/*  - int col : the color that we desire for the pixel                        */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	img_pix_put(t_mlx_img *img, int x, int y, int col)
{
	int		offset;
	char	*pix_dest;

	offset = (y * img->line_len + x * (img->bpp / 8));
	pix_dest = img->addr + offset;
	*(unsigned int *)pix_dest = col;
}
