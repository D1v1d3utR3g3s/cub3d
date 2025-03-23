/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:34:08 by hauerbac          #+#    #+#             */
/*   Updated: 2025/03/23 17:54:57 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3DBasic.h"

static int	check_nb_args(const int argc, const char **argv)
{
	if (argc <= 1 || argc > 2 || (argc == 2 && argv[1] == NULL))
	{
		write(2, "Error\n", 6);
		if (argc <= 1)
			write(2, "No file path given as an argument\n", 34);
		else if (argc == 2 && argv[1] == NULL)
			write(2, "NULL argument\n", 14);
		else
			write(2, "Too many arguments\n", 19);
		return (-1);
	}
	return (0);
}

static int	check_file_path(char **file_path, char **error_msg, const char *arg)
{
	int		result;
	int		arg_len;
	char	*extension;

	result = -1;
	*error_msg = "The file path given as an argument is empty\n";
	if (arg == NULL)
		return (result);
	*file_path = ft_strtrim(arg, " \t\n\"\'()[]{}%$#@!~^&*+-_=:;\\<>,?`");
	if (*file_path == NULL)
		return (result);
	arg_len = ft_strlen(*file_path);
	if (arg_len == 0)
		return (result);
	*error_msg = "The file name given as an argument is not ended by .cub\n";
	if (arg_len < 5)
		return (result);
	extension = ft_substr(*file_path, arg_len - 4, 4);
	if (ft_strncmp(extension, ".cub", 4) == 0)
	{
		*error_msg = NULL;
		result = 0;
	}
	free(extension);
	return (result);
}

int	parse_c3d_args(char **file_path, const int argc, const char **argv)
{
	char	*error_msg;

	error_msg = NULL;
	*file_path = NULL;
	if (check_nb_args(argc, argv) < 0)
		return (-1);
	if (check_file_path(file_path, &error_msg, argv[1]) < 0)
	{
		write(2, "Error\n", 6);
		if (error_msg)
			write(2, error_msg, ft_strlen(error_msg));
		if (*file_path)
		{
			free(*file_path);
			*file_path = NULL;
		}
		return (-1);
	}
	return (0);
}
