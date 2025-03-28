/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:52:55 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 11:45:39 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
/*                                 ft_lstdelone                               */
/* -------------------------------------------------------------------------- */
/* This function deletes and frees the element that lst points to             */
/* * Inputs :                                                                 */
/*  - t_list **lst  : a pointer to the element to delete and free             */
/*  - void   (*del) : a pointer to the del function                           */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if ((!lst) || (!del))
		return ;
	del(lst->content);
	free(lst);
}
