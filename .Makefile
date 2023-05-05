# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 12:49:06 by lpeeters          #+#    #+#              #
#    Updated: 2023/05/05 20:39:47 by lpeeters         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#program name
NAME = pipex

#compiler
CC = gcc

#remove
RM = rm -rf

#flags
CFLAGS = -Wall -Wextra -Werror

#find sources
SRCS = ${shell find . -name "*.c" -not -path "*lib*"}

#find other makefiles
MKFL = ${shell find . -mindepth 2 -name "Makefile" -o -name "makefile"}

#find library files
LIBS = ${shell find . -name "*.a"}

#fetch object files
OBJS = ${SRCS:%.c=${OBJ_DIR}%.o}

#fetch makefile directory
MKFL_DIRS = ${dir ${MKFL}}

#fetch library directory
LIB_DIRS = ${dir ${LIBS}}

#fetch library filename
LIB_PNAMES = ${notdir ${LIBS}} #cut off the path
LIB_LNAMES = ${LIB_PNAMES:lib%.a=%} #cut off the library files' "lib" prefix
LIB_NAMES = ${LIB_LNAMES:.a=} #cut off the library files' ".a" suffix

#object directory
OBJ_DIR = OBJS/

#make directories for object files
MK_DIR = mkdir -p ${@D}

#make object files
${OBJ_DIR}%.o: %.c
	${MK_DIR}
	${CC} ${CFLAGS} -c $< -o $@

#compilation flags, their directories and names for any library
LIB_ALL = ${foreach libdir,${LIB_DIRS},-L ${libdir}} \
	  ${foreach libname,${LIB_NAMES},-l ${libname}}

MKFL_ALL = ${foreach mkfldir,${MKFL_DIRS},${MAKE} -C ${mkfldir}}

#make project into program
${NAME}: ${OBJS}
	${MK_DIR}
	${CC} -o ${NAME} ${OBJS} ${LIB_ALL}
	chmod +x ${NAME}

#make
all: ${MKFL_ALL} ${NAME}

#clean object files and directories
clean:
	${RM} ${OBJ_DIR}

#clean everything that was made
fclean: clean
	${RM} ${NAME}

#remake
re: fclean all

#targets
.PHONY: all clean fclean re
