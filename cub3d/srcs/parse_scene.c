/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:31:51 by hauerbac          #+#    #+#             */
/*   Updated: 2025/03/23 17:59:19 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic.h"

static int	is_a_valid_color_value(int *value, ssize_t *i, ssize_t end,
									const char *raw_data)
{
	ssize_t	j;

	*value = 0;
	j = *i;
	while (j >= 0 && j < end && raw_data[j] && raw_data[j] == ' ')
		j++;
	*i = j;
	while (j >= 0 && j < end && (j - *i <= 2) && *value <= 255 && raw_data[j]
		&& ft_isdigit(raw_data[j]))
	{
		*value = (*value * 10) + (raw_data[j] - '0');
		j++;
	}
	if (j < 0 || (j < end && !ft_isdigit(raw_data[j]) && raw_data[j] != ' '
			&& raw_data[j] != ',') || (j - *i > 3) || *value > 255)
		return (0);
	while (j >= 0 && j < end && raw_data[j] && raw_data[j] == ' ')
		j++;
	if (j >= 0 && j < end && raw_data[j] && raw_data[j] == ',')
		j++;
	*i = j;
	return (1);
}

static int	check_rgb_colors(t_c3d_data *c3d, ssize_t *el,
								const char *raw_data, ssize_t idx)
{
	ssize_t	i;
	int		red;
	int		green;
	int		blue;

	i = el[idx];
	if (check_commas_into_format(c3d, i, el[idx] + el[idx + 1], raw_data))
		return (-4);
	red = 0;
	green = 0;
	blue = 0;
	c3d->error_msg = "The R part for the color is not in [0, 255]\n";
	if (!is_a_valid_color_value(&red, &i, el[idx] + el[idx + 1], raw_data))
		return (-1);
	c3d->error_msg = "The G part for the color is not in [0, 255]\n";
	if (!is_a_valid_color_value(&green, &i, el[idx] + el[idx + 1], raw_data))
		return (-2);
	c3d->error_msg = "The B part for the color is not in [0, 255]\n";
	if (!is_a_valid_color_value(&blue, &i, el[idx] + el[idx + 1], raw_data))
		return (-3);
	if (idx == F_COLOR_INDEX)
		c3d->textures.f = red << 16 | green << 8 | blue;
	else if (idx == C_COLOR_INDEX)
		c3d->textures.c = red << 16 | green << 8 | blue;
	return (0);
}

static void	save_texture_file_path(t_c3d_data *c3d, char *file_path,
									ssize_t index)
{
	if (index == NO_FILE_INDEX)
		c3d->textures.no = file_path;
	if (index == SO_FILE_INDEX)
		c3d->textures.so = file_path;
	if (index == WE_FILE_INDEX)
		c3d->textures.we = file_path;
	if (index == EA_FILE_INDEX)
		c3d->textures.ea = file_path;
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
	if (check_rgb_colors(c3d, el, *raw_data, F_COLOR_INDEX) < 0)
		return (1);
	if (check_rgb_colors(c3d, el, *raw_data, C_COLOR_INDEX) < 0)
		return (1);
	c3d->error_msg = NULL;
	return (parse_map(c3d, el, raw_data, len));
}
