SRCS		= srcs/main.c \
		  srcs/msg.c \
		  srcs/error.c \
		  srcs/create_fourchette.c \
		  srcs/create_philo.c \
		  srcs/thread.c \
		  srcs/action.c \
		  srcs/get_fork.c \
		  srcs/death.c \
		  srcs/utils.c \

OBJS		= ${SRCS:.c=.o}

LFT			= ./libft/libft.a

HEAD		= ./includes 

NAME		= philo

CC			= gcc

CFLAGS		= -g -Wall -Wextra -Werror

.c.o:		
			${CC} ${CFLAGS} -I ${HEAD} -Ilibft -c $< -o ${<:.c=.o} 

${NAME}:	${LFT} ${OBJS}
			${CC} ${CFLAGS} ${OBJS} -pthread -L ./libft -lft -o ${NAME}

${LFT}:
			make -s -C libft

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJS_BONUS}
			make clean -C libft

fclean:		clean
			${RM} ${NAME}
			make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re
