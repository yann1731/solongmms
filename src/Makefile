SRCS =			checkarg.c checkmap.c checkmap_utils.c errorhandling.c main.c

OBJS =			${SRCS:.c=.o}

NAME =			so_long

CFLAGs =		-Wall -Wextra -Werror

CC =			gcc

LIBFTPATH =		libft/

LIBFT =			libft.a

MLX =			-lmlx

RM =			rm -f

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${LIBFT}:
				make -C ${LIBFTPATH} all

${NAME}:		${OBJS} ${LIBFT}
				${CC} ${CFLAGS} ${OBJS} ${MLX} ${LIBFTPATH}${LIBFT} -o ${NAME}

all: ${NAME}

clean:
				${RM} ${OBJS}
				make -C ${LIBFTPATH} clean

fclean: clean
				${RM} ${NAME} ${LIBFTPATH}${LIBFT}

re: fclean all

.PHONY: all clean fclean re