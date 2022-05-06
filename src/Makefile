SRCS =			main.c checkmap_utils.c checkmap_utils_2.c misc_utils.c misc_utils_2.c move_utils.c \
				my_mlx_utils.c parse_utils.c rendering_utils.c scaling_utils.c update_utils.c

OBJS =			${SRCS:.c=.o}

NAME =			so_long

CFLAGs =		-Wall -Wextra -Werror

CC =			gcc

LIBFTPATH =		libft/

LIBFT =			libft.a

MLX =			-lmlx

FRAMEWORK =		-lmlx -framework OpenGL -framework AppKit

RM =			rm -f

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${LIBFT}:
				make -C ${LIBFTPATH} all

${NAME}:		${OBJS} ${LIBFT}
				@${CC} ${CFLAGS} ${FRAMEWORK} ${OBJS} ${LIBFTPATH}${LIBFT} -o ${NAME}

all: ${NAME}

clean:
				${RM} ${OBJS}
				make -C ${LIBFTPATH} clean

fclean: clean
				${RM} ${NAME} ${LIBFTPATH}${LIBFT}

re: fclean all

.PHONY: all clean fclean re