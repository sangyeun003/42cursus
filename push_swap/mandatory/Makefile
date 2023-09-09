SRCS=ft_check_invalid_input.c ft_parsing.c sort_3.c a_to_b.c ft_deque1.c ft_deque2.c ft_split.c swap.c b_to_a.c ft_error.c greedy.c ft_free_deque.c is_sorted.c reverse_rotate.c ft_is_overlaping.c main.c rotate.c ft_atoi.c ft_isdigit.c push.c sort_2.c
OBJS=$(SRCS:.c=.o)
SRCS_BONUS=
OBJS_BONUS=$(SRCS_BONUS:.c=.o)
CC=cc
WFLAGS=-Wall -Wextra -Werror
NAME=push_swap
HEADER=.

ifdef BONUS
	OBJS_FILES = $(OBJS) $(OBJS_BONUS)
else
	OBJS_FILES = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS_FILES)
	$(CC) -o $(NAME) $(OBJS_FILES)

%.o: %.c
	$(CC) $(WFLAGS) -c $^ -o $@ -I $(HEADER)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	make BONUS=1 all

.PHONY: all clean fclean re bonus