/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:30:10 by hauerbac          #+#    #+#             */
/*   Updated: 2025/03/18 12:57:30 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/*                                  init_map                                  */
/* -------------------------------------------------------------------------- */
/* This function initialises map structure datas                              */
/* Input :                                                                    */
/*   - t_map *map : pointer to a map structure to initialise                  */
/* Return :                                                                   */
/*   - NONE                                                                   */
/* ************************************************************************** */
void	init_maze(t_maze *maze)
{
	maze->nb_col = 0;
	maze->nb_line = 0;
	maze->w_tile = 64;
	maze->map = NULL;
}

/* ************************************************************************** */
/*                                init_player                                 */
/* -------------------------------------------------------------------------- */
/* This function initialises player structure datas                           */
/* Input :                                                                    */
/*   - t_player *player : pointer to a player structure to initialise         */
/* Return :                                                                   */
/*   - NONE                                                                   */
/* ************************************************************************** */
void	init_player(t_player *player)
{
	player->px = -1;
	player->py = -1;
	player->pa = 0;
	player->dx = -1;
	player->dy = -1;
	player->da = 0;
	player->fov = 60;
	player->mov_speed = MOV_SPEED;
	player->rot_speed = ROT_SPEED;
}

/* ************************************************************************** */
/*                                  init_ray                                  */
/* -------------------------------------------------------------------------- */
/* This function initialises ray structure datas                              */
/* Input :                                                                    */
/*   - t_ray *ray : pointer to a ray structure to initialise                  */
/* Return :                                                                   */
/*   - NONE                                                                   */
/* ************************************************************************** */
void	init_ray(t_c3d_data *c3d, float angle)
{
	c3d->ray.rx = c3d->player.px;
	c3d->ray.ry = c3d->player.py;
	c3d->ray.ra = angle;
	c3d->ray.dx = 0;
	c3d->ray.dy = 0;
	c3d->ray.hit_h = 0;
	c3d->ray.hx = c3d->ray.rx;
	c3d->ray.hy = c3d->ray.ry;
	c3d->ray.dh = -1;
	c3d->ray.hit_v = 0;
	c3d->ray.vx = c3d->ray.rx;
	c3d->ray.vy = c3d->ray.ry;
	c3d->ray.dv = -1;
	c3d->ray.hit_h_door = 0;
	c3d->ray.hit_v_door = 0;
	c3d->ray.dist_wall = -1;
	c3d->ray.wall_dir = -1;
	c3d->ray.col_wall = encode_rgb(255, 0, 0);
}

/* ************************************************************************** */
/*                                 init_event                                 */
/* -------------------------------------------------------------------------- */
/* This function initialises event structure datas                            */
/* Input :                                                                    */
/*   - t_event *event : pointer to a ray structure to initialise              */
/* Return :                                                                   */
/*   - NONE                                                                   */
/* ************************************************************************** */
void	init_event(t_event *event)
{
	event->f_xk_left = 0;
	event->f_xk_right = 0;
	event->f_xk_w = 0;
	event->f_xk_a = 0;
	event->f_xk_s = 0;
	event->f_xk_d = 0;
}

/* ************************************************************************** */
/*                               init_c3d_data                                */
/* -------------------------------------------------------------------------- */
/* This function initialises the basic c3d datas needed for having a display  */
/* (this contained the mlx pointer, the window - with height, width, title-   */
/* and it's pointer as well as the image - with pointer and address)          */
/* Input :                                                                    */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - 0 : if everything went well and was created successfully                */
/* ************************************************************************** */
int	init_c3d_data(t_c3d_data *c3d, const char *file_path)
{
	c3d->error_msg = NULL;
	c3d->textures.no = NULL;
	c3d->textures.so = NULL;
	c3d->textures.we = NULL;
	c3d->textures.ea = NULL;
	c3d->textures.f = encode_rgb(0, 0, 0);
	c3d->textures.c = encode_rgb(0, 0, 0);
	if (load_scene(c3d, file_path) == 1)
		return (1);
	if (init_mlx_data(&(c3d->mlx)) == 1)
	{
		clear_data(c3d);
		exit(1);
	}
	return (0);
}
