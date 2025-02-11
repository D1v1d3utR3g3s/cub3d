/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:30:10 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/11 20:03:19 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/* ************************************************************************** */
int	*transpose_map(char *map)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = NULL;
	tmp = (int *)malloc(sizeof(int) * strlen(map));
	// check prior to this function or right after if == NULL
	if (!map || !map[0])
		return (NULL);
	while (map[i])
	{
		tmp[i] = map[i] - '0';
		i++;
	}
	return (tmp);
}

/* ************************************************************************** */
/* ************************************************************************** */
int	init_grid(t_c3d_data *c3d)
{
	char	*map;

	c3d->grid.nb_tile_x = 8;
	c3d->grid.nb_tile_y = 8;
	c3d->grid.w_tile = 64;
	map = "11111111\
10100001\
10100001\
10100001\
10000001\
10000101\
10000001\
11111111";
	c3d->grid.map = transpose_map(map);
	return (0);
}

/* ************************************************************************** */
/*                                 init_image                                 */
/* -------------------------------------------------------------------------- */
/* This function initialises the basic c3d image datas needed for creating a  */
/* new mlx compatible image (new image instance pointer, memory address of    */
/* the given image)                                                           */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : a pointer to a structure                              */
/* Return :                                                                   */
/*  - 0 : if everything went well and was created successfully                */
/*  - 1 : if a problem has be encountered                                     */
/* ************************************************************************** */
int	init_image(t_c3d_data *c3d)
{
	c3d->img_ptr.mlx_img = mlx_new_image(c3d->mlx_ptr, c3d->w, c3d->h);
	if (c3d->img_ptr.mlx_img == NULL)
	{
		mlx_destroy_window(c3d->mlx_ptr, c3d->win_ptr);
		mlx_destroy_display(c3d->mlx_ptr);
		free(c3d->mlx_ptr);
		c3d->error_msg = "With the mlx image generation\n";
		return (1);
	}
	c3d->img_ptr.addr = mlx_get_data_addr(c3d->img_ptr.mlx_img,
			&c3d->img_ptr.bpp, &c3d->img_ptr.line_len, &c3d->img_ptr.endian);
	return (0);
}

/* ************************************************************************** */
/*                                init_window                                 */
/* -------------------------------------------------------------------------- */
/* This function initialises the basic mlx window datas needed for creating   */
/* a window (new window instance pointer, size, title)                        */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : a pointer to a structure                              */
/* Return :                                                                   */
/*  - 0 : if everything went well and was created successfully                */
/*  - 1 : if a problem has be encountered                                     */
/* ************************************************************************** */
int	init_window(t_c3d_data *c3d)
{
	c3d->w = 1024;
	c3d->h = 512;
	c3d->title = "Test Ray Tracing";
	c3d->win_ptr = mlx_new_window(c3d->mlx_ptr, c3d->w,
			c3d->h, c3d->title);
	if (c3d->win_ptr == NULL)
	{
		mlx_destroy_display(c3d->mlx_ptr);
		free(c3d->mlx_ptr);
		c3d->error_msg = "With the mlx window generation\n";
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                               init_c3d_data                                */
/* -------------------------------------------------------------------------- */
/* This function initialises the basic c3d datas needed for having a display  */
/* (this contained the mlx pointer, the window - with height, width, title-   */
/* and it's pointer as well as the image - with pointer and address)          */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : a pointer to a structure                              */
/* Return :                                                                   */
/*  - 0 : if everything went well and was created successfully                */
/* ************************************************************************** */
int	init_c3d_data(t_c3d_data *c3d, const char *file_path)
{
	c3d->error_msg = NULL;
	if (load_scene(c3d, file_path) == 1)
		return (1);
	c3d->mlx_ptr = mlx_init();
	if (c3d->mlx_ptr == NULL)
	{
		c3d->error_msg = "With the mlx initialisation\n";
		return (1);
	}
	if (init_window(c3d) == 1)
		return (1);
	if (init_image(c3d) == 1)
		return (1);
	return (0);
}
