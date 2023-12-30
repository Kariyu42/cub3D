
# ! Use cc for compilation must change before push !

# --- SRC / OBJ --- #
SRC_PATH	=	./src/

SRC			=	${addprefix ${SRC_PATH}, main.c \
											game/key_handler.c \
											initialize/init_cub.c \
											initialize/init_struct.c \
											initialize/mlx_win.c \
											initialize/stock_img.c \
											parsing/check_color.c \
											parsing/get_texture.c \
											parsing/inspect_dup.c \
											parsing/map_data.c \
											parsing/map_parser.c \
											parsing/parsing.c \
											raycast/drawing.c \
											raycast/raycasting.c \
											raycast/texture.c \
											utils/ft_cleanup.c \
											utils/ft_utils.c \
											utils/ft_utils2.c \
											utils/map_tools.c}

OBJ			=	${SRC:.c=.o}

# --- COMPILER --- #
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
OFLAGS		=	-framework OpenGL -framework AppKit

# --- DEBUG PURPOSES --- #
ifdef	DEBUG
	CC	+=	-g
endif

HEADER		=	./inc/

${SRC_PATH}%.o: ${SRC_PATH}%.c
	@${CC} ${CFLAGS} -Imlx -I${HEADER} -c $< -o $@

# --- EXEC / RULES --- #
NAME		=	cub3D
LIBFT		=	./Lib/Libft/
MLX			=	./mlx/
MLX2		=	./mlx2/

all:	${NAME}

${NAME}:	${OBJ}
	@make -C ${LIBFT}
	@${CC} ${CFLAGS} -Lmlx -lmlx ${OFLAGS} ${LIBFT}libft.a ${MLX}libmlx.a ${OBJ} -o ${NAME}
	@printf "\n\tcub3D ready ✨\n"

intel:	${OBJ}
	@make -C ${LIBFT}
	@${CC} ${CFLAGS} -Lmlx -lmlx ${OFLAGS} ${LIBFT}libft.a libmlx.dylib ${OBJ} -o ${NAME}
	@printf "\n\tcub3D ready ✨\n"

debug:
	@${MAKE} DEBUG=1

clean:
	@make clean -C ${LIBFT}
	@rm -f ${OBJ}

fclean:	clean
	@rm -f ${LIBFT}libft.a ${NAME}

re:	fclean
	@${MAKE} all

.PHONY: all debug clean fclean re
