/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_checks_raw_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:34:16 by hauerbac          #+#    #+#             */
/*   Updated: 2025/03/18 11:55:00 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

static void	print_element_value(ssize_t *elements, int element_index,
					char *raw_data, ssize_t len)
{
	ssize_t	i;

	if (element_index >= 0 && element_index <= 10 && element_index % 2 == 0
		&& len >= 0 && raw_data && elements
		&& elements[element_index] >= 0 && elements[element_index] < len
		&& elements[element_index + 1] >= 0
		&& (elements[element_index] + elements[element_index + 1] < len)
	)
	{
		i = elements[element_index];
		while (i < elements[element_index] + elements[element_index + 1])
		{
			write(1, &raw_data[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
}

void	debug_elements(ssize_t *elements, char *raw_data, ssize_t len)
{
	printf("Length : %ld\n", len);
	printf("\"North texture\" element index : %ld - length : %ld\n",
		elements[NO_FILE_INDEX], elements[NO_FILE_LEN]);
	print_element_value(elements, NO_FILE_INDEX, raw_data, len);
	printf("\"South texture\" element index : %ld - length : %ld\n",
		elements[SO_FILE_INDEX], elements[SO_FILE_LEN]);
	print_element_value(elements, SO_FILE_INDEX, raw_data, len);
	printf("\"West texture\" element index : %ld - length : %ld\n",
		elements[WE_FILE_INDEX], elements[WE_FILE_LEN]);
	print_element_value(elements, WE_FILE_INDEX, raw_data, len);
	printf("\"East texture\" element index : %ld - length : %ld\n",
		elements[EA_FILE_INDEX], elements[EA_FILE_LEN]);
	print_element_value(elements, EA_FILE_INDEX, raw_data, len);
	printf("\"Floor color\" element index : %ld - length : %ld\n",
		elements[F_COLOR_INDEX], elements[F_COLOR_LEN]);
	print_element_value(elements, F_COLOR_INDEX, raw_data, len);
	printf("\"Ceiling color\" element index : %ld - length : %ld\n",
		elements[C_COLOR_INDEX], elements[C_COLOR_LEN]);
	print_element_value(elements, C_COLOR_INDEX, raw_data, len);
	printf("\"Map\" element index : %ld - number of lines : %ld \
- number of columns : %ld - \n\"%s\" - number of players : %ld \
- player index : %ld\n", elements[MAP_INDEX], elements[MAP_LINES_NB],
		elements[MAP_COLUMNS_NB], &raw_data[elements[MAP_INDEX]],
		elements[PLAYERS_NB], elements[PLAYER_INDEX]);
}

void	debug_c3d_data(t_c3d_data *c3d)
{
	printf("c3d->error_msg : \"%s\"\n", c3d->error_msg);
	printf("\"North texture\" path : \"%s\"\n", c3d->textures.no);
	printf("\"South texture\" path : \"%s\"\n", c3d->textures.so);
	printf("\"West texture\" path : \"%s\"\n", c3d->textures.we);
	printf("\"East texture\" path : \"%s\"\n", c3d->textures.ea);
	printf("\"Floor color\" : %d\n", c3d->textures.f);
	printf("\"Ceiling color\" : %d\n", c3d->textures.c);
	if (!c3d->maze.map)
		printf("\"Map\" - number of lines : %d - \
number of columns : %d - \n\"%s\"\n",
			c3d->maze.nb_line, c3d->maze.nb_col, c3d->maze.map);
	else
		printf("\"Map\" - number of lines : %d - \
number of columns : %d - \n\"%s\"\n - c3d->maze.map length : %ld - \
%ld %% %d = %ld - %ld / %d = %ld\n",
			c3d->maze.nb_line, c3d->maze.nb_col, c3d->maze.map,
			ft_strlen(c3d->maze.map), ft_strlen(c3d->maze.map),
			c3d->maze.nb_col, ft_strlen(c3d->maze.map) % c3d->maze.nb_col,
			ft_strlen(c3d->maze.map), c3d->maze.nb_col,
			ft_strlen(c3d->maze.map) / c3d->maze.nb_col);
	printf("\"Player\" px : %.2f - py : %.2f - pa : %.2f - dx : %.2f - \
dy : %.2f - da : %.2f - fov : %d\n", c3d->player.px, c3d->player.py,
		c3d->player.pa, c3d->player.dx, c3d->player.dy, c3d->player.da,
		c3d->player.fov);
}
