/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:32:59 by rmorice           #+#    #+#             */
/*   Updated: 2024/06/13 13:43:14 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* ************************************************************************** */
/*                                 ft_isalnum                                 */
/* -------------------------------------------------------------------------- */
/* This function check if c is (alphabetic || numeric) or not                 */
/* Inputs :                                                                   */
/*  - int c : the character to check (refers to the Ascii table)              */
/* Return :                                                                   */
/*  - 1 : if c is alphabetic or numeric                                       */
/*  - 0 : otherwise                                                           */
/* ************************************************************************** */
int	ft_isalnum(int c)
{
	if ((ft_isalpha(c)) || (ft_isdigit(c)))
		return (1);
	return (0);
}
