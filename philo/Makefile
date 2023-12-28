# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 21:18:44 by sangyepa          #+#    #+#              #
#    Updated: 2023/12/27 22:45:27 by sangyepa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INCLUDES = ./includes
SRCS = ${wildcard ./srcs/*.c}
OBJS = $(SRCS:.c=.o)

MAKE = make
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES)
	
clean:
	$(RM) -f $(OBJS)
	
fclean: clean
	$(RM) -f $(NAME)
	
re: fclean all

.PHONY: clean fclean re all
	