/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:35:12 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 12:00:21 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_lstmap                                  */
/* -------------------------------------------------------------------------- */
/* This function creates a list that is the result of applying f to every     */
/* element of lst                                                             */
/* Inputs :                                                                   */
/*  - t_list **lst  : a pointer to an element of lst                          */
/*  - void   *(*f)  : a pointer to the function f                             */
/*  - void   *(del) : a pointer to the function del                           */
/* Return :                                                                   */
/*  - t_list * : the list created (if no problems were encounter)             */
/*  - NULL : otherwise                                                        */
/* ************************************************************************** */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l_map;
	t_list	*l_elt;

	if ((!lst) || (!f) || (!del))
		return (NULL);
	l_map = NULL;
	l_elt = NULL;
	while (lst)
	{
		l_elt = ft_lstnew(f(lst->content));
		if (!l_elt)
			return (NULL);
		ft_lstadd_back(&l_map, l_elt);
		lst = lst->next;
	}
	return (l_map);
}
