SRCS    = ft_printf.c \
			calc.c \
			utils.c \
			print_type.c

OBJS    = ${SRCS:.c=.o}

CC      = gcc

CFLAGS  = -Wall -Wextra -Werror -I.

NAME    = libftprintf.a

.c.o :       ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

.o: libft/%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}		:	${OBJS}
				make -C libft
				ar rc ${NAME} libft/*.o ${OBJS}

all 		:   ${NAME}

bonus		:	all

clean 		:
				make -C libft/ fclean
				rm -f ${OBJS}

fclean 		:	clean
				rm -f ${NAME} libft/*.o *.o

re 			:   fclean all

.PHONY		:	all clean fclean re
