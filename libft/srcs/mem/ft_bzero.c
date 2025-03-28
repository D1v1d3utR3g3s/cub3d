/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:41:52 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/23 17:41:59 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_bzero                                   */
/* -------------------------------------------------------------------------- */
/* This function replaces the data in n bytes of s, starting where s is       */
/* pointed, by 0 (NULL, '\0').                                                */
/* Inputs :                                                                   */
/*  - void   *s : a pointer to the beginning of the string that should be     */
/*   overwrite                                                                */
/*  - size_t n  : the number of bytes that should be overwrite                */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	ft_bzero(void *s, size_t n)
{
	if ((s) && (n != 0))
		ft_memset(s, '\0', n);
}
