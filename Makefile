# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 13:20:43 by rsiqueir          #+#    #+#              #
#    Updated: 2021/09/20 20:34:17 by rsiqueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
SERVER_NAME = server
LIB_NAME = ft_printf/libftprintf.a
LIBPATH = ./ft_printf
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -f

CLIENT_SRCS = src/client.c
SERVER_SRCS = src/server.c

CLIENT_OBJS = ${CLIENT_SRCS:%.c=%.o}
SERVER_OBJS = ${SERVER_SRCS:%.c=%.o}

all: lib ${CLIENT_NAME} ${SERVER_NAME}

${CLIENT_NAME}:		${CLIENT_OBJS}
					${CC} ${CFLAGS} ${CLIENT_OBJS} ${LIB_NAME} -o ${CLIENT_NAME}

${SERVER_NAME}:		${SERVER_OBJS}
					${CC} ${CFLAGS} ${SERVER_OBJS} ${LIB_NAME} -o ${SERVER_NAME}

lib:
	make -C ${LIBPATH}

clean:
	make -C ${LIBPATH} clean
	${RM} src/*.o

fclean: clean
	make -C ${LIBPATH} fclean
	${RM} ${CLIENT_NAME} ${SERVER_NAME}

re: clean all
