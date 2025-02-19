# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 09:21:28 by rmorice           #+#    #+#              #
#    Updated: 2024/07/04 11:17:12 by rmorice          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME		= libft.a

CHECK_DIR	= check/
MEM_DIR		= mem/
STR_DIR		= str/
WRITE_DIR	= write/
LST_DIR		= lst/
GNL_DIR		= gnl/

SRCS_DIR	= srcs/
OBJS_DIR	= objs/
HEAD_DIR	= includes/

CC			= cc
FLAGS		= -Wall -Wextra -Werror -g3 -gdwarf-2
AR			= ar -rc -s

CHECK_SRCS	= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c
CHECK_SRCS	:= $(addprefix $(CHECK_DIR), $(CHECK_SRCS))

MEM_SRCS	= ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c
MEM_SRCS	:= $(addprefix $(MEM_DIR), $(MEM_SRCS))

STR_SRCS	= ft_atoi.c ft_itoa.c ft_split.c ft_strchr.c ft_strdup.c \
			ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
			ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c
STR_SRCS	:= $(addprefix $(STR_DIR), $(STR_SRCS))

WRITE_SRCS	= ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_substr.c ft_tolower.c ft_toupper.c
WRITE_SRCS	:= $(addprefix $(WRITE_DIR), $(WRITE_SRCS))

LST_SRCS 	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
       ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
LST_SRCS	:= $(addprefix $(LST_DIR), $(LST_SRCS))

GNL_SRCS 	= get_next_line_bonus.c get_next_line_bonus_utils.c
GNL_SRCS	:= $(addprefix $(GNL_DIR), $(GNL_SRCS))

SOURCES = $(CHECK_SRCS)
SOURCES += $(MEM_SRCS)
SOURCES += $(STR_SRCS)
SOURCES += $(WRITE_SRCS)
SOURCES += $(LSTS_SRCS)
SOURCES += $(GNL_SRCS)
SRCS = $(addprefix $(SRCS_DIR), $(SOURCES))

OBJECTS = $(notdir $(SOURCES:.c=.o))
OBJS = $(addprefix $(OBJS_DIR), $(OBJECTS))

$(OBJS_DIR)%.o: $(SRCS_DIR)*/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEAD_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re

