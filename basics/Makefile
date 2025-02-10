# VARIABLES
SRCS_DIR	= ./srcs/
HEAD_DIR	= ./includes/
OBJS_DIR	= ./objs/

MLX_DIR		= ./minilibx-linux/
#LIBFT_DIR	= ./libft/
CC		= cc
FLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -lmlx_Linux -lX11 -lXext -lm
NAME		= mlx

# FILES
SOURCES = main.c clean.c display_2D.c display_line.c display.c \
hook_event_utils.c hook_event.c init.c ray_trace.c utils.c\
display_3D.c \
ray_trace_backup.c

OBJECTS = $(SOURCES:.c=.o)

SRCS = $(addprefix $(SRCS_DIR), $(SOURCES))
OBJS = $(addprefix $(OBJS_DIR), $(OBJECTS))
#LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEAD_DIR) -I $(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJS)
#	make re -C ./libft
#	$(CC) $(FLAGS) $(OBJS) -L. $(LIBFT) -Lminilibx-linux $(MLX_FLAGS) -o $(NAME)
	$(CC) $(FLAGS) $(OBJS) -Lminilibx-linux $(MLX_FLAGS) -o $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
#	make clean -C ./libft
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