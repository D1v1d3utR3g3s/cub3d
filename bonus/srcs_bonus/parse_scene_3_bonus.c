/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:11:51 by hauerbac          #+#    #+#             */
/*   Updated: 2025/03/23 21:46:01 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic_bonus.h"

int	check_commas_into_format(t_c3d_data *c3d, ssize_t start, ssize_t end,
								const char *raw_data)
{
	ssize_t	j;
	int		commas_nb;

	commas_nb = 0;
	j = start;
	while (j >= 0 && j < end && raw_data[j])
	{
		if (raw_data[j] == ',')
			commas_nb++;
		j++;
	}
	if (commas_nb != 2)
	{
		c3d->error_msg = "Wrong number of commas into a rgb colors format\n";
		return (-1);
	}
	return (0);
}
