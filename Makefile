# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 19:06:55 by ccarnot           #+#    #+#              #
#    Updated: 2023/06/22 13:41:25 by ccarnot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -g3 -Wall -Wextra -Werror

SRC = settings1.c settings2.c find_keyval.c instructions.c moves1.c moves2.c ops_print1.c ops_print2.c \
	ops_print3.c sortings.c utils.c ft_split.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ)

all: $(NAME)

%.o: %.c
	cc -I $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
