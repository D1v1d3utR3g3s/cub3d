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

static void	display_player_infos(t_c3d_data c3d)
{
	int	x;
	int	y;
	int	w_tile;

	w_tile = c3d.maze.w_tile;
	x = (int)((c3d.player.px) / w_tile);
	y = (int)((c3d.player.py) / w_tile);
	printf("player (%d, %d)\n", x, y);
}

void	display_anim_infos(t_c3d_data *c3d)
{
	int	x;
	int	y;

	display_player_infos(*c3d);
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

void	rot_dir_mouse(t_c3d_data *c3d)
{
	float	rot;
	int		mx;
	int		my;

	if ((c3d->event.f_xk_left != 0) || (c3d->event.f_xk_right != 0))
		return ;
	rot = c3d->player.rot_speed;
	mlx_mouse_get_pos(c3d->mlx.mlx_ptr, c3d->mlx.win_ptr, &mx, &my);
	if ((mx != -1) && (mx < c3d->mouse.mx))
	{
		c3d->player.pa = update_angle(c3d->player.pa, -rot);
		display_3d(c3d);
	}
	else if ((mx != -1) && (mx > c3d->mouse.mx))
	{
		c3d->player.pa = update_angle(c3d->player.pa, rot);
		display_3d(c3d);
	}
}

int	click(int button, int mx, int my, t_c3d_data *c3d)
{
	if (button == 1)
	{
		c3d->mouse.mx = mx;
		c3d->mouse.my = my;
		c3d->mouse.flag_press = 1;
	}
	return (0);
}

int	unclick(int button, int mx, int my, t_c3d_data *c3d)
{
	(void)mx;
	(void)my;
	if (button == 1)
		c3d->mouse.flag_press = 0;
	return (0);
}
