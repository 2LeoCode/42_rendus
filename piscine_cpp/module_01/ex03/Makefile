# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 01:17:37 by Leo Suardi        #+#    #+#              #
#    Updated: 2022/01/19 13:35:54 by Leo Suardi       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=unnecessary_violence

INC=$(wildcard *.hpp)
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

CC=clang++
CFLAGS=-Wall -Werror -Wextra -std=c++98 #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp $(INC) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
