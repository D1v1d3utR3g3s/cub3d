/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_checks_raw_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:34:16 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/14 15:38:09 by hauerbac         ###   ########.fr       */
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
	printf("\"Map\" element index : %ld - number of lines : %ld - \"%s\"\n",
		elements[MAP_INDEX], elements[MAP_LINES_NB],
		&raw_data[elements[MAP_INDEX]]);
}
