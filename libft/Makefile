# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/24 15:26:22 by lsuardi           #+#    #+#              #
#    Updated: 2020/05/22 16:01:47 by lsuardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a
CFLAGS			= -Wall -Wextra -Werror
_SRCS			=	ft_atoi\
					ft_bzero\
					ft_calloc\
					ft_isalnum\
					ft_isalpha\
					ft_isascii\
					ft_isdigit\
					ft_isprint\
					ft_itoa\
					ft_memccpy\
					ft_memchr\
					ft_memcmp\
					ft_memcpy\
					ft_strlen\
					ft_memmove\
					ft_strdup\
					ft_memset\
					ft_putchar_fd\
					ft_putendl_fd\
					ft_strncmp\
					ft_putnbr_fd\
					ft_putstr_fd\
					ft_split\
					ft_strlcpy\
					ft_strrchr\
					ft_strchr\
					ft_strjoin\
					ft_strlcat\
					ft_strnstr\
					ft_strtrim\
					ft_substr\
					ft_tolower\
					ft_strmapi\
					ft_toupper
SRCS			= $(addsuffix .c, ${_SRCS})
INC				= libft.h
OBJ				= $(SRCS:.c=.o)
B_TARGET		=
_SRCS_BONUS		=	ft_lstclear\
					ft_lstdelone\
					ft_lstiter\
					ft_lstlast\
					ft_lstnew\
					ft_lstsize\
					ft_lstmap\
					ft_lstadd_back\
					ft_lstadd_front
SRCS_BONUS		= ${addsuffix .c, $(_SRCS_BONUS)}
OBJ_BONUS		= ${SRCS_BONUS:.c=.o}

ifeq ("$(wildcard ${NAME})", "")
	B_TARGET = all
endif

all: $(NAME)
	@(ranlib $(NAME) && echo 'Successfuly created $(NAME)')

$(NAME): $(OBJ)
	@(ar rc $@ $^)

bonus: $(B_TARGET) $(OBJ_BONUS)
	@(ar rcs $(NAME) $(OBJ_BONUS) && echo 'Successfully added bonus files to library')

%.o: %.c $(INC)
	@(printf 'Compiling (' && gcc $(CFLAGS) -c $< -o $@ && ls *.o |wc -l |sed 's/ //g'| tr -d '\n'  && printf ' / ' && ls *.c |wc -l |sed 's/ //g'| tr -d '\n' && echo ')')

clean:
	@(echo 'Removing obj'; $(foreach i, ${wildcard *.o}, rm -f ${i} && echo 'Removed [${i}]';))

fclean: clean
	@(rm -f $(NAME) && echo 'Removed [$(NAME)]')

re: fclean all
