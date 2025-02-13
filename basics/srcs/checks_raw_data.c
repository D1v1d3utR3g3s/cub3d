/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_raw_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:31:08 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/13 17:37:24 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

static int	first_checks_return_2(char **error_msg, ssize_t *elements)
{
	*error_msg = "A path to a \"North texture\" element is missing\n";
	if (elements[NO_FILE_INDEX] == -2)
		return (1);
	*error_msg = "A path to a \"South texture\" element is missing\n";
	if (elements[SO_FILE_INDEX] == -2)
		return (1);
	*error_msg = "A path to a \"West texture\" element is missing\n";
	if (elements[WE_FILE_INDEX] == -2)
		return (1);
	*error_msg = "A path to an \"East texture\" element is missing\n";
	if (elements[EA_FILE_INDEX] == -2)
		return (1);
	*error_msg = "R,G,B colors for a \"Floor color\" element are missing\n";
	if (elements[F_COLOR_INDEX] == -2)
		return (1);
	*error_msg = "R,G,B colors for a \"Ceiling color\" element are missing\n";
	if (elements[C_COLOR_INDEX] == -2)
		return (1);
	*error_msg = NULL;
	return (0);
}

static int	first_checks_return(char **error_msg, ssize_t *elements)
{
	*error_msg = "A \"North texture\" element is missing before the map\n";
	if (elements[NO_FILE_INDEX] == -1)
		return (1);
	*error_msg = "A \"South texture\" element is missing before the map\n";
	if (elements[SO_FILE_INDEX] == -1)
		return (1);
	*error_msg = "A \"West texture\" element is missing before the map\n";
	if (elements[WE_FILE_INDEX] == -1)
		return (1);
	*error_msg = "An \"East texture\" element is missing before the map\n";
	if (elements[EA_FILE_INDEX] == -1)
		return (1);
	*error_msg = "A \"Floor color\" element is missing before the map\n";
	if (elements[F_COLOR_INDEX] == -1)
		return (1);
	*error_msg = "A \"Ceiling color\" element is missing before the map\n";
	if (elements[C_COLOR_INDEX] == -1)
		return (1);
	*error_msg = "A \"Map\" element is missing in the scene file\n";
	if (elements[MAP_INDEX] == -1
		|| (elements[MAP_INDEX] >= 0 && elements[MAP_LINES_NB] <= 0))
		return (1);
	return (first_checks_return_2(error_msg, elements));
}

void	remove_ending_spaces_of_last_line_into_str(char **str, ssize_t *len,
							ssize_t from,
							int remove_last_nl)
{
	ssize_t	i;
	ssize_t	last_nl_index;

	if (*len > 0)
	{
		i = *len - 1;
		last_nl_index = -1;
		if (i >= from && (*str)[i] && (*str)[i] == '\n')
			last_nl_index = i--;
		while (i >= from && (*str)[i] && (*str)[i] == ' ')
		{
			(*str)[i--] = '\0';
			(*len)--;
		}
		if (last_nl_index != -1)
		{
			(*str)[last_nl_index] = '\0';
			if (remove_last_nl == 1)
				(*len)--;
			else
				(*str)[i + 1] = '\n';
		}
	}
}

int	first_checks(char *raw_data, int nb_lines, char **error_msg)
{
	ssize_t	len;
	ssize_t	*elements;

	elements = (ssize_t [15]){-1, -1, -1, -1, -1, -1, -1, -1, \
							-1, -1, -1, -1, \
							-1, nb_lines, 0};
	len = ft_strlen(raw_data);
	remove_ending_spaces_of_last_line_into_str(&raw_data, &len, 0, 0);
	*error_msg = "This scene file is empty\n";
	if (len == 0)
		return (1);
	*error_msg = "Too much empty lines at the end of the scene file\n";
	if (nb_lines >= 2 && raw_data[len - 1] == '\n'
		&& raw_data[len - 2] == '\n')
		return (1);
	find_elements_indexes(elements, raw_data, len);
	*error_msg = "There is none texture nor color before the map in the \
		      scene file\n";
	if (elements[NO_FILE_INDEX] < 0 && elements[SO_FILE_INDEX] < 0
		&& elements[WE_FILE_INDEX] < 0 && elements[EA_FILE_INDEX] < 0
		&& elements[F_COLOR_INDEX] < 0 && elements[C_COLOR_INDEX] < 0
		&& elements[MAP_INDEX] != -1)
		return (1);
	return (first_checks_return(error_msg, elements));
}
