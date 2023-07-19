SRCS=main.c
OBJS=main.o
NAME=BSQ
CC=cc
WFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(WFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(WFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
