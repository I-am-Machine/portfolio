NAME = libftprintf.a

SRCS = ft_printf.c ft_uitoa.c ft_putchar.c ft_print_voidpointer.c  \
ft_print_string.c ft_itoa.c ft_nbrlength_strlen_memset_strlcpy.c ft_base.c

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f


.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all, re, clean, fclean, make