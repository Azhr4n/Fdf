# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/03 15:30:43 by pivanovi          #+#    #+#              #
#    Updated: 2014/04/21 19:45:22 by pivanovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = fdf

SRC =		tools/ft_putendl.c				\
			tools/ft_strjoin.c				\
			tools/ft_strlen.c				\
			tools/ft_putnbr.c				\
			tools/ft_atoi.c					\
			tools/clean.c					\
			src/setting_struct.c			\
			src/setting_map.c				\
			src/parsing.c					\
			src/print.c						\
			src/keys.c						\
			src/draw.c						\
			src/main.c

OBJ = $(SRC:.c=.o)

CFLAGS += -I./includes -I /usr/X11/include
LIBX = -L /usr/X11/lib -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBX)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
