# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crochu <crochu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 01:17:37 by Leo Suardi        #+#    #+#              #
#    Updated: 2021/11/02 16:16:32 by crochu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=scavtrap
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

CC=clang++
CFLAGS=-Wall -Werror -Wextra -std=c++98 #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
