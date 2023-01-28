# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 19:20:01 by user42            #+#    #+#              #
#    Updated: 2021/02/25 21:36:12 by lsuardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libasm.a
BNAME =		libasm_bonus.a

SRC =		ft_strlen.s\
			ft_strcpy.s\
			ft_strcmp.s\
			ft_write.s\
			ft_read.s\
			ft_strdup.s
BSRC =		ft_list_push_front_bonus.s\
			ft_list_size_bonus.s\
			ft_list_sort_bonus.s\
			ft_list_remove_if_bonus.s\
			ft_atoi_base_bonus.s
OBJ =		$(SRC:.s=.o)
BOBJ =		$(BSRC:.s=.o)
INC =		libasm.h
BINC =		libasm_bonus.h

INCDIR =	inc
SRCDIR =	src
OBJDIR =	obj
BOBJDIR =	obj_bonus
BSRCDIR =	src_bonus
BINCDIR =	inc_bonus

OBJPATH =	$(addprefix $(OBJDIR)/, $(OBJ))
BOBJPATH =	$(addprefix $(BOBJDIR)/, $(BOBJ))
INCPATH =	$(addprefix $(INCDIR)/, $(INC))
BINCPATH =	$(addprefix $(BINCDIR)/, $(BINC))


CFLAGS =	-f elf64

all: $(NAME)
	@(ranlib $<; echo '$< is up to date')

bonus: $(BNAME) all
	@(ranlib $<; echo '$< is up to date')

test: bonus
	@(cd testdir; $(MAKE))

$(NAME): $(OBJDIR) $(INCPATH) $(OBJPATH)
	@(echo 'Creating library...';\
	ar rcs $@ $(OBJPATH))

$(BNAME): $(BOBJDIR) $(BINCPATH) $(BOBJPATH)
	@(echo 'Creating bonus library...';\
	ar rcs $@ $(BOBJPATH))

$(BOBJDIR)/%.o: $(BSRCDIR)/%.s
	@(echo 'Compiling $<';\
	nasm $(CFLAGS) $< -o $@)

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	@(echo 'Compiling $<';\
	nasm $(CFLAGS) $< -o $@)

$(OBJDIR):
	@(mkdir $@)

$(BOBJDIR):
	@(mkdir $@)

clean:
	@(rm -rf $(OBJDIR) $(BOBJDIR);\
	echo 'Removed\n\t./$(OBJDIR)\n\t./$(BOBJDIR)')

fclean: clean
	@(rm -rf $(NAME) $(BNAME);\
	echo 'Removed\n\t./$(NAME)\n\t./$(BNAME)';\
	cd testdir;\
	$(MAKE) fclean)

re: fclean all
