/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:57:25 by roxane            #+#    #+#             */
/*   Updated: 2025/02/17 01:02:12 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/*                               init_col_array                               */
/* -------------------------------------------------------------------------- */
/* This function initialises color array with -1 value (a value that can't be */
/* obtained with RGB conversion)                                              */
/* Inputs :                                                                   */
/*  - int **col_map : a pointer to the int array to initialise                */
/*  - int size : the size of the color array                                  */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
void	init_col_array(int **col_map, int size)
{
	int	i;

	i = 0;
	if (!(*col_map))
		display_error("color array not created\n");
	while (i < size)
	{
		(*col_map)[i] = -1;
		i++;
	}
}

/* ************************************************************************** */
/*                                  init_col                                  */
/* -------------------------------------------------------------------------- */
/* This function init every element of a t_map_col structure contained in a   */
/* t_c3d_data structure                                                       */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - 0 (check if still needed)                                               */
/* ************************************************************************** */
int	init_col(t_c3d_data *c3d)
{
	t_map_col	*m_col;

	m_col = &(c3d->m_col);
	m_col->background = encode_rgb(0, 0, 0);
	m_col->no = encode_rgb(130, 142, 132);
	m_col->so = encode_rgb(122, 127, 128);
	m_col->we = encode_rgb(112, 128, 144);
	m_col->ea = encode_rgb(111, 114, 133);
	m_col->f = encode_rgb(67, 97, 117);
	m_col->c = encode_rgb(20, 66, 90);
	m_col->col = malloc(sizeof(int) * c3d->mlx.w * c3d->mlx.h);
	if (!m_col->col)
		err_clear_exit("malloc error\n", c3d);
	init_col_array(&(m_col->col), c3d->mlx.w * c3d->mlx.h);
	return (0);
}
