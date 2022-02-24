# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 13:32:57 by minjeki2          #+#    #+#              #
#    Updated: 2022/02/24 15:25:06 by minjeki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

SRCS = do_op.c operate.c tool.c
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
