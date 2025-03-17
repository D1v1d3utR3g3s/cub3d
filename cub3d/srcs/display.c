/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:55:31 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/17 00:58:02 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/*                                  full_img                                  */
/* -------------------------------------------------------------------------- */
/* This function creates an image by specifying the color to associate to     */
/* each pixels of the image. Then the image is put inside the window.         */
/* rq : this allow a smooth display                                           */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	full_img(t_c3d_data *c3d)
{
	t_pix	pix;
	t_mlx	*mlx;

	mlx = &(c3d->mlx);
	pix.y = 0;
	while (pix.y < mlx->h)
	{
		pix.x = 0;
		while (pix.x < mlx->w)
		{
			pix.col = determine_col(pix.x, pix.y, c3d);
			img_pix_put(&mlx->img_ptr, pix.x, pix.y, pix.col);
			pix.x++;
		}
		pix.y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr.mlx_img,
		0, 0);
}

/* ************************************************************************** */
/*                                 display_3D                                 */
/* -------------------------------------------------------------------------- */
/* This function displays a 3D representation of the maze (map)               */
/* To do so, the distance between the player and the nearest intersection     */
/* (wall) is calculated. This distance is converted in the heigth of the wall */
/* from the player point of view and this value is used to associate a color  */
/* to each "wall pixels"                                                      */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	display_3d(t_c3d_data *c3d)
{
	init_ray(c3d, c3d->player.pa);
	init_col_array(&(c3d->m_col.col), c3d->mlx.w * c3d->mlx.h);
	raycast(c3d);
	if (BONUS_MINIMAP == 1)
		update_minimap_col(c3d);
	full_img(c3d);
}

/* ************************************************************************** */
/*                                 loop_event                                 */
/* -------------------------------------------------------------------------- */
/* This function checks if one event occured, at least, occured. If that is   */
/* the case then the event(s) are apply and the 3D dispaly is update          */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - 0 : (see if still needed)                                               */
/* ************************************************************************** */
static int	loop_event(t_c3d_data *c3d)
{
	if (BONUS_ANIM)
		get_current_anim_id(c3d);
	if (check_event(c3d))
		apply_event(c3d);
	display_3d(c3d);
	return (0);
}

/* ************************************************************************** */
/*                                 loop_game                                  */
/* -------------------------------------------------------------------------- */
/* This function loops the game (3D display, hook events, etc.) until the     */
/* game is exit (red cross from window or Esc key)                            */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	loop_game(t_c3d_data *c3d)
{
	display_3d(c3d);
	hook_event(c3d);
	mlx_loop_hook(c3d->mlx.mlx_ptr, loop_event, c3d);
	mlx_loop(c3d->mlx.mlx_ptr);
}
