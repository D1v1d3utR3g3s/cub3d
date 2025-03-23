/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:43:13 by rmorice           #+#    #+#             */
/*   Updated: 2025/03/23 17:37:19 by hauerbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* ************************************************************************** */
/*                                 strlen_ch                                  */
/* -------------------------------------------------------------------------- */
/* This function returns the length of a string until first ch or '\0'        */
/* Input :                                                                    */
/*  - const char *s : the string whose size we want                           */
/* Return :                                                                   */
/*  - size_t : the lenght of the string                                       */
/* ************************************************************************** */
size_t	strl_ch(const char *s, char ch)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while ((s[len] != ch) && (s[len] != '\0'))
		len++;
	return (len);
}

/* ************************************************************************** */
/*                               ft_lstnew_gnl                                */
/* -------------------------------------------------------------------------- */
/* This function creates an element and return it.                            */
/* Input :                                                                    */
/*  - const char content : the content of the new element created             */
/* Return :                                                                   */
/*  - t_list * : the new element created (if no problem was encounter)        */
/*  - NULL : otherwise                                                        */
/* ************************************************************************** */
t_file	*ft_lstnew_gnl(const int fd)
{
	t_file	*new_elt;
	char	*rest;

	new_elt = NULL;
	new_elt = malloc(sizeof(t_file));
	if (!new_elt)
		return (NULL);
	rest = NULL;
	new_elt->fd = fd;
	new_elt->rest = rest;
	new_elt->next = NULL;
	return (new_elt);
}

/* ************************************************************************** */
/*                             ft_lstadd_back_gnl                             */
/* -------------------------------------------------------------------------- */
/* This function adds element "new_elt" at the end of the list lst.           */
/* Inputs :                                                                   */
/*  - t_list **lst : a pointer to the list to which we will add an element    */
/*  - t_list *new_elt  : the element to add at the end of the list            */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	ft_lstadd_back_gnl(t_file **lst, t_file *new_elt)
{
	t_file	*l_temp;

	if (!new_elt)
		return ;
	if (!(*lst))
		*lst = new_elt;
	else
	{
		l_temp = *lst;
		while (l_temp->next)
			l_temp = l_temp->next;
		l_temp->next = new_elt;
	}
}

/* ************************************************************************** */
/*                                find_node_fd                                */
/* -------------------------------------------------------------------------- */
/* This function browses a linked list until finding the element              */
/* corresponding to the processed file. If the node doesn't exist it creates  */
/* it.                                                                        */
/* Inputs :                                                                   */
/*  - t_file *temp : a linked list to browse                                  */
/*  - int fd : the criterion uses to refer to the processed file              */
/* Return :                                                                   */
/*  - t_file * : the address to the node                                      */
/*  - NULL : if a problem occured                                             */
/* ************************************************************************** */
t_file	*find_node_fd(t_file *temp, int fd)
{
	while ((temp) && (temp->next) && (temp->fd != fd))
		temp = temp->next;
	if (temp->fd != fd)
	{
		ft_lstadd_back_gnl(&temp, ft_lstnew_gnl(fd));
		if (!temp)
			return (NULL);
		temp = temp->next;
	}
	return (temp);
}

/* ************************************************************************** */
/*                                  to_free                                   */
/* -------------------------------------------------------------------------- */
/* This function free a node of a linked list.                                */
/* Input :                                                                    */
/*  - t_file *file : the first node of a linked list                          */
/*  - t_file **temp : the node to free                                        */
/* Return :                                                                   */
/*  - t_list * : the address of the first node of the linked list             */
/* ************************************************************************** */
t_file	*to_free(t_file *file, t_file **temp)
{
	t_file	*temp2;

	temp2 = file;
	if (!((*temp)->rest))
	{
		if (temp2->fd == (*temp)->fd)
		{
			file = file->next;
			free(temp2);
		}
		else
		{
			while ((temp2->next)->fd != (*temp)->fd)
				temp2 = temp2->next;
			temp2->next = (*temp)->next;
			free(*temp);
		}
	}
	return (file);
}
