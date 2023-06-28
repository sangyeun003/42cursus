SRCS=
OBJS=$(SRCS:.c=.o)
SRCS_BONUS=
OBJS_BONUS=$(SRCS_BONUS:.c=.o)
CC=cc
WFLAGS=-Wall -Wextra -Werror
NAME=
HEADER=libft.a

ifdef BONUS
	OBJS_FILES = $(OBJS) $(OBJS_BONUS)
else
	OBJS_FILES = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS_FILES)
	ar r $(NAME) $(OBJS_FILES)

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