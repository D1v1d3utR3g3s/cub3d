/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:13:13 by roxane            #+#    #+#             */
/*   Updated: 2025/02/20 12:37:45 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/*                                update_maze                                 */
/* -------------------------------------------------------------------------- */
/* This function updates the number of columns, number of lines and the str   */
/* that describe the maze component                                           */
/* Inputs :                                                                   */
/*  - t_maze *maze : a pointer to a struct that contained maze datas          */
/*  - char *str : the string that describes the maze                          */
/*  - int nb_col : the nb of column that composed the maze                    */
/*  - int nb_line : the nb of line that composed the maze                     */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	update_maze(t_maze *maze, char *str, int nb_col, int nb_line)
{
	maze->nb_col = nb_col;
	maze->nb_line = nb_line;
	maze->map = str;
}

/* ************************************************************************** */
/*                               update_player                                */
/* -------------------------------------------------------------------------- */
/* This function updates the position of the player, his angle, dx and dy     */
/* Inputs :                                                                   */
/*  - t_player *player : a pointer to a struct that contained player datas    */
/*  - float x : the new x coordinate of the player                            */
/*  - float y : the new y coordinate of the player                            */
/*  - float a : the new angle of the player                                   */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	update_player(t_c3d_data *c3d, int x, int y, float a)
{
	c3d->player.px = x * c3d->maze.w_tile + c3d->maze.w_tile / 2;
	c3d->player.py = y * c3d->maze.w_tile + c3d->maze.w_tile / 2;
	c3d->player.pa = a;
	c3d->player.dx = cos(a) * c3d->player.mov_speed;
	c3d->player.dy = sin(a) * c3d->player.mov_speed;
}

/* ************************************************************************** */
/*                                update_angle                                */
/* -------------------------------------------------------------------------- */
/* This function returns the angle [rad] obtained when <da> is added to <a>   */
/* rq : <a> and <da> are expressed in radian                                  */
/* rq2 : 2 Pi <=> 0                                                           */
/* Inputs :                                                                   */
/*  - float a : the first radian angle use for the addition                   */
/*  - float da : the second radian angle use for the addition                 */
/* Return :                                                                   */
/*  - float : the angle obtained after the addition of both input [rad]       */
/* ************************************************************************** */
float	update_angle(float a, float da)
{
	float	new_a;

	new_a = a + da;
	if (new_a > 2 * M_PI)
		new_a -= 2 * M_PI;
	else if (new_a < 0)
		new_a += 2 * M_PI;
	return (new_a);
}
