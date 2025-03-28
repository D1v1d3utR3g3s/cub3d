/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:57:50 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 13:44:04 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_strlcpy                                 */
/* -------------------------------------------------------------------------- */
/* This function copies size char of src in dst.                              */
/* Inputs :                                                                   */
/*  - char       *dst : the string which receives the copy                    */
/*  - const char *src : the string which is copied in dest                    */
/*  - size_t     size : the number of elements which  are copied              */
/* Return :                                                                   */
/*  - size_t : the total lenght of the string created (len_src)               */
/*  - 0 : if a problem has been encounter                                     */
/* ************************************************************************** */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if ((!dst) || (!src))
		return (0);
	i = 0;
	if (size > 0)
	{
		while ((src[i] != '\0') && (i < size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
