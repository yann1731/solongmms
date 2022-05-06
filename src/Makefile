SRCS =			checkarg.c checkmap.c checkmap_utils.c errorhandling.c main.c image_scale_init.c \
				my_mlx_pixel_put.c get_colors.c player_init.c get_player_pos.c my_xpm_file_to_image.c \
				my_get_data_addr.c closeondestroy.c get_map_size.c closeprogram.c move_up.c move_down.c \
				move_left.c move_right.c

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
				${CC} ${CFLAGS} ${FRAMEWORK} ${OBJS} ${LIBFTPATH}${LIBFT} -o ${NAME}

all: ${NAME}

clean:
				${RM} ${OBJS}
				make -C ${LIBFTPATH} clean

fclean: clean
				${RM} ${NAME} ${LIBFTPATH}${LIBFT}

re: fclean all

.PHONY: all clean fclean re