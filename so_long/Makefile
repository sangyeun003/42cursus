# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 19:29:17 by sangyepa          #+#    #+#              #
#    Updated: 2023/11/03 17:47:36 by sangyepa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=./mandatory/get_next_line_utils.c ./mandatory/check_map.c \
	./mandatory/press_key.c ./mandatory/close_window.c ./mandatory/init_game.c \
	./mandatory/ft_strdup_without_newline.c ./mandatory/init_img.c \
	./mandatory/set_img.c ./mandatory/get_next_line.c ./mandatory/display.c \
	./mandatory/ft_strjoin_without_newline.c ./mandatory/main.c \
	./mandatory/read_map.c ./mandatory/print_error.c
SRCS_BONUS=./bonus/check_map_bonus.c ./bonus/get_next_line_utils_bonus.c \
	./bonus/press_key_bonus.c ./bonus/close_window_bonus.c \
	./bonus/init_game_bonus.c ./bonus/read_map_bonus.c \
	./bonus/ft_strdup_without_newline_bonus.c ./bonus/display_bonus.c \
	./bonus/init_img_bonus.c ./bonus/set_img_bonus.c \
	./bonus/ft_strjoin_without_newline_bonus.c ./bonus/main_bonus.c \
	./bonus/get_next_line_bonus.c ./bonus/print_error_bonus.c \
	./bonus/wasd_bonus.c ./bonus/meet_monster.c ./bonus/ft_itoa_bonus.c
OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)
MLX=./mlx/libmlx.dylib
MLX_DIR=./mlx/
MLX_LIB=libmlx.dylib
PRINTF=./ft_printf/libftprintf.a
PRINTF_DIR=./ft_printf/
PRINTF_LIB=libftprintf.a
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

$(FILE_NAME): $(MLX) $(PRINTF) $(OBJS_FILES)
	cp $(MLX) "./"
	cp $(PRINTF) "./"
	$(CC) $(WFLAGS) -o $(FILE_NAME) $(OBJS_FILES) $(MLX_LIB) $(PRINTF_LIB)

$(MLX):
	make -C $(MLX_DIR) all

$(PRINTF):
	make -C $(PRINTF_DIR) all

%.o: %.c
	$(CC) $(WFLAGS) -c $^ -o $@ -I $(HEADER)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	rm -f $(MLX_LIB)
	rm -f $(PRINTF_LIB)
	rm -f $(PRINTF_DIR)$(PRINTF_LIB)
	rm -f $(MLX_DIR)$(MLX_LIB)
	rm -f $(PRINTF_DIR)*.o
	rm -f $(MLX_DIR)*.o

fclean: clean
	rm -f $(FILE_NAME)
	rm -f $(BONUS_NAME)

re: fclean all

bonus:
	make BONUS=1 all

.PHONY: all clean fclean re bonus
