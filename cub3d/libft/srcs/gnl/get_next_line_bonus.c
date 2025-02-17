/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:42:47 by rmorice           #+#    #+#             */
/*   Updated: 2024/07/04 11:59:35 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

/* ************************************************************************** */
/*                               contained_nl                                 */
/* -------------------------------------------------------------------------- */
/* This function checks if a string contain a '\n'                            */
/* Input :                                                                    */
/*  - const char *s : the string that we want to check                        */
/* Return :                                                                   */
/*  - 1 : if a '\n' is encounter                                              */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
static int	contained_nl(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                               ft_strjoin_gnl                               */
/* -------------------------------------------------------------------------- */
/* This function creates a string that is the concatenation of s1 and s2.     */
/* Inputs :                                                                   */
/*  - char *s1 : the first string to concatenate                              */
/*  - const char *s2 : the second string to concatenate                       */
/* Return :                                                                   */
/*  - char * : the string obtained by concatenation of s1 and s2              */
/*  - NULL : if a problem is encounter                                        */
/* ************************************************************************** */
static char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s2)
		return (s1);
	str = malloc(sizeof(char) * (strl_ch(s1, 0) + strl_ch(s2, 0) + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (s1)
	{
		i--;
		while (s1[++i])
			str[i] = s1[i];
		free(s1);
	}
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                               complete_rest                                */
/* -------------------------------------------------------------------------- */
/* This function call the read function until a '\n' has been found or the    */
/* end of file has been encoutered and add the buffer obained to a string     */
/* Inputs :                                                                   */
/*  - int fd : the file descriptor                                            */
/*  - char *rest : a string to complete                                       */
/* Return :                                                                   */
/*  - char * : a string that contained everything that has been read and not  */
/* yet return by get_next_line                                                */
/*  - NULL : if a problem occured or if the file was empty                    */
/* ************************************************************************** */
static char	*complete_rest(int fd, char *rest)
{
	char	*buf;
	int		ret;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ret = 1;
	while ((!contained_nl(rest)) && (ret))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if ((ret == -1) || ((ret == 0) && (!rest)))
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		rest = ft_strjoin_gnl(rest, buf);
	}
	free(buf);
	return (rest);
}

/* ************************************************************************** */
/*                                  split_nl                                  */
/* -------------------------------------------------------------------------- */
/* This function splits a string in two strings : a line (the string until    */
/* the first '\n' (include) or EOF (=> '\0' without any '\n') and a rest (the */
/* string after the first '\n', NULL if there is no '\n' int he initial str.  */
/* Inputs :                                                                   */
/*  - char **line : a pointeur to a string (NULL)                             */
/*  - char **rest : a pointeur to the string to split and adapt               */
/*  - int len_nl : the size of the line that will be extract (len until the   */
/*  first '\n' include or EOF)                                                */
/* Return :                                                                   */
/*  - None                                                                    */
/* ************************************************************************** */
static char	*split_nl(char **line, char *rest, int len_nl)
{
	int		len;
	int		i;
	char	*new_rest;

	if (!rest || (rest[0] == '\0'))
		return (NULL);
	if ((rest) && (rest[len_nl] == '\n'))
		len_nl++;
	len = strl_ch(rest, '\0');
	(*line) = malloc(sizeof(char) * (len_nl + 1));
	if (!(*line))
		return (rest);
	i = -1;
	while (++i < len_nl)
		(*line)[i] = rest[i];
	(*line)[i] = '\0';
	if (len == len_nl)
		return (NULL);
	new_rest = malloc(sizeof(char) * (len - len_nl + 1));
	if (!new_rest)
		return (NULL);
	while (++i <= len)
		new_rest[i - len_nl - 1] = rest[i - 1];
	new_rest[i - len_nl - 1] = '\0';
	return (new_rest);
}

/* ************************************************************************** */
/*                               get_next_line                                */
/* -------------------------------------------------------------------------- */
/* This function browses a file and returns the first line encountered        */
/* (delimited by a '\n' or EOF)                                               */
/* Inputs :                                                                   */
/*  - int fd : the file descriptor                                            */
/* Return :                                                                   */
/*  - char * : the first line encountered (NULL if a problem occured or if    */
/*  the file is empty)                                                        */
/* ************************************************************************** */
char	*get_next_line(int fd)
{
	static t_file	*file;
	t_file			*tp;
	char			*line;
	char			*new_rest;

	if ((fd < 0) || (fd >= 1024) || BUFFER_SIZE <= 0)
		return (NULL);
	if (!file)
		ft_lstadd_back_gnl(&file, ft_lstnew_gnl(fd));
	if (!file)
		return (NULL);
	tp = file;
	tp = find_node_fd(tp, fd);
	if (!tp)
		return (NULL);
	tp->rest = complete_rest(fd, tp->rest);
	line = NULL;
	new_rest = split_nl(&line, tp->rest, strl_ch(tp->rest, '\n'));
	free(tp->rest);
	tp->rest = ft_strdup(new_rest);
	free(new_rest);
	file = to_free(file, &tp);
	return (line);
}
