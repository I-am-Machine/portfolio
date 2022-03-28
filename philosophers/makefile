SRC = philo.c

OBJ = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = philo

LIB = libft/libft.a

all: ${NAME}

${NAME}: ${OBJ}
	make -C ./libft
	${CC} ${SRC} ${LIB} philo.h 
	mv a.out $@

clean:
	rm ${OBJ}
	make clean -C ./libft
	rm -f ./philo
	rm -f ./philo.h.gch

fclean:
	rm ${OBJ}
	make fclean -C ./libft
	rm -f ./philo
	rm -f ./philo.h.gch

re: fclean all

.PHONY: all fclean clean name re