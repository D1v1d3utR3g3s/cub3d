/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roxane <roxane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:10:25 by rmorice           #+#    #+#             */
/*   Updated: 2025/02/14 18:48:51 by roxane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_strrchr                                 */
/* -------------------------------------------------------------------------- */
/* This function returns a pointer to the first occurrence of c in the string */
/* s starting by the end of s.                                                */
/* Inputs :                                                                   */
/*  - char const *s : the string where we are looking for c                   */
/*  - char       c  : the char that we are looking for                        */
/* Return :                                                                   */
/*  - char * : a pointer to the first occurence of c starting by the end      */
/*  - NULL : if a problem has be encountered                                  */
/* ************************************************************************** */
char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	ch;
	int				i;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	if (ch > 127)
		return ((char *)str);
	i = ft_strlen((char *)str);
	while ((i > 0) && (str[i] != ch))
		i--;
	if (str[i] == ch)
		return ((char *)str + i);
	return (NULL);
}
