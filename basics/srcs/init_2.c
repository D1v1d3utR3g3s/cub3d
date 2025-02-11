/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:50:27 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/11 12:50:45 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/* ************************************************************************** */
/* ************************************************************************** */
int	init_ray(t_c3d_data *c3d, float angle)
{
	c3d->ray.rx = c3d->player.px;
	c3d->ray.ry = c3d->player.py;
	c3d->ray.dx = 0;
	c3d->ray.dy = 0;
	c3d->ray.ra = angle;
	c3d->ray.dh = -1;
	c3d->ray.hx = c3d->ray.rx;
	c3d->ray.hy = c3d->ray.ry;
	c3d->ray.dv = -1;
	c3d->ray.vx = c3d->ray.rx;
	c3d->ray.vy = c3d->ray.ry;
	c3d->ray.dist_wall = -1;
	c3d->ray.col_wall = encode_rgb(0, 125, 0);
	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */
int	init_player(t_player *player)
{
	player->px = 300;
	player->py = 300;
	player->pa = 3 * M_PI / 2;
	player->dx = cos(player->pa) * 5;
	player->dy = sin(player->pa) * 5;
	return (0);
}
