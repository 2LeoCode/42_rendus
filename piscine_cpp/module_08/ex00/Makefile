NAME=easyfind

CC=c++
CFLAGS=-MMD -Wall -Werror -Wextra -std=c++98 #-g3 -fsanitize=address

SRC=main.cpp
OBJ=$(SRC:.cpp=.o)
DEP=$(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP)

clean:
	rm -rf $(OBJ) $(DEP)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
