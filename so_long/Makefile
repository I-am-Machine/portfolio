# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 15:24:00 by cdahlhof          #+#    #+#              #
#    Updated: 2022/01/23 19:28:54 by bexner           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c get_next_line.c get_next_line_utils.c map.c player.c movement.c images.c ft_memmove.c

OBJ =	so_long.o get_next_line.o get_next_line_utils.o map.o player.o movement.o images.o ft_memmove.o

CC = gcc

LIB = ./libft/libft.a

LIBMLX = ./minilibx/libmlx.a

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./minilibx
	make -C ./libft
	$(CC) $(SRC) $(LIB) $(LIBMLX) so_long.h -L /usr/X11/lib -lXext -lX11
	mv a.out $@

clean:
	rm $(OBJ)
	make clean -C ./minilibx
	make clean -C ./libft

fclean:
	rm $(OBJ)
	make clean -C ./minilibx
	make fclean -C ./libft
	rm -f ./so_long
	rm -f ./so_long.h.gch

re: fclean all
