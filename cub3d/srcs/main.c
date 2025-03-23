/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:30:01 by hauerbac          #+#    #+#             */
/*   Updated: 2025/03/23 18:16:16 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic.h"

////////////////////////////////////////////////////////////////////////////////
///                                 TO DO :                                  ///
/// ------------------------------------------------------------------------ ///
///   - remove ft_strchr modif (needed for my system at home)                ///
///   - remove ft_strrchr modif (needed for my system at home)               ///
///   - remove ft_strtrim modif (needed for my system at home)               ///
///   - change window size                                          - DONE   ///
///   - adapt view (player ~ half the size of a wall)               - DONE   ///
///   - update rotation and movement speed                          - DONE   ///
///   - remove hard programmation part                       - IN PROGRESS   ///
///   - check simultaneous multi keys event                         - DONE   ///
///   - add textures to walls                                       - DONE   ///
///   - for now w_tile = 64px  => textures 64px * 64px                       ///
/// ------------------------------------------------------------------------ ///
///   - correct limit cases for wall collision                               ///
///   - rotation with Mouse while hold ?                                     ///
////////////////////////////////////////////////////////////////////////////////

static void	init_clearable_datas(t_c3d_data *c3d)
{
	c3d->mlx.mlx_ptr = NULL;
	c3d->mlx.win_ptr = NULL;
	c3d->mlx.img_ptr.mlx_img = NULL;
	c3d->mlx.img_ptr.addr = NULL;
	c3d->m_col.tex_no.mlx_img = NULL;
	c3d->m_col.tex_no.addr = NULL;
	c3d->m_col.tex_so.mlx_img = NULL;
	c3d->m_col.tex_so.addr = NULL;
	c3d->m_col.tex_ea.mlx_img = NULL;
	c3d->m_col.tex_ea.addr = NULL;
	c3d->m_col.tex_we.mlx_img = NULL;
	c3d->m_col.tex_we.addr = NULL;
	c3d->m_col.col = NULL;
	if (BONUS_DOOR)
	{
		c3d->doors.dist = NULL;
		c3d->m_col.tex_door.mlx_img = NULL;
	}
	if (BONUS_ANIM)
	{
		c3d->anim.sprite = NULL;
		c3d->anim.anim_dir = NULL;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
int	main(const int argc, const char **argv)
{
	char		*file_path;
	t_c3d_data	c3d;
	int			result;

	c3d.size_map = 64;
	init_clearable_datas(&c3d);
	init_maze(&(c3d.maze));
	init_player(&(c3d.player));
	file_path = NULL;
	if (parse_c3d_args(&file_path, argc, argv) != 0)
		return (1);
	result = init_c3d_data(&c3d, file_path);
	if (file_path)
		free(file_path);
	file_path = NULL;
	if (result == 1)
		return (display_error(c3d.error_msg), clear_data(&c3d), 1);
//	init_game(&c3d);
	init_game(&c3d, argv[1]);
	if (DISPLAY_DEBUG)
		display_map_and_player(c3d);
	loop_game(&c3d);
	return (clear_data(&c3d), 0);
}
