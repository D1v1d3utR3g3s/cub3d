/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:40:02 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 10:11:25 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_isspace                                 */
/* -------------------------------------------------------------------------- */
/* This function checks if a character is in space(3)                         */
/* Inputs :                                                                   */
/*  - int ch : a character identified by it's value in the Ascii table        */
/* Return :                                                                   */
/*  - 1 : if ch is in space(3)                                                */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
static int	ft_isspace(int ch)
{
	if ((ch == ' ') || ((ch >= 9) && (ch <= 13)))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                 ft_atoi                                    */
/* -------------------------------------------------------------------------- */
/* This function translates a string formatted according to the rules         */
/* (cf. man) into a int.                                                      */
/* Inputs :                                                                   */
/*  - const char *nptr : the string to translate                              */
/* Return :                                                                   */
/*  - the numerical value obtained : if no problem is encountered             */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
int	ft_atoi(const char *nptr)
{
	long int	nb;
	int			sign;
	int			i;

	i = 0;
	nb = 0;
	sign = 0;
	while ((nptr[i] != '\0') && (ft_isspace(nptr[i])))
		i++;
	if (nptr[i] == '\0')
		return (0);
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign = 1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	if (sign == 1)
		nb *= -1;
	return (nb);
}
