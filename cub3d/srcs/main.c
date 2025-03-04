/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:30:01 by hauerbac          #+#    #+#             */
/*   Updated: 2025/03/03 22:04:16 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

////////////////////////////////////////////////////////////////////////////////
///                                 TO DO :                                  ///
/// ------------------------------------------------------------------------ ///
///   - remove ft_strchr modif (needed for my system at home)                ///
///   - remove ft_strrchr modif (needed for my system at home)               ///
///   - remove ft_strtrim modif (needed for my system at home)               ///
///   - change window size                                                   ///
///   - adapt view (player ~ half the size of a wall)                        ///
///   - update rotation and movement speed                                   ///
///   - remove hard programmation part to be able to make quick modif        ///
///   - if more than one key is pressed how do we want our program to act    ///
///   - add textures to walls                                                ///
////////////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/* ************************************************************************** */
int	main(const int argc, const char **argv)
{
	char		*file_path;
	t_c3d_data	c3d;
	int			result;

	c3d.size_map = 64;
	init_maze(&(c3d.maze));
	init_player(&(c3d.player));
	c3d.mlx.mlx_ptr = NULL;
	c3d.mlx.img_ptr.mlx_img = NULL;
	c3d.mlx.win_ptr = NULL;
	c3d.m_col.col = NULL;
	c3d.wall_size = 12;
	file_path = NULL;
	if (parse_c3d_args(&file_path, argc, argv) != 0)
		return (1);
	result = init_c3d_data(&c3d, file_path);
	if (file_path)
	{
		free(file_path);
		file_path = NULL;
	}
	if (result == 1)
		return (display_error(c3d.error_msg), clear_data(&c3d), 1);

	init_event(&(c3d.event));
	init_col(&c3d);
	init_textures(&c3d);

	display_map(c3d);
	display_player_pos(c3d);

	loop_game(&c3d);
	return (clear_data(&c3d), 0);
}
