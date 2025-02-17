/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:31:51 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/17 21:53:03 by hauerbac         ###   ########.fr       */
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
		if (!((*raw_data)[i] == '\n' || (*raw_data)[i] == '\0'))
			j++;
		else
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

static void	save_texture_file_path(t_c3d_data *c3d, char *file_path,
									ssize_t index)
{
	if (index == NO_FILE_INDEX)
		c3d->textures.NO = file_path;
	if (index == SO_FILE_INDEX)
		c3d->textures.SO = file_path;
	if (index == WE_FILE_INDEX)
		c3d->textures.WE = file_path;
	if (index == EA_FILE_INDEX)
		c3d->textures.EA = file_path;
}

static int	check_texture_file_path(t_c3d_data *c3d, ssize_t *elements,
									const char *raw_data, ssize_t index)
{
	char	*file_path;
	int		fd;

	file_path = ft_substr(&raw_data[elements[index]], 0, elements[index + 1]);
	if (file_path == NULL)
	{
		c3d->error_msg = "Malloc error on a texture file\n";
		return (-3);
	}
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (free(file_path), -1);
	if (fd != -1 && close(fd) == -1)
	{
		c3d->error_msg = "Close error of a texture file\n";
		return (free(file_path), -2);
	}
	save_texture_file_path(c3d, file_path, index);
	return (0);
}

int	parse(t_c3d_data *c3d, ssize_t *el, char **raw_data, ssize_t len)
{
	c3d->error_msg = \
		"No such file/wrong read rights on \"North texture\"\n";
	if (check_texture_file_path(c3d, el, *raw_data, NO_FILE_INDEX) < 0)
		return (1);
	c3d->error_msg = \
		"No such file/wrong read rights on \"South texture\"\n";
	if (check_texture_file_path(c3d, el, *raw_data, SO_FILE_INDEX) < 0)
		return (1);
	c3d->error_msg = "No such file/wrong read rights on \"West texture\"\n";
	if (check_texture_file_path(c3d, el, *raw_data, WE_FILE_INDEX) < 0)
		return (1);
	c3d->error_msg = "No such file/wrong read rights on \"East texture\"\n";
	if (check_texture_file_path(c3d, el, *raw_data, EA_FILE_INDEX) < 0)
		return (1);
	return (check_map(c3d, el, raw_data, len));
}
