NAME = fract-ol

SRC = main.c julia.c mandelbrot.c utils.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

MLX_PATH=mlx_linux

MLX_LIB=mlx

MLX_LIBPATH=mlx_linux/libmlx.a

PRINTF = printf/libftprintf.a

PRINTF_DIR = ./printf

RM = rm -rf

OBJECTS = $(SRC:.c=.o)

%.o: %.c
	gcc $(FLAGS) -I/usr/include -I$(MLX_PATH) -O3 -c $< -o $@ -g

$(NAME): $(OBJECTS) $(MLX_LIBPATH)
	$(CC) $(OBJECTS) $(PRINTF) -L$(MLX_PATH) -l$(MLX_LIB) -L/usr/lib -I$(MLX_PATH) -lXext -lX11 -lm -lz -o $(NAME) -g

$(PRINTF):
	@make -sC $(PRINTF_DIR)

$(MLX_LIBPATH):
	@make -sC $(MLX_PATH)

all : $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
