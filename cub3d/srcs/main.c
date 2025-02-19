/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:30:01 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/19 17:55:12 by rmorice          ###   ########.fr       */
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

	////////////////////////////////////////////////////////////////////
	////                        add for test                        ////
	// initialise and update for testing purpose
    // init player
	init_event(&(c3d.event));
/*
	char	*str = "11111111\
10100001\
10100001\
10100001\
10000001\
10000101\
10000001\
11111111";
	update_maze(&(c3d.maze), str, 8, 8);
	update_player(&(c3d.player), 300, 300, 3 * M_PI / 2);*/
	init_col(&c3d);
	// loop display, hook event, etc.
	loop_game(&c3d);
	////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////
	////                      remove for test                       ////
/*	init_player(&c3d.player);
	//init_maze(&c3d);
	full_img(&c3d);

	hook_event(&c3d);
	mlx_loop(c3d.mlx_ptr);*/
	////////////////////////////////////////////////////////////////////
	return (clear_data(&c3d), 0);
}
