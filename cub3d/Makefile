# VARIABLES
SRCS_DIR	= ./srcs/
HEAD_DIR	= ./includes/
OBJS_DIR	= ./objs/

MLX_DIR		= ./minilibx-linux/
LIBFT_DIR	= ./libft/
CC			= cc
FLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -lmlx_Linux -lX11 -lXext -lm
NAME		= cub3D

DEBUG := 0
ifeq ($(DEBUG), 1)
	FLAGS += -g3 -gdwarf-2
endif

# FILES
SOURCES = main.c clean.c colors.c display_img_mlx.c display.c error.c\
hook_event_close.c hook_event_mov.c hook_event_rot.c hook_event_utils.c\
hook_event.c init_colors_data.c init_mlx.c init.c \
raycast_intersect_utils.c raycast_intersect.c raycasting.c update.c utils.c\
debug_checks_raw_data.c checks_raw_data_2.c checks_raw_data_3.c checks_raw_data.c parse_scene_2.c\
parse_scene_3.c parse_scene.c map_closure_checks.c load_scene.c checks_args.c\
textures.c textures_utils.c \
wall_collision.c writing_testing_purpose.c

OBJECTS = $(SOURCES:.c=.o)

SRCS = $(addprefix $(SRCS_DIR), $(SOURCES))
OBJS = $(addprefix $(OBJS_DIR), $(OBJECTS))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEAD_DIR) -I $(MLX_DIR) -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	make re -C ./libft
	$(CC) $(FLAGS) $(OBJS) -L. $(LIBFT) -Lminilibx-linux $(MLX_FLAGS) -o $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	make clean -C ./libft
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)

fclean:
#	make fclean -C ./libft
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
