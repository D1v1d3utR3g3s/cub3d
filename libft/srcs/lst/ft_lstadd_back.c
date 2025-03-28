/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:44:54 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 11:15:04 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_lstadd_back                             */
/* -------------------------------------------------------------------------- */
/* This function adds element "new" at the end of the list lst.               */
/* Inputs :                                                                   */
/*  - t_list **lst : a pointer to the list to which we will add an element    */
/*  - t_list *new  : the element to add at the end of the list                */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l_temp;

	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		l_temp = ft_lstlast(*lst);
		l_temp->next = new;
	}
}
