SRCS=main.c ft_atoi.c
OBJS=$(SRCS:.c=.o)
CC=cc
WFLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a
HEADER=.

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(WFLAGS) -c $^ -o $@ -I $(HEADER)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re