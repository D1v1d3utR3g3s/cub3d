/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:37 by rmorice           #+#    #+#             */
/*   Updated: 2024/06/13 13:43:58 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* ************************************************************************** */
/*                                 ft_memmove                                 */
/* -------------------------------------------------------------------------- */
/* This function copies n bytes of the string src to dest. The memory overlap */
/* is handled.                                                                */
/* Inputs :                                                                   */
/*  - void       *dest : the string where we copy src                         */
/*  - const void *src  : the string that is copied                            */
/*  - size_t     n     : the number of bytes to copy                          */
/* Return :                                                                   */
/*  - void * : the string obtained                                            */
/*  - NULL : if a problem is encounter                                        */
/* ************************************************************************** */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	if ((!src) || (!dest))
		return (NULL);
	d = dest;
	s = src;
	i = 0;
	while (i < n)
	{
		if (dest > src)
			d[n - 1 - i] = s[n - 1 - i];
		else
			d[i] = s[i];
		i++;
	}
	return (dest);
}
