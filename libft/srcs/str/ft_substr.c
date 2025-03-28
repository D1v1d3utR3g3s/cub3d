/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 08:56:38 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 14:22:12 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_substr                                  */
/* -------------------------------------------------------------------------- */
/* This function returns a copy of a part of s1 starting at start and which   */
/* length is len.                                                             */
/* Inputs :                                                                   */
/*  - char const   *s    : the initial string                                 */
/*  - unsigned int start : the index of the first character to copied         */
/*  - size_t       len   : the len of the return string                       */
/* Return :                                                                   */
/*  - char * : the substring obtained                                         */
/*  - NULL || ft_calloc(1, sizeof(char)) : if a problem occured               */
/* ************************************************************************** */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	len_s;
	size_t	i;

	if (!s)
		return ((char *)s);
	len_s = ft_strlen((char *)s);
	if ((len == 0) || (start >= len_s))
		return (ft_calloc(1, sizeof(char)));
	sub_str = NULL;
	if (len_s - start < len)
		sub_str = malloc(sizeof(char) * (len_s - start + 1));
	else
		sub_str = malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	i = 0;
	while ((s[start + i] != '\0') && (i < len))
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
