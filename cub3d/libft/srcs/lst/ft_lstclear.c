/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:00:47 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 11:42:41 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_lstclear                                */
/* -------------------------------------------------------------------------- */
/* This function deletes and frees the element that lst points to as well as  */
/* those after this one. The deletion is done with the function that "del"    */
/* points to.                                                                 */
/* * Inputs :                                                                 */
/*  - t_list **lst  : a pointer to the first element to delete and free       */
/*  - void   (*del) : a pointer to the del function                           */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l_temp;

	if ((!lst) || (!del))
		return ;
	while (*lst)
	{
		l_temp = *lst;
		*lst = (*lst)->next;
		del(l_temp->content);
		free(l_temp);
	}
	*lst = NULL;
}
