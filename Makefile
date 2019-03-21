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

EXECTIONDIR		=	exection
INPUTDIR		=	input
PARSINGDIR		=	parsing

SRCC			=	main.c\
					ms_init.c\

EXECTIONC		=	
INPUTC			=	dllst.c\
					dllst_str.c\
					ms_input.c\

PARSINGC		=	ms_cmd.c\

ODIR			=	obj
OBJ				=	$(patsubst %.c,%.o,$(EXECTIONC))\
					$(patsubst %.c,%.o,$(INPUTC))\
					$(patsubst %.c,%.o,$(PARSINGC))\
					$(patsubst %.c,%.o,$(SRCC))\

vpath			%.o	$(ODIR)
vpath			%.h	$(HDIR)
vpath			%.h	$(SRCDIR)/$(SUB1D)/$(HDIR)
vpath			%.c	$(SRCDIR)/$(EXECTIONDIR)
vpath			%.c	$(SRCDIR)/$(INPUTDIR)
vpath			%.c	$(SRCDIR)/$(PARSINGDIR)
vpath			%.c	$(SRCDIR)

############################## BUILD ###########################################

all: $(NAME)

$(NAME): libft.a $(ODIR) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(patsubst %.o,$(ODIR)/%.o,$(OBJ)) $(LIBS)

libft.a:
	make -C $(SRCDIR)/$(SUB1D)

dllst.o: dllst.h libft.h
dllst_str.o: dllst.h libft.h
ms_input.o: ms_data.h libft.h dllst.h
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
