SOURCE	=	get_next_line.c\

HEADER	=	get_next_line.h libft/libft.h

OBJECTS	=	${SOURCE:.c=.o}

RM		=	rm -f

NAME	=	gnl.a

AR		=	ar rcs

CFLAGS	=	-Wall -Wextra -Werror

%.o: %.c ${HEADER}
			gcc  ${CFLAGS} -I libft -c $< -o ${<:.c=.o}

${NAME}:	${OBJECTS}
			make -C libft
			cp libft/libft.a $(NAME)
			${AR} ${NAME} ${OBJECTS}


all:		${NAME}

clean:
			make clean -C libft
			${RM} ${OBJECTS}

fclean:		clean
			make fclean -C libft
			${RM} ${NAME}

re:			fclean all

debug:		re
			gcc -g ${CFLAGS} *.c ./libft/libft.a

.PHONY:		all clean fclean bonus