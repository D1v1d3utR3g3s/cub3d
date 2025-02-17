/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:31:51 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/17 10:08:01 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

static int	is_a_map_valid_char(const char c)
{
	int	boolean;

	if (c == '0' || c == '1'
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ' || c == '\n' || c == '\0')
		boolean = 1;
	else
		boolean = 0;
	return (boolean);
}

static int	check_map(t_c3d_data *c3d, ssize_t *elements, char **raw_data,
						ssize_t len)
{
	ssize_t	i;
	ssize_t	j;

	c3d->error_msg = "There is an invalid character into the map\n";
	j = 0;
	i = elements[MAP_INDEX];
	while (i < len && (*raw_data)[i])
	{
		if (!is_a_map_valid_char((*raw_data)[i]))
			return (1);
		if ((*raw_data)[i] == ' ')
			(*raw_data)[i] = '_';
		j++;
		if ((*raw_data)[i] == '\n' || (*raw_data)[i] == '\0')
		{
			if (j > elements[MAP_COLUMNS_NB])
				elements[MAP_COLUMNS_NB] = j;
			j = 0;
		}
		i++;
	}
	c3d->error_msg = NULL;
	debug_elements(elements, *raw_data, len);
	return (0);
}

/*static int	check_structure_file_path(const char *raw_data, ssize_t from,
						ssize_t len)
{
	int		result;
	char	*file_path;
	int		fd;

	result = 0;
	file_path = ft_substr(raw_data, from, len);
	if (file_path == NULL)
		result = -3;
	else
	{
		fd = open(file_path, O_RDONLY);
		if (fd == -1)
			result = -1;
		if (fd != -1 && close(fd) == -1)
			result = -2;
		if (file_path)
		{
			free(file_path);
			file_path = NULL;
		}
	}
	return (result);
}*/

int	parse(t_c3d_data *c3d, ssize_t *elements, char **raw_data, ssize_t len)
{
	/*c3d->error_msg = "No such file/wrong read rights on \"North texture\"\n";
	if (check_structure_file_path(*raw_data, elements[NO_FILE_INDEX],
			elements[NO_FILE_LEN]) == -1)
		return (1);
	c3d->error_msg = "No such file/wrong read rights on \"South texture\"\n";
	if (check_structure_file_path(*raw_data, elements[SO_FILE_INDEX],
			elements[SO_FILE_LEN]) == -1)
		return (1);
	c3d->error_msg = "No such file/wrong read rights on \"West texture\"\n";
	if (check_structure_file_path(*raw_data, elements[WE_FILE_INDEX],
			elements[WE_FILE_LEN]) == -1)
		return (1);
	c3d->error_msg = "No such file/wrong read rights on \"East texture\"\n";
	if (check_structure_file_path(*raw_data, elements[EA_FILE_INDEX],
			elements[EA_FILE_LEN]) == -1)
		return (1);*/
	return (check_map(c3d, elements, raw_data, len));
}
