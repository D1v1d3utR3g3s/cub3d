/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:07:36 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 13:22:20 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_strdup                                  */
/* -------------------------------------------------------------------------- */
/* This function duplicates the string s                                      */
/* Inputs :                                                                   */
/*  - char const *s : the string we want to duplicate                         */
/* Return :                                                                   */
/*  - char * : the duplicated string                                          */
/*  - NULL : if a problem has be encountered                                  */
/* ************************************************************************** */
char	*ft_strdup(const char *s)
{
	char			*str;
	char			*dup;
	unsigned int	len;

	str = (char *)s;
	len = ft_strlen(str);
	dup = NULL;
	if (!str)
		return (NULL);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	dup[len] = '\0';
	while (len > 0)
	{
		len--;
		dup[len] = str[len];
	}
	return (dup);
}
