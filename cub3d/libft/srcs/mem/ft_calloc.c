/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:55:29 by rmorice           #+#    #+#             */
/*   Updated: 2024/06/13 13:43:43 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* ************************************************************************** */
/*                                 ft_calloc                                  */
/* -------------------------------------------------------------------------- */
/* This function allocates memory for an array of nbemb elements of size      */
/* bytes. The allocate memory is set to 0. This function doesn't allow        */
/* integer overflow.                                                          */
/* Inputs :                                                                   */
/*  - void   *s : a pointer to the beginning of the string that should be     */
/*   overwrite                                                                */
/*  - size_t n  : the number of bytes that should be overwrite                */
/* Return :                                                                   */
/*  - void * : a pointer to the allocate memory (if everything is OK)         */
/*  - NULL : otherwise                                                        */
/* ************************************************************************** */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if ((nmemb > INT_MAX) || (size > INT_MAX))
		return (NULL);
	mem = NULL;
	mem = malloc(size * nmemb);
	if ((!mem) || (size == 0) || (nmemb == 0))
		return (mem);
	ft_bzero(mem, nmemb * size);
	return (mem);
}
