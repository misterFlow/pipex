# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguy <marvin@42lausanne.ch>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 21:43:38 by fguy              #+#    #+#              #
#    Updated: 2022/06/24 21:43:42 by fguy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror

INC = ./inc/pipex.h \

SRC = \
	./src/main.c \
	./src/pipex.c \
	./src/pipex_utils.c \
	./src/string_utils.c \
	./src/ft_splitpath.c \
	./src/free.c \

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re