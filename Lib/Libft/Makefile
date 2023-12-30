# --- TEXT EDIT --- #
BOLD		=	\033[1m
RESET		=	\033[0m
ITALIC		=	\033[3m
### Colors ###
GRAY		=	\033[38;5;245m
RED			=	\033[31m
GREEN		=	\033[32m
BLUE		=	\033[34m
PURPLE		=	\033[35m

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
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

HEADER	=	inc/

### Loading Bar ###
COUNTER		=	0
CUR_UP		=	\033[A
TOTAL_SRCS	=	${shell find . -type f -name "*.c" | wc -l}
PERCENT		=	${shell expr 100 \* ${COUNTER} / ${TOTAL_SRCS}}
BAR			=	${shell expr 20 \* ${COUNTER} / ${TOTAL_SRCS}}

${SRC_PATH}%.o: ${SRC_PATH}%.c
	@${eval COUNTER = ${shell expr ${COUNTER} + 1}}
	@${CC} ${CFLAGS} -I${HEADER} -c $< -o $@
	@echo " ${GREEN}${BOLD} ↳ ${BLUE}cooking [${GREEN}libft.a${BLUE}]:${RESET}"
	@printf "\t\t\t${BOLD}${BLUE}[${PURPLE}%-20.${BAR}s${BLUE}] %d/%d [${GREEN}%d%%${BLUE}]${RESET}" "////////////////////" ${COUNTER} ${TOTAL_SRCS} ${PERCENT}
	@echo "${CUR_UP}${CUR_UP}"

### Name of lib ###
NAME	=	libft.a

### Rules ###
all:	${NAME}

${NAME}:	${OBJ}
	@ar rcs ${NAME} ${OBJ}
	@clear
	@printf "\n${GRAY}━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}\n"
	@printf "${BOLD}${GREEN} ↳ ${BLUE}[${PURPLE}${NAME}${BLUE}] ${GREEN}compiled !${RESET}"
	@printf "\n${GRAY}━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}\n"

clean:
	@${RM} ${OBJ}
	@printf "\n${GRAY}━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}\n"
	@printf "${BOLD}${GREEN} ↳ ${BLUE}[${PURPLE}${NAME}${BLUE}] object ${RED}cleaned${RESET}"
	@printf "\n${GRAY}━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}\n"

fclean:	clean
	@${RM} ${NAME}
	@printf "\n${GRAY}━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}\n"
	@printf "${BOLD}${GREEN} ↳ ${BLUE}[${PURPLE}${NAME}${BLUE}] ${RED}removed${RESET}"
	@printf "\n${GRAY}━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}\n\n"

re:	fclean all

.PHONY:	all clean fclean re
