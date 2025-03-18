/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_testing_purpose.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:11:18 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/04 16:08:40 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

void	display_anim_pos(t_c3d_data *c3d)
{
	int	x;
	int	y;

	x = c3d->anim.wall_id % c3d->maze.nb_col;
	y = c3d->anim.wall_id / c3d->maze.nb_col;
	printf("animation id %d (%d, %d) | dir ", c3d->anim.wall_id, x, y);
	if (c3d->anim.dir == NORTH)
		printf("North\n");
	else if (c3d->anim.dir == EAST)
		printf("East\n");
	else if (c3d->anim.dir == SOUTH)
		printf("South\n");
	else if (c3d->anim.dir == WEST)
		printf("West\n");
	else
		printf("NONE\n");
}

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

void	display_player_pos(t_c3d_data c3d)
{
	int	w_tile;

	w_tile = c3d.maze.w_tile;
	printf("(%f, %f) | ", c3d.player.px, c3d.player.py);
	printf("(%d, ", (int)((c3d.player.px - w_tile / 2) / w_tile));
	printf("%d)\n", (int)((c3d.player.py - w_tile / 2) / w_tile));
}

void	display_map_and_player(t_c3d_data c3d)
{
	display_map(c3d);
	display_player_pos(c3d);
}
