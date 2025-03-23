# VARIABLES
SRCS_DIR	= srcs
HEAD_DIR	= includes
OBJS_DIR	= .objs

MLX_DIR		= minilibx-linux
LIBFT_DIR	= libft
CC		= cc
FLAGS		= -Wall -Wextra -Werror
DEPSFLAG	= -MMD
NAME		= cub3D

DEBUG := 0
ifeq ($(DEBUG), 1)
	FLAGS += -g3
endif

vpath %.c ${SRCS_DIR}

# FILES
SRCS = main.c \
       clean.c \
       colors.c \
       display_img_mlx.c \
       display.c \
       error.c \
       hook_event_close.c \
       hook_event_mov.c \
       hook_event_rot.c \
       hook_event_utils.c \
       hook_event.c \
       init_colors_data.c \
       init_game.c \
       init_mlx.c \
       init.c \
       raycast_intersect_utils.c \
       raycast_intersect.c \
       raycasting.c \
       update.c \
       utils.c \
       utils_math.c \
       debug_checks_raw_data.c \
       checks_raw_data_2.c \
       checks_raw_data_3.c \
       checks_raw_data.c \
       parse_scene_3.c \
       parse_scene_2.c \
       parse_scene.c \
       map_closure_checks.c \
       load_scene.c \
       checks_args.c \
       textures.c \
       textures_utils.c \
       bonus_minimap.c \
       bonus_minimap_utils.c \
       bonus_mouse.c \
       bonus_doors.c \
       bonus_wall_collision.c \
       bonus_anim.c \
       bonus_anim_utils.c \
       time_fct.c \
       writing_testing_purpose.c

HEADERS =	includes/c3DBasic.h \
		includes/c3DMap.h \
		includes/c3DMlx.h

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))
DEPS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.d))
LIBFT = ${LIBFT_DIR}/libft.a

all: LIBRARY BUILD ${NAME}

LIBRARY:
	make -C ${MLX_DIR} all
	make -C ${LIBFT_DIR} all

BUILD:
	mkdir -p ${OBJS_DIR}

clean:
	make -C ${MLX_DIR} clean
	make -C ${LIBFT_DIR} clean
	rm -f ${OBJS} ${DEPS}
	rm -rf ${OBJS_DIR}

fclean: clean
	rm -f ${NAME}
	rm -f ${LIBFT}

re: fclean all

-include ${DEPS}

${OBJS_DIR}/%.o: %.c ${HEADERS} Makefile 
	${CC} ${FLAGS} ${DEPSFLAG} -c $< -o $@ -I./${HEAD_DIR}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${FLAGS} ${DEPSFLAG} -o ${NAME} ${OBJS} -L${LIBFT_DIR} -lft -lX11 -lXext -L${MLX_DIR} -lmlx -lm

.PHONY: all clean fclean re
