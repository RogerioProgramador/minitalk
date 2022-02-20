# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rosf <rosf@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 13:20:43 by rsiqueir          #+#    #+#              #
#    Updated: 2022/02/20 17:48:32 by rosf             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CLIENT = client
SERVER = server
LIB = ft_printf/libftprintf.a
LIBPATH = ./ft_printf

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

CLIENT_SRCS = src/client.c
SERVER_SRCS = src/server.c

CLIENT_OBJS = $(CLIENT_SRCS:%.c=%.o)
SERVER_OBJS = $(SERVER_SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT):		$(LIB) $(CLIENT_OBJS)
					$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIB) -o $(CLIENT)

$(SERVER):		$(LIB) $(SERVER_OBJS)
					$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIB) -o $(SERVER)

$(LIB):
	make -C $(LIBPATH)

clean:
	make -C $(LIBPATH) clean
	$(RM) src/*.o

fclean: clean
	make -C $(LIBPATH) fclean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

bonus: all

.PHONY:	all clean fclean re bonus