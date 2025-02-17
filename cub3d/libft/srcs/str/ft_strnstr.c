/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:30:11 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 13:59:49 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_strnstr                                 */
/* -------------------------------------------------------------------------- */
/* This function return the first occurence of the string "little" in the len */
/* firsts elements of the string "big".                                       */
/* Inputs :                                                                   */
/*  - const char *big    : the string in which we are looking                 */
/*  - const char *little : the string that we are looking for                 */
/*  - size_t     len     : the number of bytes to compared                    */
/* Return :                                                                   */
/*  - char * : a pointer to the first occurence of "little"                   */
/*  - NULL : if a problem occured                                             */
/* ************************************************************************** */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen((char *)little) == 0)
		return ((char *)big);
	i = 0;
	if (len > 0)
	{
		while ((big[i] != '\0') && (i < len))
		{
			j = 0;
			while ((i + j < len) && (big[i + j] == little[j])
				&& (little[j] != '\0'))
				j++;
			if (little[j] == '\0')
				return ((char *)big + i);
			i++;
		}
	}
	if ((i < len) && (big[i] == little[0]))
		return ((char *)big + i);
	return (NULL);
}
