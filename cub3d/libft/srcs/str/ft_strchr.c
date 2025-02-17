/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roxane <roxane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:06:12 by rmorice           #+#    #+#             */
/*   Updated: 2025/02/14 18:38:46 by roxane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_strchr                                  */
/* -------------------------------------------------------------------------- */
/* This function returns a pointer to the first occurrence of c in s          */
/* Inputs :                                                                   */
/*  - char const *s : the string where we are looking for c                   */
/*  - char       c  : the char that we are looking for                        */
/* Return :                                                                   */
/*  - char * : a pointer to the first occurence of c                          */
/*  - NULL : if a problem has be encountered                                  */
/* ************************************************************************** */
char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	ch;
	int				i;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
//	if ((ch < 0) || (ch > 127))
	if (ch > 127)
		return ((char *)str);
	i = 0;
	while ((str[i] != '\0') && (str[i] != ch))
		i++;
	if (str[i] == ch)
		return ((char *)str + i);
	return (NULL);
}
