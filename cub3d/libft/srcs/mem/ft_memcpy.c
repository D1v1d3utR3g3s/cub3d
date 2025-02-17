/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:56:13 by rmorice           #+#    #+#             */
/*   Updated: 2024/06/13 13:43:55 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* ************************************************************************** */
/*                                 ft_memcpy                                  */
/* -------------------------------------------------------------------------- */
/* This function copies the initial n bytes of the string src to dest.        */
/* Inputs :                                                                   */
/*  - void       *dest : the string where we copy src                         */
/*  - const void *src  : the string that is copied                            */
/*  - size_t     n     : the number of bytes to copy                          */
/* Return :                                                                   */
/*  - void * : the string obtained                                            */
/* ************************************************************************** */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*cdest;
	const char	*csrc;
	size_t		un;

	if ((!dest) || (!src))
		return (dest);
	cdest = dest;
	csrc = src;
	un = 0;
	while (un < n)
	{
		cdest[un] = csrc[un];
		un++;
	}
	return (dest);
}
