/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:20:50 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 12:08:51 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_lstadd_front                            */
/* -------------------------------------------------------------------------- */
/* This function adds element "new" at the beggining of the list lst.         */
/* Inputs :                                                                   */
/*  - t_list **lst : a pointer to the list to which we will add an element    */
/*  - t_list *new  : the element to add at the beginning of the list          */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if ((lst) && (new))
	{
		new->next = *lst;
		*lst = new;
	}
}
