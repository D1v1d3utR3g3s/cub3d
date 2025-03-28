/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:29:37 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 11:49:41 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_lstiter                                 */
/* -------------------------------------------------------------------------- */
/* This function applied the function f to each element of the list lst.      */
/* * Inputs :                                                                 */
/*  - t_list **lst : a pointer to the first element to apply f to             */
/*  - void   (*f)  : a pointer to the f function                              */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if ((!lst) || (!f))
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
