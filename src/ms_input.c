/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:42:19 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/17 11:26:26 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include "ms_data.h"

void		ms_restart(int iargc, char **iargv, char **ienv, int rs_do)
{
	int		argc = 0;
	char	**argv = NULL;
	char	**env = NULL;

	if (rs_do == MS_LOAD)
	{
		argc = iargc;
		argv = iargv;
		ienv = env;
	}
	else if (rs_do == MS_RESTART)
	{
		if (execve(argv[0], argv, env) == -1)
			frexit();
	}
}

static void	restart_input(int sig)
{
	(void)sig;
	//write(1, "\n", 1);
	heap_collector(NULL, HS_FREE);
	ms_restart(0, NULL, NULL, MS_RESTART);
}

/*right now this function is pretty useless, but there are
  cool and easy bonuses to do here*/
static void	print_prompt(t_ms_data *msd)
{
	(void)msd;
	ft_printf("$> ");
}

void		ms_input(t_ms_data *msd)
{
	print_prompt(msd);
	signal(SIGINT, restart_input);
	get_next_line(0, &msd->input_buffer);
	signal(SIGINT, SIG_IGN);
	if (msd->input_buffer)
		ft_printf("input is: '%s'\n", msd->input_buffer);
}
