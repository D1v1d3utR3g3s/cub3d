/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:38:36 by hauerbac          #+#    #+#             */
/*   Updated: 2025/02/11 19:14:44 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"
#include "../libft/includes/get_next_line_bonus.h"

static void	free_raw_data(char **raw_data, int *nb_lines)
{
	free(*raw_data);
	*raw_data = NULL;
	*nb_lines = 0;
}

/* ************************************************************************** */
/*                            ft_strjoin_with_free                            */
/* -------------------------------------------------------------------------- */
/* This function creates a string that is the combination of s1 and s2. (s2   */
/* is add at the end of s1)                                                   */
/* s1 and s2 are then free and the string created is return                   */
/* Input :                                                                    */
/*  - char *s1 : the first string to join                                     */
/*  - char *s2 : the string to add at the end of the previous string          */
/* Return :                                                                   */
/*  - char *: the string obtained by adding s2 at the end of s1               */
/* ************************************************************************** */
static char	*ft_strjoin_with_free(char *s1, char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (s1_len == 0 && s2_len == 0)
		result[0] = '\0';
	else
	{
		if (s1_len > 0)
		{
			ft_strlcpy(result, s1, s1_len + 1);
			free(s1);
		}
		if (s2_len > 0)
		{
			ft_strlcpy(result + s1_len, s2, s2_len + 1);
			free(s2);
		}
	}
	return (result);
}

/* ************************************************************************** */
/*                                 concatene                                  */
/* -------------------------------------------------------------------------- */
/* This function concatenes the whole raw data extracted from the given file  */
/* descriptor into a single string                                            */
/* Input :                                                                    */
/*  - fd : a file descriptor                                                  */
/* Return :                                                                   */
/*  - 0 : if everything went well and was created successfully                */
/*  - 1 : if a problem has be encountered                                     */
/* ************************************************************************** */
static int	concatene(char **raw_data, int *nb_lines, char **error_msg,
			const int fd)
{
	int		result;
	char	*a_line;

	result = 0;
	a_line = "Start";
	while (a_line)
	{
		a_line = get_next_line(fd);
		if (a_line)
		{
			*raw_data = ft_strjoin_with_free(*raw_data, a_line);
			if (!*raw_data)
			{
				*error_msg = "ERROR - with the c3d scene file \
					      loading : malloc error\n";
				result = 1;
			}
			(*nb_lines)++;
		}
	}
	return (result);
}

/* ************************************************************************** */
/*                                 read_file                                  */
/* -------------------------------------------------------------------------- */
/* This function reads a scene file for creating a string with the whole raw  */
/* data extracted from the given file                                         */
/* Input :                                                                    */
/*  - const char *file_path : a scene file path                               */
/* Return :                                                                   */
/*  - 0 : if everything went well and was created successfully                */
/*  - 1 : if a problem has be encountered                                     */
/* ************************************************************************** */
static int	read_file(char **raw_data, int *nb_lines, char **error_msg,
				const char *file_path)
{
	int	result;
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		*error_msg = "ERROR - No such file/wrong read rights on file\n";
		return (1);
	}
	result = concatene(raw_data, nb_lines, error_msg, fd);
	if (fd != -1 && close(fd) == -1)
	{
		if (result == 0)
			*error_msg = "ERROR - File close failed\n";
		result = 1;
	}
	return (result);
}

/* ************************************************************************** */
/*                                 load_scene                                 */
/* -------------------------------------------------------------------------- */
/* This function loads a scene file in order to initialise the basic c3d data */
/* Input :                                                                    */
/*  - const char *file_path : a scene file path                               */
/* Return :                                                                   */
/*  - 0 : if everything went well and was created successfully                */
/*  - 1 : if a problem has be encountered                                     */
/* ************************************************************************** */
int	load_scene(t_c3d_data *c3d, const char *file_path)
{
	int		result;
	char	*raw_data;
	int		nb_lines;

	nb_lines = 0;
	raw_data = NULL;
	result = read_file(&raw_data, &nb_lines, &c3d->error_msg, file_path);
	/*if (result == 0 && raw_data)
		result = first_checks(raw_data, nb_lines, &c3d->error_msg);
	if (result == 0 && raw_data)
		result = parse(raw_data, nb_lines, &c3d->error_msg);
	if (result == 0 && raw_data)
		result = checks(raw_data, nb_lines, &c3d->error_msg);
	if (result == 0 && raw_data)
		result = reformate(c3d, raw_data, nb_lines);*/
	if (raw_data)
		free_raw_data(&raw_data, &nb_lines);
	return (result);
}
