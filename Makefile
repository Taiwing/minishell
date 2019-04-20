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

BUILTINSDIR		=	builtins
EXECUTIONDIR	=	execution
INPUTDIR		=	input
LEXINGDIR		=	lexing
PARSINGDIR		=	parsing

SRCC			=	env.c\
					main.c\
					ms_init.c\
					ms_signals.c\
					quotes.c\
					t_shvar.c\

BUILTINSC		=	g_builtins.c\
					msb_cd.c\
					msb_echo.c\
					msb_env.c\
					msb_exit.c\
					msb_pwd.c\
					msb_setenv.c\
					msb_unsetenv.c\

EXECUTIONC		=	exec.c\
					ms_execution.c\

INPUTC			=	char_functions_1.c\
					char_functions_2.c\
					char_functions_3.c\
					charfunc.c\
					charfunc_utils.c\
					completion_utils.c\
					dllst_insert.c\
					dllst_move.c\
					dllst_remove.c\
					dllst_str.c\
					env_completion.c\
					exec_completion.c\
					file_completion.c\
					ms_input.c\
					tab_completion.c\

LEXINGC			=	ms_lexing.c\
					token.c\

PARSINGC		=	ms_parsing.c\
					param_exp.c\
					tilde_exp.c\

ODIR			=	obj
OBJ				=	$(patsubst %.c,%.o,$(BUILTINSC))\
					$(patsubst %.c,%.o,$(EXECUTIONC))\
					$(patsubst %.c,%.o,$(INPUTC))\
					$(patsubst %.c,%.o,$(LEXINGC))\
					$(patsubst %.c,%.o,$(PARSINGC))\
					$(patsubst %.c,%.o,$(SRCC))\

vpath			%.o	$(ODIR)
vpath			%.h	$(HDIR)
vpath			%.h	$(SRCDIR)/$(SUB1D)/$(HDIR)
vpath			%.c	$(SRCDIR)/$(BUILTINSDIR)
vpath			%.c	$(SRCDIR)/$(EXECUTIONDIR)
vpath			%.c	$(SRCDIR)/$(INPUTDIR)
vpath			%.c	$(SRCDIR)/$(LEXINGDIR)
vpath			%.c	$(SRCDIR)/$(PARSINGDIR)
vpath			%.c	$(SRCDIR)

############################## BUILD ###########################################

all: $(NAME)

$(NAME): libft.a $(ODIR) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(patsubst %.o,$(ODIR)/%.o,$(OBJ)) $(LIBS)

libft.a:
	make -C $(SRCDIR)/$(SUB1D)

g_builtins.o: g_builtins.h ms_data.h libft.h
msb_cd.o: ms_data.h libft.h t_shvar.h
msb_echo.o: ms_data.h libft.h
msb_env.o: t_shvar.h libft.h ms_execution.h ms_data.h
msb_exit.o: ms_data.h libft.h
msb_pwd.o: ms_data.h libft.h t_shvar.h
msb_setenv.o: t_shvar.h libft.h ms_data.h
msb_unsetenv.o: t_shvar.h libft.h ms_data.h
env.o: t_shvar.h libft.h
exec.o: ms_data.h libft.h t_shvar.h ms_signals.h
ms_execution.o: exec.h ms_data.h libft.h g_builtins.h ms_execution.h
char_functions_1.o: charfunc.h ms_input.h ms_data.h libft.h t_dllst.h quotes.h\
	tab_completion.h
char_functions_2.o: charfunc.h ms_input.h ms_data.h libft.h t_dllst.h
char_functions_3.o: charfunc.h ms_input.h ms_data.h libft.h t_dllst.h
charfunc.o: charfunc.h ms_input.h ms_data.h libft.h t_dllst.h
charfunc_utils.o: charfunc.h ms_input.h ms_data.h libft.h t_dllst.h quotes.h
completion_utils.o: libft.h
dllst_insert.o: t_dllst.h libft.h
dllst_move.o: t_dllst.h libft.h
dllst_remove.o: t_dllst.h libft.h
dllst_str.o: t_dllst.h libft.h
env_completion.o: tab_completion.h ms_input.h ms_data.h libft.h t_dllst.h\
	t_shvar.h
exec_completion.o: tab_completion.h ms_input.h ms_data.h libft.h t_dllst.h\
	g_builtins.h
file_completion.o: tab_completion.h ms_input.h ms_data.h libft.h t_dllst.h
ms_input.o: charfunc.h ms_input.h ms_data.h libft.h t_dllst.h quotes.h
tab_completion.o: tab_completion.h ms_input.h ms_data.h libft.h t_dllst.h\
	charfunc.h quotes.h
ms_lexing.o: token.h libft.h quotes.h ms_lexing.h ms_data.h
token.o: token.h libft.h quotes.h
main.o: ms_input.h ms_data.h libft.h t_dllst.h ms_lexing.h ms_parsing.h\
	ms_execution.h
ms_init.o: ms_data.h libft.h t_shvar.h ms_signals.h
ms_signals.o: libft.h
ms_parsing.o: token.h libft.h tilde_exp.h ms_data.h param_exp.h quotes.h
param_exp.o: ms_data.h libft.h quotes.h t_shvar.h
tilde_exp.o: ms_data.h libft.h t_shvar.h
quotes.o: quotes.h
t_shvar.o: t_shvar.h libft.h
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
