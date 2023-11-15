# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 16:58:45 by sangyepa          #+#    #+#              #
#    Updated: 2023/11/15 17:13:45 by sangyepa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_SRCS=client.c
SERVER_SRCS=server.c
SRCS_BONUS=client_bonus.c server_bonus.c
OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

PRINTF=./ft_printf/libftprintf.a
PRINTF_DIR=./ft_printf/

HEADER=.
WFLAGS=-Wall -Wextra -Werror
CC=cc
CLEINT=client
SERVER=server

ifdef BONUS
	# CLIENT_NAME = $(BONUS_NAME)
	OBJS_FILES = $(OBJS_BONUS)
else
	# FILE_NAME = $(NAME)
	OBJS_FILES = $(OBJS)
endif

all: $(FILE_NAME)

$(FILE_NAME): $(PRINTF) $(OBJS_FILES)
	$(CC) $(WFLAGS) -o $(CLEINT) $(OBJS_FILES) $(PRINTF)

$(PRINTF):
	make -C $(PRINTF_DIR) all

%.o: %.c
	$(CC) $(WFLAGS) -c $^ -o $@ -I $(HEADER)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	rm -f $(PRINTF)
	rm -f $(PRINTF_DIR)*.o

fclean: clean
	rm -f $(FILE_NAME)
	rm -f $(BONUS_NAME)

re: fclean all

bonus:
	make BONUS=1 all

.PHONY: all clean fclean re bonus