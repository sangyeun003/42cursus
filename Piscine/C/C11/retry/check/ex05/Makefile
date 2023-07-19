SRCS=calculate.c ft_atoi.c ft_putnbr.c ft_strcmp.c ft_sum.c ft_sub.c ft_mul.c ft_div.c ft_modulo.c ft_cal.c
OBJS=calculate.o ft_atoi.o ft_putnbr.o ft_strcmp.o ft_sum.o ft_sub.o ft_mul.o ft_div.o ft_modulo.o ft_cal.o
NAME=do-op
CC=cc
WFLAGS=-Wall -Wextra -Werror
HEADER=ex05

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(WFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(WFLAGS) -c $^ -o $@ -I $(HEADER)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
