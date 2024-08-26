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
	$(CC) $(CFLAGS) -c -o $@ $< 

all: $(NAME)
	
$(NAME): $(OBJS)
	make -C ./mlx
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
	echo "\n\t\tFil de fer est pret ✅\n"

clean:
	rm -rf $(OBJS)
	echo "c'est clean"

fclean: clean
	rm -rf $(NAME)
	echo "c'est fclean"

re: fclean all

.PHONY: all, clean, fclean, re

.SILENT:
