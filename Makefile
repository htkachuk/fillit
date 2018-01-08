# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 14:53:42 by htkachuk          #+#    #+#              #
#    Updated: 2018/01/03 14:53:50 by htkachuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit_part1.c\
	  fillit_part2.c\
	  fillit_part3.c\
	  fillit_part4.c\
	  fillit_part5.c\
	  fillit_part6.c\
	  main.c

INC = fillit.h

OBJ = $(SRC:%.c=%.o)

CC = gcc

KEYS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(KEYS) -o $(NAME) $(OBJ) -I .

%.o: %.c
	$(CC) $(KEYS) -c $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean
