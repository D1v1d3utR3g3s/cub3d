/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:08:27 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 13:30:38 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_strjoin                                 */
/* -------------------------------------------------------------------------- */
/* This function creates a string that is the concatenation of s1 and s2.     */
/* Inputs :                                                                   */
/*  - char const *s1 : the first string to concatenate                        */
/*  - char const *s2 : the second string to concatenate                       */
/* Return :                                                                   */
/*  - char * : the string obtained by concatenation of s1 and s2              */
/*  - NULL : if a problem is encounter                                        */
/* ************************************************************************** */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	len_s1;
	unsigned int	len_s2;

	if ((!s1) || !(s2))
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	str = NULL;
	str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if ((!str))
		return (NULL);
	i = 0;
	while (i < len_s1 + len_s2)
	{
		if (i < len_s1)
			str[i] = s1[i];
		else
			str[i] = s2[i - len_s1];
		i++;
	}
	str[len_s1 + len_s2] = '\0';
	return (str);
}
