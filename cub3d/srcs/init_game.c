/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:30:15 by rmorice          #+#    #+#             */
/*   Updated: 2025/03/17 14:12:48 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

static void	modif_data_add_door(t_c3d_data *c3d)
{
	char	*str;
	int		i;

	str = "111111111___111111111100000001111100000001100000000000000000001\
111000000121000000111__10000000000000001____10000000000000001____\
11000000000000011_____110000000000011_______1111111111111____";
//	str = "111111100101100001100001111111";
//	c3d->player.px = 256;
//	c3d->player.py = 192;
//	c3d->maze.nb_col = 6;
//	c3d->maze.nb_line = 5;
	free(c3d->maze.map);
	c3d->maze.map = NULL;
	c3d->maze.map = malloc(sizeof(char) * (strlen(str) + 1));
	if (!c3d->maze.map)
	{
		clear_data(c3d);
		exit(1);
	}
	i = 0;
	while (str[i])
	{
		c3d->maze.map[i] = str[i];
		i++;
	}
	c3d->maze.map[i] = '\0';
}

/* ************************************************************************** */
/*                                 init_game                                  */
/* -------------------------------------------------------------------------- */
/* This function initialises all the basics datas needed for events, colors,  */
/* textures.                                                                  */
/* If bonus apply then doors, minimap and anim are initialised                */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	init_game(t_c3d_data *c3d, const char *file_path)
{
	init_event(&(c3d->event));
	init_col(c3d);
	init_textures(c3d);
	if (BONUS_DOOR)
	{
		// rm file_path once test finish
		const char *str = "scenes/Mickey.cub";
		if (ft_strncmp(file_path, str, ft_strlen(str)) == 0)
			modif_data_add_door(c3d);
		init_doors(c3d);
	}
	if (BONUS_MINIMAP)
		init_minimap(c3d);
	if (BONUS_ANIM)
		init_anim(c3d);
}
