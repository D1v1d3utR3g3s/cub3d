/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:11:52 by rmorice           #+#    #+#             */
/*   Updated: 2024/07/04 13:25:17 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_count_split                             */
/* -------------------------------------------------------------------------- */
/* This function counts the number of "words" that can be found in s          */
/* separated by (at least one) c.                                             */
/* Inputs :                                                                   */
/*  - char const *s : the string in which we want to count                    */
/*  - char       c  : the separator use to separate "words"                   */
/* Return :                                                                   */
/*  - unsigned int : the number of "words" found                              */
/* ************************************************************************** */
static unsigned int	ft_count_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while ((s[i] != '\0') && (s[i] == c))
			i++;
		if (s[i] != '\0')
			count++;
		while ((s[i] != '\0') && (s[i] != c))
			i++;
	}
	return (count);
}

/* ************************************************************************** */
/*                                 ft_part_split                              */
/* -------------------------------------------------------------------------- */
/* This function creates a string that contained a "word" and return it.      */
/* Inputs :                                                                   */
/*  - char const   *s    : the string that we want to split                   */
/*  - unsigned int start : the first index of a "word"                        */
/*  - unsigned int end   : the last index of the same "word"                  */
/* Return :                                                                   */
/*  - char * : the "word" separated                                           */
/* ************************************************************************** */
static char	*ft_part_split(char const *s, unsigned int start, unsigned int end)
{
	char			*part;
	unsigned int	i;

	if (end < start)
		return (ft_calloc(1, sizeof(char)));
	part = NULL;
	part = malloc(sizeof(char) * (end - start + 1));
	if (!part)
		return (part);
	i = 0;
	while (start + i < end)
	{
		part[i] = s[start + i];
		i++;
	}
	part[i] = '\0';
	return (part);
}

/* ************************************************************************** */
/*                                 ft_complete_split                          */
/* -------------------------------------------------------------------------- */
/* This function creates an array of strings that contained all the "words"   */
/* and returns it.                                                            */
/* Inputs :                                                                   */
/*  - char const *s      : the string we want to split                        */
/*  - char       c       : the separator                                      */
/*  - char       **split : the array of strings                               */
/* Return :                                                                   */
/*  - char ** : the array of strings that have been split                     */
/* ************************************************************************** */
char	**complete_split(char const *s, char c, char **split)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	start;

	i = 0;
	j = 0;
	start = 0;
	while (s[i] != '\0')
	{
		while ((s[i] != '\0') && (s[i] == c))
			i++;
		start = i;
		while ((s[i] != '\0') && (s[i] != c))
			i++;
		if (start != i)
		{
			split[j] = ft_part_split(s, start, i);
			j++;
		}
	}
	split[j] = 0;
	return (split);
}

/* ************************************************************************** */
/*                                 ft_split                                   */
/* -------------------------------------------------------------------------- */
/* This function creates an array of strings then call the function needed to */
/* complete it.                                                               */
/* Inputs :                                                                   */
/*  - char const *s : the string that we want to split                        */
/*  - char       c  : the separator                                           */
/* Return :                                                                   */
/*  - char ** : the array of strings that have been split                     */
/*  - NULL : if a problem has be encountered                                  */
/* ************************************************************************** */
char	**ft_split(char const *s, char c)
{
	char			**split;
	unsigned int	count_split;

	if (!s)
		return (NULL);
	count_split = ft_count_split(s, c);
	split = NULL;
	split = malloc(sizeof(char *) * (count_split + 1));
	if (!split)
		return (NULL);
	split = complete_split(s, c, split);
	return (split);
}
