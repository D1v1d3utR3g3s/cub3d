/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:08:06 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 12:04:11 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                 ft_lstnew                                  */
/* -------------------------------------------------------------------------- */
/* This function creates an element and return it.                            */
/* Inputs :                                                                   */
/*  - void *content : the content of the new element created                  */
/* Return :                                                                   */
/*  - t_list * : the new element created (if no problem was encounter)        */
/*  - NULL : otherwise                                                        */
/* ************************************************************************** */
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = NULL;
	new = malloc(sizeof(t_list));
	if (!new)
		return (new);
	new->content = content;
	new->next = NULL;
	return (new);
}
