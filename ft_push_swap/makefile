# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 19:24:31 by bexner            #+#    #+#              #
#    Updated: 2022/02/22 23:02:33 by bexner           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = hardcode_sort.c ft_push_swap.c atoi_lstaddback_sortcheck_5hardcode.c \
pa_pb_sa_sb.c radix_sort.c rra_rrb_rrr.c ra_rb_rr_freeall.c benito_sort.c hardcode_helper_ss.c \
four_num_one_and_two.c four_num_three.c four_num_four.c

OBJ = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB = libft/libft.a

all: ${NAME}

${NAME}: ${OBJ}
	make -C ./libft
	${CC} ${SRC} ${LIB} push_swap.h 
	mv a.out $@

clean:
	rm ${OBJ}
	make clean -C ./libft
	rm -f ./push_swap
	rm -f ./push_swap.h.gch

re: fclean all

.PHONY: all fclean clean name re