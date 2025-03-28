/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:26:01 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 13:39:55 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_strlcat                                 */
/* -------------------------------------------------------------------------- */
/* This function concatenates size char of src at the end of dest.            */
/* Inputs :                                                                   */
/*  - char       *dest : the string that receive the concatenation            */
/*  - const char *src  : the string that is "copy" at the end of dest         */
/*  - size_t     size  : the number of elements that are add                  */
/* Return :                                                                   */
/*  - size_t : the total lenght of the string created                         */
/*  - 0 or len_src + size : if a problem has been encounter                   */
/* ************************************************************************** */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	if ((!dst) || (!src))
		return (0);
	len_dst = ft_strlen(dst);
	len_src = ft_strlen((char *)src);
	if (len_dst >= size)
		return (len_src + size);
	i = 0;
	while ((src[i] != '\0') && (len_dst + i < size - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
