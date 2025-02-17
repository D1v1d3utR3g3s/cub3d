/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:18:22 by rmorice           #+#    #+#             */
/*   Updated: 2024/06/13 13:43:48 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* ************************************************************************** */
/*                                 ft_memchr                                  */
/* -------------------------------------------------------------------------- */
/* This function returns the first instance of c in the initial n bytes of s. */
/* Inputs :                                                                   */
/*  - const void *s  : the string in which we look for c                      */
/*  - int        c   : the char  we are looking for                           */
/*  - size_t     n   : the number of bytes compared                           */
/* Return :                                                                   */
/*  - void * : a pointer to the first instance of c in s                      */
/*  - NULL : if a problem is encounter or c isn't found                       */
/* ************************************************************************** */
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		ch;
	size_t				i;

	str = s;
	ch = c;
	i = 0;
	if (!s)
		return (NULL);
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
