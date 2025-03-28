/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:43:28 by rmorice           #+#    #+#             */
/*   Updated: 2024/06/05 09:03:29 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_file
{
	int				fd;
	char			*rest;
	struct s_file	*next;
}	t_file;

char	*get_next_line(int fd);
size_t	strl_ch(const char *s, char ch);
t_file	*ft_lstnew_gnl(const int fd);
void	ft_lstadd_back_gnl(t_file **lst, t_file *new_elt);
t_file	*find_node_fd(t_file *temp, int fd);
t_file	*to_free(t_file *file, t_file **temp);

#endif
