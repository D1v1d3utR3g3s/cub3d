/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_anim_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:16:11 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/23 21:34:29 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic_bonus.h"

/* ************************************************************************** */
/*                             composed_anim_name                             */
/* -------------------------------------------------------------------------- */
/* This function returns the string created by adding <n> (in 2 int format)   */
/* to the path saved in <c3d->anim.path> then adding the extension (.xpm)     */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - int n : the number to convert in 2 int format                           */
/* Return :                                                                   */
/*  - char *: the string obtained after joining path, nb and extension        */
/* ************************************************************************** */
static char	*composed_anim_name(t_c3d_data *c3d, int n)
{
	char	nb[3];
	char	*tmp;
	char	*name;

	if (n < 10)
	{
		nb[0] = '0';
		nb[1] = n + '0';
	}
	else
	{
		nb[0] = (int)(n / 10) + '0';
		nb[1] = (int)(n % 10) + '0';
	}
	nb[2] = '\0';
	tmp = ft_strjoin(c3d->anim.path, nb);
	if (tmp == NULL)
		err_clear_exit("ERROR - in composing name of anim img\n", c3d);
	name = ft_strjoin(tmp, c3d->anim.ext);
	free(tmp);
	if (tmp == NULL)
		err_clear_exit("ERROR - in composing name of anim img\n", c3d);
	return (name);
}

/* ************************************************************************** */
/*                              init_anim_allow                               */
/* -------------------------------------------------------------------------- */
/* This function initialises an array that contained all the int value        */
/* associated to all the direction allow for an anim display on each tile of  */
/* the maze                                                                   */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - int* : array of int associated to all the dir allowed for each tile     */
/* ************************************************************************** */
static int	*init_anim_allow(t_c3d_data *c3d)
{
	int	*tmp;
	int	x;
	int	y;
	int	size;

	size = c3d->maze.nb_col * c3d->maze.nb_line;
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		err_clear_exit("ERROR - malloc <anim>\n", c3d);
	y = 0;
	while (y < c3d->maze.nb_line)
	{
		x = 0;
		while (x < c3d->maze.nb_col)
		{
			tmp[y * c3d->maze.nb_col + x] = allow_for_anim(c3d, x, y);
			x++;
		}
		y++;
	}
	return (tmp);
}

/* ************************************************************************** */
/*                                init_sprite                                 */
/* -------------------------------------------------------------------------- */
/* This function initialises sprite array and the img datas associated to     */
/* each animation sequence image                                              */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
static void	init_sprite(t_c3d_data *c3d)
{
	int		i;
	char	*name;

	c3d->anim.sprite = malloc(sizeof(t_mlx_img) * c3d->anim.nb_anim);
	if (!c3d->anim.sprite)
		err_clear_exit("ERROR - malloc animation\n", c3d);
	i = 0;
	while (i < c3d->anim.nb_anim)
	{
		name = composed_anim_name(c3d, i);
		if (name == NULL)
			err_clear_exit("ERROR - in composing name of anim img\n", c3d);
		c3d->anim.sprite[i] = load_xpm_textures(c3d, &(c3d->mlx), name);
		free(name);
		i++;
	}
}

/* ************************************************************************** */
/*                                  init_id                                   */
/* -------------------------------------------------------------------------- */
/* This function initialises the direction of the display anim (between the   */
/* allow direction(s) contained in dir_allow). The direction is obtained      */
/* randomly                                                                   */
/* Inputs :                                                                   */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/*  - int dir_allow : allow direction(s) associated to the tile for anim      */
/* Return :                                                                   */
/*  - int : the direction associated to the anim display                      */
/* ************************************************************************** */
void	init_id(t_c3d_data *c3d)
{
	int	old_id;
	int	id;
	int	n;

	old_id = c3d->anim.wall_id;
	n = c3d->maze.nb_col * c3d->maze.nb_line - 1;
	id = rand_int(0, n, c3d);
	while (id == old_id || c3d->anim.anim_dir[id] == 0)
	{
		id = rand_int(0, n, c3d);
	}
	c3d->anim.wall_id = id;
	c3d->anim.dir = determine_dir_anim(c3d, c3d->anim.anim_dir[id]);
	if (DISPLAY_DEBUG)
		display_anim_pos(c3d);
}

/* ************************************************************************** */
/*                                 init_anim                                  */
/* -------------------------------------------------------------------------- */
/* This function initialises anim datas                                       */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to a struct that contained necessary datas    */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	init_anim(t_c3d_data *c3d)
{
	c3d->anim.path = "associated_textures/anim/globe/globe_";
	c3d->anim.ext = ".xpm";
	c3d->anim.nb_anim = 8;
	init_sprite(c3d);
	c3d->anim.rand_id = 0;
	c3d->anim.anim_dir = init_anim_allow(c3d);
	c3d->anim.anim_id = 0;
	c3d->anim.wall_id = -1;
	c3d->anim.score = 0;
	c3d->anim.t0 = gettime_in(MILLISECONDS, c3d);
	c3d->anim.dt = 125;
	sub_init_anim(c3d);
}
