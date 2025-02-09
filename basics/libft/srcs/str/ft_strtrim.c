/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:16:41 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 14:15:50 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_isinset                                 */
/* -------------------------------------------------------------------------- */
/* This function checks if a character is in a string                         */
/* Inputs :                                                                   */
/*  - char       c    : the character that we are looking for                 */
/*  - char const *set : the string in which we are looking                    */
/* Return :                                                                   */
/*  - 1 : if c is in set                                                      */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
static int	ft_isinset(char c, char const *set)
{
	int		i;
	char	*s_set;

	i = 0;
	s_set = (char *)set;
	while (s_set[i] != '\0')
	{
		if (c == s_set[i])
			return (1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                 ft_strlastset                              */
/* -------------------------------------------------------------------------- */
/* This function returns the last consecutive occurence of a char existing in */
/* set from the beginning of s.                                               */
/* Inputs :                                                                   */
/*  - char const *s   : the string in which we are looking                    */
/*  - char const *set : the string which contained the char we are looking    */
/*   for                                                                      */
/* Return :                                                                   */
/*  - unsigned int : the position of the last occurence                       */
/*  - 0 : if a problem occured                                                */
/* ************************************************************************** */
static unsigned int	ft_strlastset(char const *s, char const *set)
{
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		while ((s[i] != '\0') && (ft_isinset(s[i], set)))
			i++;
		if (!ft_isinset(s[i], set))
			return (i);
	}
	return (i);
}

/* ************************************************************************** */
/*                                 ft_strrlastset                             */
/* -------------------------------------------------------------------------- */
/* This function returns the last consecutive occurence of a char existing in */
/* set from the end of s.                                                     */
/* Inputs :                                                                   */
/*  - char const *s   : the string in which we are looking                    */
/*  - char const *set : the string which contained the char we are looking    */
/*   for                                                                      */
/* Return :                                                                   */
/*  - unsigned int : the position of the last occurence                       */
/*  - 0 : if a problem occured                                                */
/* ************************************************************************** */
static unsigned int	ft_strrlastset(char const *s, char const *set)
{
	unsigned int	i;

	if (!s)
		return (0);
	i = ft_strlen((char *)s) - 1;
	while (s[i] != '\0')
	{
		while ((i >= 0) && (ft_isinset(s[i], set)))
			i--;
		if (!ft_isinset(s[i], set))
			return (i);
	}
	return (i);
}

/* ************************************************************************** */
/*                                 ft_strtrim                                 */
/* -------------------------------------------------------------------------- */
/* This function returns a copy of s1 without the characters specified in set */
/* at the beginning and the end of s1                                         */
/* Inputs :                                                                   */
/*  - char const *s1  : the string that we want to trim                       */
/*  - char const *set : an array of the characters by which we trim           */
/* Return :                                                                   */
/*  - char * : a string that is the copy of s1 trimmed                        */
/*  - ft_calloc(1, sizeof(char)) : if a problem occured                       */
/* ************************************************************************** */
char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*trim;

	if (!s1)
		return (ft_calloc(1, sizeof(char)));
	if (!set)
		return (ft_strdup(s1));
	start = ft_strlastset(s1, set);
	if (s1[start] == '\0')
		return (ft_calloc(1, sizeof(char)));
	end = ft_strrlastset(s1, set);
	if (start > end)
		return (ft_calloc(1, sizeof(char)));
	trim = NULL;
	trim = malloc(sizeof(char) * (end - start + 2));
	if (!trim)
		return (trim);
	ft_strlcpy(trim, s1 + start, end - start + 2);
	return (trim);
}
