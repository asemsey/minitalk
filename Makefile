# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 08:45:48 by asemsey           #+#    #+#              #
#    Updated: 2024/01/05 16:29:30 by asemsey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CFLAGS = -Wall -Wextra -Werror

SHARED = libft.c
SSRC = server.c
CSRC = client.c

all: $(SERVER) $(CLIENT)

$(SERVER):
	cc $(CFLAGS) -o $(SERVER) $(SSRC) $(SHARED)

$(CLIENT):
	cc $(CFLAGS) -o $(CLIENT) $(CSRC) $(SHARED)

clean:
	rm -f $(SERVER) $(CLIENT)

fclean: clean

re: fclean all