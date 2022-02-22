# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 13:20:43 by rsiqueir          #+#    #+#              #
#    Updated: 2022/02/22 04:54:04 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CLIENT = client
SERVER = server
LIB = ft_printf/libftprintf.a
LIBPATH = ./ft_printf

CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADERS = -I./header
RM = rm -f

CLIENT_SRCS = src/client.c
SERVER_SRCS = src/server.c
OTHER_SRCS = src/utils.c

CLIENT_OBJS = $(CLIENT_SRCS:%.c=%.o)
SERVER_OBJS = $(SERVER_SRCS:%.c=%.o)
OTHER_OBJS = $(OTHER_SRCS:%.c=%.o)

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT):		$(OTHER_OBJS) $(CLIENT_OBJS)
					$(CC) $(CFLAGS) $(HEADERS) $(OTHER_OBJS) $(CLIENT_OBJS)  -o $(CLIENT)

$(SERVER):		$(OTHER_OBJS) $(SERVER_OBJS)
					$(CC) $(CFLAGS) $(HEADERS) $(OTHER_OBJS) $(SERVER_OBJS) -o $(SERVER)

clean:
	$(RM) src/*.o

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

bonus: all

.PHONY:	all clean fclean re bonus