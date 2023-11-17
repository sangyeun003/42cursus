# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 16:58:45 by sangyepa          #+#    #+#              #
#    Updated: 2023/11/17 23:26:21 by sangyepa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_SRC=mandatory/client.c
SERVER_SRC=mandatory/server.c
CLIENT_OBJ=$(CLIENT_SRC:.c=.o)
SERVER_OBJ=$(SERVER_SRC:.c=.o)
CLIENT_BONUS_SRC=bonus/client_bonus.c
SERVER_BONUS_SRC=bonus/server_bonus.c
CLIENT_BONUS_OBJ=$(CLIENT_BONUS_SRC:.c=.o)
SERVER_BONUS_OBJ=$(SERVER_BONUS_SRC:.c=.o)


LIBS=./ft_printf/libftprintf.a ./libft/libft.a

PRINTF_DIR=./ft_printf/
LIBFT_DIR=./libft/

HEADER=.
WFLAGS=-Wall -Wextra -Werror
CC=cc
CLIENT=client
SERVER=server
CLIENT_BONUS=client_bonus
SERVER_BONUS=server_bonus

ifdef BONUS
	CLIENT_NAME = $(CLIENT_BONUS)
	CLIENT_OBJ_FILE = $(CLIENT_BONUS_OBJ)
	SERVER_NAME = $(SERVER_BONUS)
	SERVER_OBJ_FILE = $(SERVER_BONUS_OBJ)
else
	CLIENT_NAME = $(CLIENT)
	CLIENT_OBJ_FILE = $(CLIENT_OBJ)
	SERVER_NAME = $(SERVER)
	SERVER_OBJ_FILE = $(SERVER_OBJ)
endif

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(LIBS) $(CLIENT_OBJ_FILE)
	$(CC) $(WFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJ_FILE) $(LIBS)
$(SERVER_NAME): $(LIBS) $(SERVER_OBJ_FILE)
	$(CC) $(WFLAGS) -o $(SERVER_NAME) $(SERVER_OBJ_FILE) $(LIBS)

.c.o:
	$(CC) $(WFLAGS) -c $< -o $@

$(LIBS):
	make -C $(PRINTF_DIR) all
	make -C $(LIBFT_DIR) all

clean:
	rm -f $(CLIENT_OBJ)
	rm -f $(SERVER_OBJ)
	rm -f $(CLIENT_BONUS_OBJ)
	rm -f $(SERVER_BONUS_OBJ)
	
	rm -f $(LIBS)
	rm -f $(PRINTF_DIR)*.o
	rm -f $(LIBFT_DIR)*.o

fclean: clean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

bonus:
	make BONUS=1 all

.PHONY: all clean fclean re bonus