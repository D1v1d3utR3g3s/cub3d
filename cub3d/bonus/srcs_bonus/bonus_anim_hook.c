/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_anim_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:47:37 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/26 11:47:42 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic_bonus.h"

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
static void	display_player_infos(t_c3d_data *c3d)
{
	int	x;
	int	y;
	int	w_tile;

	w_tile = c3d->maze.w_tile;
	x = (int)((c3d->player.px) / w_tile);
	y = (int)((c3d->player.py) / w_tile);
	printf("player (%d, %d)\n", x, y);
}

/* ************************************************************************** */
/*                             display_anim_infos                             */
/* -------------------------------------------------------------------------- */
/* This function displays the position of the animated wall on the map as     */
/* well as the direction that it is facing                                    */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
static void	display_anim_infos(t_c3d_data *c3d)
{
	int	x;
	int	y;

	x = c3d->anim.wall_id % c3d->maze.nb_col;
	y = c3d->anim.wall_id / c3d->maze.nb_col;
	printf("anim (%d, %d) | dir : ", x, y);
	if (c3d->anim.dir == NORTH)
		printf("North\n");
	else if (c3d->anim.dir == SOUTH)
		printf("South\n");
	else if (c3d->anim.dir == EAST)
		printf("East\n");
	else if (c3d->anim.dir == WEST)
		printf("West\n");
	else
		printf("None\n");
}

/* ************************************************************************** */
/*                               display_infos                                */
/* -------------------------------------------------------------------------- */
/* This function displays the position of player then the position of the     */
/* animated wall on the map as well as the direction that the anim is facing  */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	display_infos(t_c3d_data *c3d)
{
	display_player_infos(c3d);
	display_anim_infos(c3d);
}
