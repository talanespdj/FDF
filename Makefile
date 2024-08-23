NAME = fdf
CC = cc
CFLAGS = -Wall -Werror -Wextra -O3 -g3
MLX_FLAGS = -L ./mlx -lmlx -Ilmlx -lXext -lX11 -lm

SRC = gnl.c \
      	algo.c \
	wgas.c \
	draw.c \
	fill.c \
	gnlv2.c \
	split.c \
	utils.c \
	trash.c \
	event.c \
	verif.c \
	process.c \
	fildefer.c \

OBJS = $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

all: $(NAME)
	
$(NAME): $(OBJS)
	make -C ./mlx
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
	echo "\t\tFil de fer est pret ✅"

clean:
	rm -rf $(OBJS)
	echo "c'est clean"

fclean: clean
	rm -rf $(NAME)
	echo "c'est fclean"

re: fclean all

.PHONY: all, clean, fclean, re

.SILENT:


# echo "\033[1mI to put isometric\033[0m"
# echo "\033[1mJ to center\033[0m"
# echo "\033[1mO to view it in 2D\033[0m"
# echo "\033[1mY or U to change the angle\033[0m"
# echo "\033[1mH or K to change the  relief\033[0m"
