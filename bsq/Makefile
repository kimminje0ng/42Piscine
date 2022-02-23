NAME = bsq

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = includes

SRCS = $(SRCDIR)/utils.c $(SRCDIR)/error.c $(SRCDIR)/file_reader.c $(SRCDIR)/find_square.c $(SRCDIR)/ft_split.c $(SRCDIR)/main.c $(SRCDIR)/make_grid.c $(SRCDIR)/print_map.c $(SRCDIR)/valid_map.c
OBJS = $(SRCS:.c=.o)

.PHONY: all
all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ -I $(INCDIR)

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
