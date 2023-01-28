NAME=real_type

CC=clang++
CFLAGS=-Wall -Werror -Wextra -std=c++98#-g3 -fsanitize=address

INC=$(addsuffix .hpp, Base A B C UniquePtr)
SRC=$(addsuffix .cpp, Base main)
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp $(INC) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
