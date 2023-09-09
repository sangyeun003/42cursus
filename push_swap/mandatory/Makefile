SRCS=ft_check_invalid_input.c ft_parsing.c sort_3.c a_to_b.c ft_deque1.c ft_deque2.c ft_split.c swap.c \
					b_to_a.c ft_error.c greedy.c ft_free_deque.c is_sorted.c reverse_rotate.c \
					ft_is_overlaping.c push_swap.c rotate.c ft_atoi.c ft_isdigit.c push.c sort_2.c
OBJS=$(SRCS:.c=.o)
SRCS_BONUS=../bonus/utils/ft_check_invalid_input_bonus.c ../bonus/utils/ft_parsing_bonus.c \
				../bonus/utils/sort_3_bonus.c ../bonus/utils/a_to_b_bonus.c ../bonus/utils/ft_deque1_bonus.c \
				../bonus/utils/ft_deque2_bonus.c ../bonus/utils/ft_split_bonus.c ../bonus/utils/swap_bonus.c \
				../bonus/utils/b_to_a_bonus.c ../bonus/utils/ft_error_bonus.c ../bonus/utils/greedy_bonus.c \
				../bonus/utils/ft_free_deque_bonus.c ../bonus/utils/is_sorted_bonus.c \
				../bonus/utils/reverse_rotate_bonus.c ../bonus/utils/ft_is_overlaping_bonus.c \
				../bonus/utils/push_swap_bonus.c ../bonus/utils/rotate_bonus.c 	../bonus/utils/ft_atoi_bonus.c \
				../bonus/utils/ft_isdigit_bonus.c ../bonus/utils/push_bonus.c ../bonus/utils/sort_2_bonus.c\
				../bonus/checker_bonus.c ../bonus/utils/ft_strcmp.c
OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)
CC=cc
WFLAGS=-Wall -Wextra -Werror
NAME=push_swap
CHECKER_NAME=checker
HEADER=.
CHECKER_HEADER=../bonus/utils

ifdef BONUS
	OBJS_FILES = $(OBJS) $(OBJS_BONUS)
	HEADERS = $(HEADER) $(CHECKER_HEADER)
else
	OBJS_FILES = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS_FILES)
	$(CC) -o $(NAME) $(OBJS_FILES)

%.o: %.c
	$(CC) $(WFLAGS) -c $^ -o $@ -I $(HEADERS)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

checker: $(CHECKER_NAME)

bonus:
	make BONUS=1 all

.PHONY: all clean fclean re bonus