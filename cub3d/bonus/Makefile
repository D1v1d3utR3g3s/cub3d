# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hauerbac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 19:30:12 by hauerbac          #+#    #+#              #
#    Updated: 2025/03/23 21:31:57 by hauerbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
SRCS_BONUS_DIR	= srcs_bonus
HEAD_BONUS_DIR	= includes_bonus
OBJS_BONUS_DIR	= .objs_bonus

MLX_DIR		= ../minilibx-linux
LIBFT_DIR	= ../libft
CC		= cc
FLAGS		= -Wall -Wextra -Werror
DEPSFLAG	= -MMD
BONUS_NAME	= ../cub3D_bonus

DEBUG := 0
ifeq ($(DEBUG), 1)
	FLAGS += -g3
endif

vpath %.c ${SRCS_BONUS_DIR}

# FILES
SRCS = main_bonus.c \
       clean_bonus.c \
       colors_bonus.c \
       display_img_mlx_bonus.c \
       display_bonus.c \
       error_bonus.c \
       hook_event_close_bonus.c \
       hook_event_mov_bonus.c \
       hook_event_rot_bonus.c \
       hook_event_utils_bonus.c \
       hook_event_bonus.c \
       init_colors_data_bonus.c \
       init_game_bonus.c \
       init_mlx_bonus.c \
       init_bonus.c \
       raycast_intersect_utils_bonus.c \
       raycast_intersect_bonus.c \
       raycasting_bonus.c \
       update_bonus.c \
       utils_bonus.c \
       utils_math_bonus.c \
       debug_checks_raw_data_bonus.c \
       checks_raw_data_2_bonus.c \
       checks_raw_data_3_bonus.c \
       checks_raw_data_bonus.c \
       parse_scene_3_bonus.c \
       parse_scene_2_bonus.c \
       parse_scene_bonus.c \
       map_closure_checks_bonus.c \
       load_scene_bonus.c \
       checks_args_bonus.c \
       textures_bonus.c \
       textures_utils_bonus.c \
       bonus_minimap_bonus.c \
       bonus_minimap_utils_bonus.c \
       bonus_mouse_bonus.c \
       bonus_doors_bonus.c \
       bonus_wall_collision_bonus.c \
       bonus_anim_bonus.c \
       bonus_anim_hook.c\
       bonus_anim_sub_init_bonus.c\
       bonus_anim_utils_bonus.c \
       time_fct_bonus.c \
       writing_testing_purpose_bonus.c

HEADERS =	includes_bonus/c3DBasic_bonus.h \
		includes_bonus/c3DMap_bonus.h \
		includes_bonus/c3DMlx_bonus.h

OBJS = $(addprefix $(OBJS_BONUS_DIR)/, $(SRCS:%.c=%.o))
DEPS = $(addprefix $(OBJS_BONUS_DIR)/, $(SRCS:%.c=%.d))
LIBFT = ${LIBFT_DIR}/libft.a

all: LIBRARY BUILD ${BONUS_NAME}

LIBRARY:
	make -C ${MLX_DIR} all
	make -C ${LIBFT_DIR} all

BUILD:
	mkdir -p ${OBJS_BONUS_DIR}

clean:
	make -C ${MLX_DIR} clean
	make -C ${LIBFT_DIR} clean
	rm -rf ${OBJS_BONUS_DIR}

fclean: clean
	rm -f ${BONUS_NAME}
	rm -f ${LIBFT}

re: fclean all

-include ${DEPS}

${OBJS_BONUS_DIR}/%.o: %.c ${HEADERS} Makefile 
	${CC} ${FLAGS} ${DEPSFLAG} -c $< -o $@ -I./${HEAD_BONUS_DIR}

${BONUS_NAME}: ${OBJS} ${LIBFT}
	${CC} ${FLAGS} ${DEPSFLAG} -o ${BONUS_NAME} ${OBJS} -L${LIBFT_DIR} -lft -lX11 -lXext -L${MLX_DIR} -lmlx -lm

.PHONY: all clean fclean re
