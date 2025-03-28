/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_raw_data_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:19:08 by hauerbac          #+#    #+#             */
/*   Updated: 2025/03/23 18:01:01 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic.h"

static void	remove_ending_spaces_of_a_line_into_map(char **str, ssize_t *len,
													ssize_t *i, ssize_t j)
{
	ssize_t	new_len;
	ssize_t	first_ending_space_index;
	ssize_t	nl_index;

	new_len = *len;
	first_ending_space_index = -1;
	nl_index = -1;
	if (*i < *len && *i > j && (*str)[*i] && (*str)[*i] == '\n')
		nl_index = (*i)--;
	while (*i >= j && (*str)[*i] && (*str)[*i] == ' ')
	{
		first_ending_space_index = *i;
		(*str)[(*i)--] = '\0';
		new_len--;
	}
	if (first_ending_space_index != -1 && nl_index != -1)
	{
		(*str)[first_ending_space_index] = '\n';
		(*str)[nl_index] = '\0';
		*i = first_ending_space_index + 1;
		ft_strlcpy(*str + *i, *str + nl_index + 1, new_len + 1);
		*len = new_len;
	}
	if (nl_index != -1 && first_ending_space_index == -1)
		*i += 2;
}

int	remove_ending_spaces_of_each_line_into_map(char **str, ssize_t *len,
												ssize_t from)
{
	ssize_t	i;
	ssize_t	j;

	i = from;
	while (i < *len && (*str)[i])
	{
		j = i;
		while (i < *len && (*str)[i] && (*str)[i] != '\n')
			i++;
		remove_ending_spaces_of_a_line_into_map(str, len, &i, j);
		if (i <= j && (*str)[i] && (*str)[i] == '\n')
			return (-1);
	}
	return (0);
}
