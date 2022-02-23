NAME = do-op

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

SRCS = do_op.c operate.c tool.c tool2.c
OBJS = $(SRCS:.c=.o)

.PHONY: all
all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ -I mylib.h

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
