# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 19:29:17 by sangyepa          #+#    #+#              #
#    Updated: 2023/09/24 15:02:48 by sangyepa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=get_next_line_utils.c check_map.c press_key.c close_window.c init_game.c \
		ft_strdup_without_newline.c init_img.c set_img.c get_next_line.c \
		ft_strjoin_without_newline.c main.c read_map.c
SRCS_BONUS=
OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)
MLX=./mlx/libmlx.dylib
MLX_DIR=mlx/
MLX_LIB=libmlx.dylib
HEADER=.
WFLAGS=-Wall -Wextra -Werror
CC=cc
NAME=so_long
BONUS_NAME=so_long_bonus

ifdef BONUS
	FILE_NAME = $(BONUS_NAME)
	OBJS_FILES = $(OBJS_BONUS)
else
	FILE_NAME = $(NAME)
	OBJS_FILES = $(OBJS)
endif

all: $(FILE_NAME)

$(FILE_NAME): $(MLX) $(OBJS_FILES)
	cp $(MLX) "./"
	$(CC) $(WFLAGS) -o $(FILE_NAME) $(OBJS_FILES) $(MLX_LIB)

$(MLX):
	make -C $(MLX_DIR) all

%.o: %.c
	$(CC) $(WFLAGS) -c $^ -o $@ -I $(HEADER)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	rm -f $(MLX_LIB)

fclean: clean
	rm -f $(FILE_NAME)
	rm -f $(BONUS_NAME)

re: fclean all

bonus:
	make BONUS=1 all

.PHONY: all clean fclean re bonus
