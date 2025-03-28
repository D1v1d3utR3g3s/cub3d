/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_testing_purpose.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:11:18 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/23 18:11:47 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic.h"

/* ************************************************************************** */
/*                                display_map                                 */
/* -------------------------------------------------------------------------- */
/* This function displays the map saved in maze.map. It is the map obtained   */
/* through the read of a .cub file and reformated to be a rectangle (all      */
/* lines will have the same size)                                             */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	display_map(t_c3d_data c3d)
{
	int	i;

	i = 0;
	while (c3d.maze.map[i])
	{
		printf("%c", c3d.maze.map[i]);
		i++;
		if (i % c3d.maze.nb_col == 0)
			printf("\n");
	}
}

/* ************************************************************************** */
/*                             display_player_pos                             */
/* -------------------------------------------------------------------------- */
/* This function displays the coordinates of the player (in map adapt for the */
/* window and in the reference's map)                                         */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	display_player_pos(t_c3d_data c3d)
{
	int	w_tile;

	w_tile = c3d.maze.w_tile;
	printf("(%f, %f) | ", c3d.player.px, c3d.player.py);
	printf("(%d, ", (int)((c3d.player.px - w_tile / 2) / w_tile));
	printf("%d)\n", (int)((c3d.player.py - w_tile / 2) / w_tile));
}

/* ************************************************************************** */
/*                           display_map_and_player                           */
/* -------------------------------------------------------------------------- */
/* This function displays the map saved in maze.map. It is the map obtained   */
/* through the read of a .cub file and reformated to be a rectangle (all      */
/* lines will have the same size) and the coordinates of the player (in map   */
/* adapt for the window and in the reference's map)                           */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	display_map_and_player(t_c3d_data c3d)
{
	display_map(c3d);
	display_player_pos(c3d);
}
