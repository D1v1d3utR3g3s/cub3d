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

void	display_map(t_c3d_data c3d)
{
	int	i;

	printf("\n\n");
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
