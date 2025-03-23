/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closure_checks_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 04:45:51 by hauerbac          #+#    #+#             */
/*   Updated: 2025/03/23 21:45:31 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic_bonus.h"

static int	is_not_an_adequate_char(int *walls_nb, const char c)
{
	if (*walls_nb == 0 && c == '0')
		return (1);
	if (c == '1' || c == '2' || c == '3')
		(*walls_nb)++;
	if (c == '_')
		*walls_nb = 0;
	return (0);
}

static int	closure_checks_on_columns(char **error_msg, t_maze maze)
{
	int	i;
	int	j;
	int	k;
	int	walls_nb;

	*error_msg = "A closing wall is missing on a column into the map\n";
	i = 0;
	j = 0;
	k = 0;
	walls_nb = 0;
	while (i < maze.nb_line * maze.nb_col && maze.map[i])
	{
		if (j % maze.nb_line == 0 || (j + 1) % maze.nb_line == 0
			|| (i + maze.nb_col < maze.nb_line * maze.nb_col
				&& maze.map[i + maze.nb_col] == '_'))
			walls_nb = 0;
		if (is_not_an_adequate_char(&walls_nb, maze.map[i]))
			return (1);
		i += maze.nb_col;
		j++;
		if (j % maze.nb_line == 0)
			i = ++k;
	}
	*error_msg = NULL;
	return (0);
}

int	closure_checks(char **error_msg, t_maze maze)
{
	int	i;
	int	walls_nb;

	*error_msg = "A closing wall is missing on a line into the map\n";
	i = 0;
	walls_nb = 0;
	while (i < maze.nb_line * maze.nb_col && maze.map[i])
	{
		if (i % maze.nb_col == 0 || (i + 1) % maze.nb_col == 0
			|| (i + 1 < maze.nb_line * maze.nb_col && maze.map[i + 1] == '_'))
			walls_nb = 0;
		if (is_not_an_adequate_char(&walls_nb, maze.map[i]))
			return (1);
		i++;
	}
	return (closure_checks_on_columns(error_msg, maze));
}
