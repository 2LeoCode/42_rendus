SHELL=bash

NAME=philo

SRCD=src
INCD=inc
OBJD=.obj

SRC=$(wildcard $(SRCD)/*.c)
INC=$(wildcard $(INCD)/*.h)
OBJ=$(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRC))

CC=clang
CFLAGS=-Wall -Wextra -Werror #-g3 -fsanitize=thread
LFLAGS=-lpthread

all: $(OBJD) $(NAME)

$(OBJD):
	mkdir $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I$(INCD) $^ -o $@ $(LFLAGS)

$(OBJD)/%.o: $(SRCD)/%.c $(INC) Makefile
	$(CC) $(CFLAGS) -I$(INCD) -c $< -o $@

clean:
	rm -rf $(OBJD)

fclean: clean
	rm -f $(NAME)

re: fclean all
