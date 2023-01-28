NAME=litteral

CC=clang++
CFLAGS=-Wall -Werror -Wextra -std=c++98#-g3 -fsanitize=address
LFLAGS=-lm

INC=Litteral.hpp
SRC=$(addsuffix .cpp, Litteral main)
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

%.o: %.cpp $(INC) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
