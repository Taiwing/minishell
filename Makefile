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

EXECUTIONDIR	=	execution
INPUTDIR		=	input
PARSINGDIR		=	parsing

SRCC			=	main.c\
					ms_init.c\

EXECUTIONC		=	
INPUTC			=	char_functions_1.c\
					char_functions_2.c\
					char_functions_3.c\
					charfunc.c\
					dllst_insert.c\
					dllst_move.c\
					dllst_remove.c\
					dllst_str.c\
					ms_input.c\

PARSINGC		=	ms_cmd.c\

ODIR			=	obj
OBJ				=	$(patsubst %.c,%.o,$(EXECUTIONC))\
					$(patsubst %.c,%.o,$(INPUTC))\
					$(patsubst %.c,%.o,$(PARSINGC))\
					$(patsubst %.c,%.o,$(SRCC))\

vpath			%.o	$(ODIR)
vpath			%.h	$(HDIR)
vpath			%.h	$(SRCDIR)/$(SUB1D)/$(HDIR)
vpath			%.c	$(SRCDIR)/$(EXECUTIONDIR)
vpath			%.c	$(SRCDIR)/$(INPUTDIR)
vpath			%.c	$(SRCDIR)/$(PARSINGDIR)
vpath			%.c	$(SRCDIR)

############################## BUILD ###########################################

all: $(NAME)

$(NAME): libft.a $(ODIR) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(patsubst %.o,$(ODIR)/%.o,$(OBJ)) $(LIBS)

libft.a:
	make -C $(SRCDIR)/$(SUB1D)

char_functions_1.o: charfunc.h dllst.h ms_data.h libft.h
char_functions_2.o: charfunc.h dllst.h ms_data.h libft.h
char_functions_3.o: charfunc.h dllst.h ms_data.h libft.h
charfunc.o: charfunc.h dllst.h ms_data.h libft.h
dllst_insert.o: dllst.h libft.h
dllst_move.o: dllst.h libft.h
dllst_remove.o: dllst.h libft.h
dllst_str.o: dllst.h libft.h
ms_input.o: charfunc.h dllst.h ms_data.h libft.h
main.o: ms_data.h libft.h
ms_init.o: libft.h ms_data.h
ms_cmd.o: ms_cmd.h ms_data.h libft.h
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
