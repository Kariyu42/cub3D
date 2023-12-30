# --- TEXT EDIT --- #
BOLD	=	\033[1m
GREEN	=	\033[0;32m
L_GREEN	=	\033[1;32m
RESET	=	\033[0m

# --- SRC / OBJ --- #
SRC_PATH	=	src/

SRC	=	${addprefix ${SRC_PATH}, ft_atoi.c \
										ft_bzero.c \
										ft_calloc.c \
										ft_isalpha.c \
										ft_isdigit.c \
										ft_itoa.c \
										ft_putchar_fd.c \
										ft_putendl_fd.c \
										ft_putnbr_fd.c \
										ft_putstr_fd.c \
										ft_split.c \
										ft_strchr.c \
										ft_strdup.c \
										ft_strjoin.c \
										ft_strlen.c \
										ft_strncmp.c \
										ft_strrchr.c \
										ft_strtrim.c \
										ft_substr.c \
										get_next_line.c}

OBJ	=	${SRC:.c=.o}

# --- COMPILER --- #
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

HEADER	=	inc/

${SRC_PATH}%.o: ${SRC_PATH}%.c
	@${CC} ${CFLAGS} -I${HEADER} -c $< -o $@

### Name of lib ###
NAME	=	libft.a

### Rules ###
all:	${NAME}

${NAME}:	${OBJ}
	@ar rcs ${NAME} ${OBJ}
	@printf "\n\t${BOLD}${L_GREEN}Compiled ${GREEN}LIBFT !${RESET}\n"

clean:
	@${RM} ${OBJ}
	@printf "\n\t${BOLD}CLEANED [LIBFT .o] files${RESET}\n"

fclean:	clean
	@${RM} ${NAME}
	@printf "\n\t${BOLD}libft.a CLEANED${RESET}\n\n"

re:	fclean all

.PHONY:	all clean fclean re
