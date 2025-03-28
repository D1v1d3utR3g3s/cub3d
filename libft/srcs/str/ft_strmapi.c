/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:25:34 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 14:16:31 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_strmapi                                 */
/* -------------------------------------------------------------------------- */
/* This function creates a new string which is the result of the application  */
/* of the function f to each element of s.                                    */
/* Inputs :                                                                   */
/*  - const char *s   : the initial string                                    */
/*  - char       (*f) : a pointer to the function f                           */
/* Return :                                                                   */
/*  - char * : the string generates                                           */
/* ************************************************************************** */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	str = NULL;
	str = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
