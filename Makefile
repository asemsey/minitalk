# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 08:45:48 by asemsey           #+#    #+#              #
#    Updated: 2024/01/04 11:50:52 by asemsey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CFLAGS = -Wall -Wextra -Werror

SSRC = server.c libft.c
CSRC = client.c libft.c

all: $(SERVER) $(CLIENT)

$(SERVER):
	cc $(CFLAGS) -o $(SERVER) $(SSRC)

$(CLIENT):
	cc $(CFLAGS) -o $(CLIENT) $(CSRC)

clean:
	rm -f $(SERVER) $(CLIENT)

fclean: clean

re: fclean all