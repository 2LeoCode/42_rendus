# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 18:15:21 by user42            #+#    #+#              #
#    Updated: 2020/12/03 20:56:30 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		test

SRC =		main.c\
			tests.c\
			utils.c
OBJ =		$(SRC:.c=.o)
LIB =		libasm.a\
			libasm_bonus.a

LIBDIR =	..
SRCDIR =	.
OBJDIR =	obj

SRCPATH =	$(addprefix $(SRCDIR)/, $(SRC))
OBJPATH =	$(addprefix $(OBJDIR)/, $(OBJ))
LIBPATH =	$(addprefix $(LIBDIR)/, $(LIB))

all: $(OBJDIR) $(NAME)
	@(echo 'Test program for libasm is up to date.')

$(OBJDIR):
	@(mkdir $@)

$(NAME): $(OBJPATH)
	@(echo 'Compiling test program for libasm...'; gcc -no-pie $^ $(LIBPATH) -o $@)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@(echo 'Compiling $<...'; gcc -c $< -o $@)

clean:
	@(rm -rf $(OBJDIR); echo 'Removed ./$(OBJDIR)')

fclean: clean
	@(rm -rf $(NAME); echo 'Removed ./$(NAME)')

re: fclean all
