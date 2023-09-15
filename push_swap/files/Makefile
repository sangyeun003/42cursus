# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 10:53:46 by sangyepa          #+#    #+#              #
#    Updated: 2023/09/15 15:19:40 by sangyepa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=ft_check_invalid_input.c ft_parsing.c sort_3.c a_to_b.c ft_deque1.c ft_deque2.c ft_split.c swap.c \
					b_to_a.c ft_error.c greedy.c is_sorted.c reverse_rotate.c \
					ft_is_overlaping.c push_swap.c rotate.c ft_atoi.c ft_isdigit.c push.c sort_2.c
OBJS=$(SRCS:.c=.o)
SRCS_BONUS=checker_bonus.c ft_atoi_bonus.c ft_check_invalid_input_bonus.c ft_deque1_bonus.c \
			ft_deque2_bonus.c ft_error_bonus.c ft_is_overlaping_bonus.c ft_isdigit_bonus.c \
			ft_parsing_bonus.c ft_split_bonus.c ft_strcmp_bonus.c get_next_line_bonus.c \
			get_next_line_utils_bonus.c is_sorted_bonus.c push_bonus.c reverse_rotate_bonus.c \
			rotate_bonus.c swap_bonus.c
OBJS_BONUS=$(SRCS_BONUS:.c=.o)
CC=cc
WFLAGS=-Wall -Wextra -Werror
NAME=push_swap
BONUS_NAME=checker
HEADER=.

ifdef BONUS
	FILE_NAME = $(BONUS_NAME)
	OBJS_FILES = $(OBJS_BONUS)
else
	FILE_NAME = $(NAME)
	OBJS_FILES = $(OBJS)
endif

all: $(FILE_NAME)

$(FILE_NAME): $(OBJS_FILES)
	$(CC) -o $(FILE_NAME) $(OBJS_FILES)

%.o: %.c
	$(CC) $(WFLAGS) -c $^ -o $@ -I $(HEADER)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

bonus:
	make BONUS=1 all

.PHONY: all clean fclean re bonus