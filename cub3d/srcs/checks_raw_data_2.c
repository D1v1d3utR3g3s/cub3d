/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_raw_data_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:52:15 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/14 16:06:18 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

static int	is_a_line_of_the_map(ssize_t *remained_lines_nb, char *raw_data,
					ssize_t j, ssize_t len)
{
	while (j + 1 < len && raw_data[j] && raw_data[j] != '\n'
		&& raw_data[j + 1] && raw_data[j + 1] != '\n')
	{
		if ((raw_data[j] == 'N' && raw_data[j + 1] == 'O')
			|| (raw_data[j] == 'S' && raw_data[j + 1] == 'O')
			|| (raw_data[j] == 'W' && raw_data[j + 1] == 'E')
			|| (raw_data[j] == 'E' && raw_data[j + 1] == 'A')
			|| (raw_data[j] == 'F' && raw_data[j + 1] == ' ')
			|| (raw_data[j] == 'C' && raw_data[j + 1] == ' '))
		{
			(*remained_lines_nb)--;
			return (0);
		}
		j++;
	}
	return (1);
}

static ssize_t	index_after_successive_empty_lines(ssize_t *remained_lines_nb,
													char *raw_data, ssize_t i,
													ssize_t len)
{
	ssize_t	j;
	ssize_t	previous;
	int		is_an_empty_line;

	j = i;
	previous = j;
	is_an_empty_line = 1;
	while (j < len && is_an_empty_line)
	{
		while (j < len && is_a_space(raw_data[j]))
			j++;
		if (j < len && !is_a_space(raw_data[j]) && raw_data[j] != '\n')
		{
			j = previous;
			is_an_empty_line = 0;
		}
		if (j < len && raw_data[j] == '\n')
		{
			j++;
			(*remained_lines_nb)--;
			previous = j;
		}
	}
	return (j);
}

static int	find_a_structure_index(ssize_t *elements, ssize_t *j,
									char *raw_data, ssize_t len)
{
	int	index_id;

	index_id = -1;
	if (raw_data[*j] == 'N' && raw_data[*j + 1] == 'O')
		index_id = NO_FILE_INDEX;
	if (raw_data[*j] == 'S' && raw_data[*j + 1] == 'O')
		index_id = SO_FILE_INDEX;
	if (raw_data[*j] == 'W' && raw_data[*j + 1] == 'E')
		index_id = WE_FILE_INDEX;
	if (raw_data[*j] == 'E' && raw_data[*j + 1] == 'A')
		index_id = EA_FILE_INDEX;
	if (index_id != -1)
	{
		*j = *j + 2;
		while (*j < len && raw_data[*j] == ' ')
			(*j)++;
		if (elements[index_id] != -2)
			elements[index_id] = *j;
		if (*j >= len || raw_data[*j] == '\n')
			elements[index_id] = -2;
		while (*j < len && raw_data[*j - 1] != '\n')
			(*j)++;
		elements[index_id + 1] = *j - 1 - elements[index_id];
	}
	return (index_id);
}

static int	find_a_color_index(ssize_t *elements, ssize_t *j, char *raw_data,
								ssize_t len)
{
	int	index_id;

	index_id = -1;
	if (*j < len - 1)
	{
		if (raw_data[*j] == 'F')
			index_id = F_COLOR_INDEX;
		if (raw_data[*j] == 'C')
			index_id = C_COLOR_INDEX;
		if (index_id != -1)
		{
			*j = *j + 1;
			while (*j < len && raw_data[*j] == ' ')
				(*j)++;
			if (elements[index_id] != -2)
				elements[index_id] = *j;
			if (*j >= len || raw_data[*j] == '\n')
				elements[index_id] = -2;
			while (*j < len && raw_data[*j - 1] != '\n')
				(*j)++;
			elements[index_id + 1] = *j - 1 - elements[index_id];
		}
	}
	return (index_id);
}

void	find_elements_indexes(ssize_t *el, char *raw_data, ssize_t len)
{
	ssize_t	j;
	int		index_id;

	j = 0;
	index_id = -3;
	while (j < len)
	{
		j = index_after_successive_empty_lines(&el[MAP_LINES_NB],
				raw_data, j, len);
		el[MAP_INDEX] = j;
		if (index_id == -1)
			break ;
		if ((index_id >= 0) && (el[index_id] > 0)
			&& (el[index_id + 1] > 0))
			remove_ending_spaces_of_last_line_into_str(&raw_data, \
				&el[index_id + 1], el[index_id], 1);
		while (j < len && raw_data[j] == ' ')
			j++;
		if (is_a_line_of_the_map(&el[MAP_LINES_NB], raw_data, j, len))
			break ;
		index_id = find_a_color_index(el, &j, raw_data, len);
		if ((index_id == -1) && (j < len - 2))
			index_id = find_a_structure_index(el, &j, raw_data, len);
		el[MAP_INDEX] = j;
	}
}
