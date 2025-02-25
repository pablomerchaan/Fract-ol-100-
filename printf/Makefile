# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paperez- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 12:55:03 by paperez-          #+#    #+#              #
#    Updated: 2024/04/22 17:03:12 by paperez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf.c ft_putchar.c ft_putstr.c \
		  ft_putpointer.c ft_puthexa.c ft_putnbr.c \
		  ft_putuint.c aux.c

OBJECTS = $(SOURCES:.c=.o)

CC = gcc

CFLAGS = -Wextra -Wall -Werror

AR = ar -rcs

all = $(NAME)

$(NAME) : $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
