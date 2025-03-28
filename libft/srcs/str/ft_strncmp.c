/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:12:27 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 13:53:47 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_strncmp                                 */
/* -------------------------------------------------------------------------- */
/* This function returns the compared value of the initial n bytes of two     */
/* strings.                                                                   */
/* Inputs :                                                                   */
/*  - const void *s1  : the first string to compared                          */
/*  - const void *s2  : the second string to compared                         */
/*  - size_t     n    : the number of bytes to compared                       */
/* Return :                                                                   */
/*  - int : the difference between s1 and s2 in the ascii order               */
/*  - 0 : if no bytes should be compared                                      */
/* ************************************************************************** */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0') && (i < n - 1)
		&& (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
