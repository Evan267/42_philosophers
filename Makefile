SRCS		= srcs/main.c \
		  srcs/msg.c \
		  srcs/error.c \
		  srcs/print_error.c \
		  srcs/create_fourchette.c \
		  srcs/create_philo.c \
		  srcs/thread.c \
		  srcs/action.c \
		  srcs/get_fork.c \
		  srcs/death.c \
		  srcs/utils.c \
		  srcs/ft_libft.c \

OBJS		= ${SRCS:.c=.o}

HEAD		= ./includes 

NAME		= philo

CC			= gcc

CFLAGS		= -g -Wall -Wextra -Werror

.c.o:		
			${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -pthread -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
