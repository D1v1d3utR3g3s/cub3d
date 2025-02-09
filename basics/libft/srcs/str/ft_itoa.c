/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:03:38 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 11:10:48 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_len_nb                                  */
/* -------------------------------------------------------------------------- */
/* This function return the size of the array needed to do the translation of */
/* nb                                                                         */
/* Inputs :                                                                   */
/*  - int nb : the integer to translate                                       */
/*  - unsigned int size : the size needed at every step (initial value 0)     */
/* Return :                                                                   */
/*  - static unsigned int : the size needed for the string                    */
/* ************************************************************************** */
static unsigned int	ft_len_nb(int nb, unsigned int size)
{
	long int	n;

	n = nb;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	if (n < 10)
		size++;
	else
	{
		while (n > 9)
		{
			n /= 10;
			size++;
		}
		size++;
	}
	return (size);
}

/* ************************************************************************** */
/*                                 ft_strnbr                                  */
/* -------------------------------------------------------------------------- */
/* This function fills the string s by transposing the integer n into chars.  */
/* Inputs :                                                                   */
/*  - char *s : the string to complete                                        */
/*  - int  n  : the integer to translate                                      */
/*  - int  i  : the position in the string                                    */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
static void	ft_strnbr(char *s, int n, int i)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	if (nb < 10)
		s[i] = nb + '0';
	else
	{
		i--;
		ft_strnbr(s, nb / 10, i);
		i++;
		s[i] = nb % 10 + '0';
	}
}

/* ************************************************************************** */
/*                                 ft_itoa                                    */
/* -------------------------------------------------------------------------- */
/* This function does the opposite of the atoi function. This function        */
/* translates an int to a string.                                             */
/* Inputs :                                                                   */
/*  - int n : the integer to translate                                        */
/* Return :                                                                   */
/*  - char * : the array of char obtained by translating n                    */
/*  - NULL : otherwise                                                        */
/* ************************************************************************** */
char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	size;

	size = ft_len_nb(n, 0);
	str = NULL;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_strnbr(str, n, size - 1);
	str[size] = '\0';
	return (str);
}
