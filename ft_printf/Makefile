# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/05 16:16:39 by lsuardi           #+#    #+#              #
#    Updated: 2020/05/31 15:45:22 by lsuardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
_SRCS		=	ft_printf\
				printf_main\
				flags\
				flags_2\
				utils\
				utils_2\
				utils_3\
				utils_4\
				utils_5\
				list\
				print_address\
				print_char\
				print_str\
				print_unsigned_int\
				print_int\
				print_hexa\
				print_def
__SRCS		=	$(addsuffix .c, ${_SRCS})
OBJ			=	$(__SRCS:.c=.o)
OBJDIR		=	obj
SRCSDIR		=	src
CFLAGS		=	-Wall -Wextra -Werror
GREEN		=	\x1b[32m
PURPLE		=	\x1b[35m

all: $(NAME)
	@(ranlib $(NAME) && echo '$(GREEN)$(NAME) is up to date')

$(NAME): $(addprefix ${OBJDIR}/, ${OBJ})
	@(ar rc $@ $^ && printf '\n')

$(OBJDIR)/%.o: $(SRCSDIR)/%.c | $(OBJDIR)
	@(printf '$(PURPLE)\rCompiling' && gcc $(CFLAGS) -c $< -o $@ -I inc && printf ' (' && ls $(OBJDIR)/*.o |wc -l |tr -d ' \n' && printf ' / ' && ls $(SRCSDIR)/*.c |wc -w |tr -d ' \n' && printf ')')

$(OBJDIR):
	@(mkdir $(OBJDIR))

clean:
	@(rm -rf $(OBJDIR) && echo '$(GREEN)Removed [obj]')

fclean: clean
	@(rm -f $(NAME) && echo '$(GREEN)Removed [$(NAME)]')

re: fclean all
