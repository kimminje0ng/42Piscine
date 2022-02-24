# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 16:16:59 by minjeki2          #+#    #+#              #
#    Updated: 2022/02/24 16:21:12 by minjeki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = includes

SRCS = $(SRCDIR)/ft_display_file.c
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
