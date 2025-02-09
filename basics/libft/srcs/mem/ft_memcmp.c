/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:22:52 by rmorice           #+#    #+#             */
/*   Updated: 2024/06/13 13:43:51 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* ************************************************************************** */
/*                                 ft_memcmp                                  */
/* -------------------------------------------------------------------------- */
/* This function returns the compared value of the initial n bytes of two     */
/* strings.                                                                   */
/* Inputs :                                                                   */
/*  - const void *s1 : the first string to compared                           */
/*  - const void *s2 : the second string to compared                          */
/*  - size_t     n   : the number of bytes to compared                        */
/* Return :                                                                   */
/*  - int : the difference between s1 and s2 in the ascii order               */
/*  - 0 : if no bytes should be compared                                      */
/* ************************************************************************** */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	if (n == 0)
		return (0);
	str1 = s1;
	str2 = s2;
	i = 0;
	while ((i < n - 1) && (str1[i] == str2[i]))
		i++;
	return (str1[i] - str2[i]);
}
