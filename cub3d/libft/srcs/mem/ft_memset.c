/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:54:57 by rmorice           #+#    #+#             */
/*   Updated: 2024/06/13 13:44:25 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* ************************************************************************** */
/*                                 ft_memset                                  */
/* -------------------------------------------------------------------------- */
/* This function replaces n bytes of the string src by c.                     */
/* Inputs :                                                                   */
/*  - void   *s : the string that is modified                                 */
/*  - int    c  : the char that will be used for the replacing                */
/*  - size_t n  : the number of bytes to change                               */
/* Return :                                                                   */
/*  - void * : the string obtained                                            */
/* ************************************************************************** */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;
	unsigned char	*str;

	i = 0;
	uc = c ;
	str = s;
	while (i < n)
	{
		str[i] = uc;
		i++;
	}
	return (s);
}
