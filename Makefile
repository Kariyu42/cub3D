# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/30 16:25:28 by kquetat-          #+#    #+#              #
#    Updated: 2024/01/01 15:49:54 by kquetat-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### TEXT EDIT ###
BOLD		=	\033[1m
RESET		=	\033[0m
ITALIC		=	\033[3m
### Colors ###
GRAY		=	\033[38;5;245m
RED			=	\033[31m
GREEN		=	\033[32m
BLUE		=	\033[34m
PURPLE		=	\033[35m

### OS Check ###
OS_NAME		:=	${shell uname -s}

# --- SRC / OBJ --- #
MAIN_SRC_PATH	=	./src/mandatory/
BONUS_SRC_PATH	=	./src/bonus/

SRC			=	${addprefix ${MAIN_SRC_PATH}, main.c \
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

SRC_BONUS	=	${addprefix ${BONUS_SRC_PATH}, main_bonus.c\
											game_bonus/key_handler_bonus.c \
											initialize_bonus/init_cub_bonus.c \
											initialize_bonus/init_struct_bonus.c \
											initialize_bonus/mlx_win_bonus.c \
											initialize_bonus/stock_img_bonus.c \
											parsing_bonus/check_color_bonus.c \
											parsing_bonus/get_texture_bonus.c \
											parsing_bonus/inspect_dup_bonus.c \
											parsing_bonus/map_data_bonus.c \
											parsing_bonus/map_parser_bonus.c \
											parsing_bonus/parsing_bonus.c \
											raycast_bonus/drawing_bonus.c \
											raycast_bonus/raycasting_bonus.c \
											raycast_bonus/texture_bonus.c \
											utils_bonus/ft_cleanup_bonus.c \
											utils_bonus/ft_utils_bonus.c \
											utils_bonus/ft_utils2_bonus.c \
											utils_bonus/map_tools_bonus.c}

OBJ			=	${SRC:.c=.o}

# --- COMPILER --- #
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
OFLAGS		=	-framework OpenGL -framework AppKit
HEADER		=	./inc/
MLX_DIR		=	./mlx/macos/

# --- OS Compilation Flags --- #
ifeq (${OS_NAME}, Linux)
	CFLAGS	+=	-Imlx/linux/
	LIBMLX	=	./mlx/linux/libmlx.a
	MLX_DIR	=	./mlx/linux/
endif

ifeq (${OS_NAME}, Darwin)
	CFLAGS	+=	-Imlx/macos
	LIBMLX	=	./mlx/macos/libmlx.a
	MLX_DIR	=	./mlx/macos/
endif

# --- DEBUG PURPOSES --- #
ifdef	DEBUG
	CC	+=	-g
endif

### Loading Bar ###
COUNTER		=	0
CUR_UP		=	\033[A
TOTAL_SRCS	=	${shell find . -type f -name "*.c" -not -path "./Lib/Libft/*" -not -path "./mlx/*" | wc -l}
PERCENT		=	${shell expr 100 \* ${COUNTER} / ${TOTAL_SRCS}}
BAR			=	${shell expr 19 \* ${COUNTER} / ${TOTAL_SRCS}}

${SRC_PATH}%.o: ${SRC_PATH}%.c
	@${eval COUNTER = ${shell expr ${COUNTER} + 1}}
	@${CC} ${CFLAGS} -I${MLX_DIR} -I${HEADER} -c $< -o $@
	@echo " ${GREEN}${BOLD} ↳ ${BLUE}cooking [${PURPLE}${NAME}${BLUE}]:${RESET}"
	@printf "\t\t\t${BOLD}${BLUE}[${PURPLE}%-19.${BAR}s${BLUE}] %d/%d [${GREEN}%d%%${BLUE}]${RESET}" "////////////////////" ${COUNTER} ${TOTAL_SRCS} ${PERCENT}
	@echo "${CUR_UP}${CUR_UP}"

# --- EXEC / RULES --- #
NAME		=	cub3D
LIBFT		=	./Lib/Libft/

all:	${NAME}

ifeq (${OS_NAME}, Linux)
${NAME}:	brew_libft brew_mlx ${OBJ}
	@clear
	@printf "\n\n${GRAY}━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}\n"
	@${CC} ${CFLAGS} ${OBJ} -Lmlx/linux -lmlx -lXext -lX11 -lm -lz -o ${NAME} ${LIBFT}libft.a
	@printf "${BOLD}${GREEN} ↳ ${BLUE}[${PURPLE}${NAME}${BLUE}] ${GREEN}compiled !${RESET}"
	@printf "\n${GRAY}━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}\n"
endif

ifeq (${OS_NAME}, Darwin)
${NAME}:	brew_libft brew_mlx ${OBJ}
	@clear
	@printf "\n\n${GRAY}━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}\n"
	@${CC} ${CFLAGS} -Lmlx/macos -lmlx ${OFLAGS} ${LIBFT}libft.a ${OBJ} -o ${NAME}
	@printf "${BOLD}${GREEN} ↳ ${BLUE}[${PURPLE}${NAME}${BLUE}] ${GREEN}compiled !${RESET}"
	@printf "\n${GRAY}━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}\n"
endif

brew_libft:
	@make -C ${LIBFT}

brew_mlx:
	@make -C ${MLX_DIR}

debug:
	@${MAKE} DEBUG=1

clean:
	@make clean -C ${LIBFT}
	@make clean -C ${MLX_DIR}
	@rm -f ${OBJ}
	@printf "\n${GRAY}━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}\n"
	@printf "${BOLD}${GREEN} ↳ ${BLUE}[${PURPLE}${NAME}${BLUE}] object ${RED}cleaned${RESET}"
	@printf "\n${GRAY}━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}\n"

fclean:	clean
	@make fclean -C ${LIBFT}
	@rm -f ${NAME}
	@printf "\n${GRAY}━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}\n"
	@printf "${BOLD}${GREEN} ↳ ${BLUE}[${PURPLE}${NAME}${BLUE}] ${RED}removed${RESET}"
	@printf "\n${GRAY}━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}\n"

re:	fclean
	@${MAKE} all

.PHONY: all brew_libft brew_mlx debug clean fclean re
