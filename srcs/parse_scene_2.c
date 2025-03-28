/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:07:51 by hauerbac          #+#    #+#             */
/*   Updated: 2025/03/23 19:00:03 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic.h"

static int	is_a_map_valid_char(t_c3d_data *c3d, ssize_t *elements,
								const char c, ssize_t i)
{
	int	boolean;

	if (c == '0' || c == '1'
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ' || c == '\n' || c == '\0')
	{
		boolean = 1;
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			elements[PLAYERS_NB]++;
			elements[PLAYER_INDEX] = i;
		}
	}
	else
	{
		c3d->error_msg = "There is an invalid character into the map\n";
		boolean = 0;
	}
	return (boolean);
}

static int	check_map(t_c3d_data *c3d, ssize_t *elements, char **raw_data,
						ssize_t len)
{
	ssize_t	i;
	ssize_t	j;

	j = 0;
	i = elements[MAP_INDEX];
	while (i < len)
	{
		if (!is_a_map_valid_char(c3d, elements, (*raw_data)[i], i))
			return (1);
		if ((*raw_data)[i] == ' ')
			(*raw_data)[i] = '_';
		if ((*raw_data)[i] == '\n' || (*raw_data)[i] == '\0')
		{
			if (j > elements[MAP_COLUMNS_NB])
				elements[MAP_COLUMNS_NB] = j;
			j = 0;
		}
		else
			j++;
		i++;
	}
	if (j > elements[MAP_COLUMNS_NB])
		elements[MAP_COLUMNS_NB] = j;
	c3d->error_msg = NULL;
	return (0);
}

static void	parse_map_char_and_player(t_c3d_data *c3d, ssize_t *k,
										ssize_t *i, char *raw_data)
{
	int	x;
	int	y;

	if (raw_data[*i] == '\n' || raw_data[*i] == '\0')
		return ;
	c3d->maze.map[*k] = raw_data[*i];
	if (raw_data[*i] == 'N' || raw_data[*i] == 'S'
		|| raw_data[*i] == 'E' || raw_data[*i] == 'W')
	{
		x = *k % c3d->maze.nb_col;
		y = *k / c3d->maze.nb_col;
		if (raw_data[*i] == 'N')
			update_player(c3d, x, y, 3 * M_PI / 2);
		if (raw_data[*i] == 'S')
			update_player(c3d, x, y, M_PI / 2);
		if (raw_data[*i] == 'E')
			update_player(c3d, x, y, 0);
		if (raw_data[*i] == 'W')
			update_player(c3d, x, y, M_PI);
		c3d->maze.map[*k] = '0';
	}
	(*k)++;
	(*i)++;
}

static int	init_maze_map(t_c3d_data *c3d, ssize_t *el, char **raw_data,
							ssize_t len)
{
	if (check_map(c3d, el, raw_data, len) != 0)
		return (-1);
	if (el[PLAYERS_NB] == 0)
	{
		c3d->error_msg = "There is none player on the c3d maze map\n";
		return (-2);
	}
	if (el[PLAYERS_NB] > 1)
	{
		c3d->error_msg = "There are too much players on the c3d maze map\n";
		return (-3);
	}
	c3d->maze.map = (char *) malloc(sizeof(char) \
					* ((el[MAP_LINES_NB] * el[MAP_COLUMNS_NB]) + 1));
	if (!c3d->maze.map)
	{
		c3d->error_msg = "With the c3d maze map : malloc error\n";
		return (-4);
	}
	c3d->maze.nb_line = el[MAP_LINES_NB];
	c3d->maze.nb_col = el[MAP_COLUMNS_NB];
	return (0);
}

int	parse_map(t_c3d_data *c3d, ssize_t *el, char **raw_data,
						ssize_t len)
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	k;

	if (init_maze_map(c3d, el, raw_data, len) != 0)
		return (1);
	k = 0;
	j = 0;
	i = el[MAP_INDEX];
	while (i < len && (*raw_data)[i])
	{
		parse_map_char_and_player(c3d, &k, &i, *raw_data);
		j = k % el[MAP_COLUMNS_NB];
		while (j > 0 && j < el[MAP_COLUMNS_NB]
			&& ((*raw_data)[i] == '\n' || (*raw_data)[i] == '\0'))
		{
			c3d->maze.map[k++] = '_';
			j++;
		}
		if ((*raw_data)[i] == '\n' || (*raw_data)[i] == '\0')
			i++;
	}
	c3d->maze.map[k] = '\0';
	return (0);
}
