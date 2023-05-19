# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 20:49:34 by lpeeters          #+#    #+#              #
#    Updated: 2023/05/18 22:47:15 by lpeeters         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#program name
NAME = pipex

#compiler
CC = gcc -g -fsanitize=address

#remove
RM = rm -rf

#compilation flags
CFLAGS = -Wall -Wextra -Werror

#library file
LIB = libft/libft.a

#make in library directory
MK_LIB = make -C libft/ > /dev/null 2>&1

#source files
SRCS = pipex.c error/handling.c

#header file
HEADER = pipex.h

#color codes for echo statements
COLOR_RESET = \033[0m
COLOR_INFO = \033[1;36m
COLOR_SUCCESS = \033[1;32m

#make project into program
${NAME}: ${SRCS} ${HEADER}
	@echo "${COLOR_INFO}Gathering ingredients...${COLOR_RESET}"
	@${MK_LIB}
	@echo "${COLOR_INFO}Mixing ingredients and brewing ${NAME}...${COLOR_RESET}"
	@${CC} ${CFLAGS} ${SRCS} ${HEADER} ${LIB} -o ${NAME}
	@chmod +x ${NAME}
	@echo "${COLOR_SUCCESS}Voila! ${NAME} is ready to be served!${COLOR_RESET}"

#make the program
all: ${NAME}

#clean object files and directories
clean:
	@echo "${COLOR_INFO}Putting away the leftovers...${COLOR_RESET}"
	@${MK_LIB} clean
	@echo "${COLOR_INFO}Washing out the cauldron...${COLOR_RESET}"
	@${RM} ${LIB}
	@echo "${COLOR_SUCCESS}All tidy and shiny!${COLOR_RESET}"

#clean everything that was made
fclean:
	@echo "${COLOR_INFO}Wiping fingerprints...${COLOR_RESET}"
	@${MK_LIB} fclean
	@echo "${COLOR_INFO}Disposing of the evidence...${COLOR_RESET}"
	@${RM} ${NAME}
	@echo "${COLOR_SUCCESS}Like I was never here!${COLOR_RESET}"

#remake
re: fclean all

#targets
.PHONY: all clean fclean re
