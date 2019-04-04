############################## COMPILE VAR #####################################

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
#CFLAGS		=	-g
HDIR		=	includes
SRCDIR		=	src
SUB1D		=	libft
HFLAGS		=	-I $(HDIR) -I $(SRCDIR)/$(SUB1D)/$(HDIR)
LIBS		=	$(SRCDIR)/$(SUB1D)/libft.a
NAME		=	minishell

############################## SOURCES #########################################

INPUTDIR		=	input

SRCC			=	main.c\
					ms_init.c\

INPUTC			=	char_functions_1.c\
					char_functions_2.c\
					char_functions_3.c\
					charfunc.c\
					charfunc_utils.c\
					dllst_insert.c\
					dllst_move.c\
					dllst_remove.c\
					dllst_str.c\
					ms_input.c\

ODIR			=	obj
OBJ				=	$(patsubst %.c,%.o,$(INPUTC))\
					$(patsubst %.c,%.o,$(SRCC))\

vpath			%.o	$(ODIR)
vpath			%.h	$(HDIR)
vpath			%.h	$(SRCDIR)/$(SUB1D)/$(HDIR)
vpath			%.c	$(SRCDIR)/$(INPUTDIR)
vpath			%.c	$(SRCDIR)

############################## BUILD ###########################################

all: $(NAME)

$(NAME): libft.a $(ODIR) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(patsubst %.o,$(ODIR)/%.o,$(OBJ)) $(LIBS)

libft.a:
	make -C $(SRCDIR)/$(SUB1D)

char_functions_1.o: charfunc.h dllst.h ms_input.h ms_data.h libft.h
char_functions_2.o: charfunc.h dllst.h ms_input.h ms_data.h
char_functions_3.o: charfunc.h dllst.h ms_input.h ms_data.h libft.h
charfunc.o: charfunc.h dllst.h ms_input.h ms_data.h
charfunc_utils.o: charfunc.h dllst.h ms_input.h ms_data.h
dllst_insert.o: dllst.h libft.h
dllst_move.o: dllst.h libft.h
dllst_remove.o: dllst.h libft.h
dllst_str.o: dllst.h libft.h
ms_input.o: charfunc.h dllst.h ms_input.h ms_data.h libft.h
main.o: ms_input.h ms_data.h dllst.h libft.h
ms_init.o: libft.h ms_data.h
%.o: %.c
	$(CC) -c $(CFLAGS) $< $(HFLAGS) -o $(ODIR)/$@

$(ODIR):
	mkdir -p $@

############################## CLEANUP #########################################

clean:
	rm -rf $(ODIR)
	make -C $(SRCDIR)/$(SUB1D) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
