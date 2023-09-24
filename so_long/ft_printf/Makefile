SRCS=ft_printf.c ft_putp.c ft_putchar.c ft_put_integer.c ft_putstr.c ft_putunsignedint.c ft_putunsignedint_hex.c ft_check.c
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