/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:30:45 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/12 11:23:26 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <termios.h>
#include "ms_data.h"
#include "t_shvar.h"

static t_list	*init_env(char **env)
{
	t_list	*lst;
	t_shvar	envar;
	char	*delim;

	lst = NULL;
	envar.type = ENV_GLOBAL;
	while (*env)
	{
		delim = ft_strchr(*env, '=');
		envar.name = ft_strsub(*env, 0, delim - *env);
		envar.value = delim[1] ?
			ft_strsub(delim + 1, 0, ft_strlen(delim + 1)) : NULL;
		ft_lst_sorted_insert(&lst, ft_lstnew((void *)&envar, sizeof(t_shvar)),
			shvar_cmp);
		++env;
	}
	return (lst);
}

static void		reset_input_mode(void)
{
	static struct termios	*old_tattr = NULL;
	struct termios			new_tattr;

	if (!old_tattr)
	{
		if (tcgetattr(0, &new_tattr) == -1)
			ft_exit("failed to get terminal attributes", EXIT_FAILURE);
		old_tattr = (struct termios *)ft_secmalloc(sizeof(struct termios));
		ft_memcpy(old_tattr, &new_tattr, sizeof(struct termios));
		new_tattr.c_lflag &= ~(ICANON | ECHO | ISIG);
		new_tattr.c_cc[VMIN] = 1;
		new_tattr.c_cc[VTIME] = 0;
		if (tcsetattr(0, TCSAFLUSH, &new_tattr) == -1)
			ft_exit("failed to set terminal attributes", EXIT_FAILURE);
	}
	else 
		tcsetattr(0, TCSANOW, old_tattr); 
}

void			ms_init(t_ms_data *msd, char **env)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGHUP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	ft_exitmsg("minishell");
	if (!isatty(0))
		ft_exit("not a terminal", EXIT_FAILURE);
	reset_input_mode();
	ft_atexit(reset_input_mode);
	msd->env = init_env(env);
	msd->cmd_exit = 0;
	msd->process_id = 0;	//TEMP (see how to get this shit)
}
