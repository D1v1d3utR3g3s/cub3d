/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:33:48 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 12:07:32 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_lstsize                                 */
/* -------------------------------------------------------------------------- */
/* This function count the number of elements of lst.                         */
/* Inputs :                                                                   */
/*  - t_list *lst : a pointer to the beginning of lst                         */
/* Return :                                                                   */
/*  - int : the number of elements of lst                                     */
/* ************************************************************************** */
int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
