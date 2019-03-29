/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:30:45 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/29 21:12:36 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <termios.h>
#include "libft.h"
#include "ms_data.h"

static char	*get_path(t_ms_data *msd)
{
	char	**env;

	env = msd->env;
	while (env && ft_strncmp(*env, "PATH=", 5))
		++env;
	return (!env || !*env ? NULL : *env + 5);
}

//TODO: check where this function can fail
static void	reset_input_mode(void)
{
	static struct termios	*old_tattr = NULL;
	struct termios			new_tattr;

	if (!old_tattr)
	{
		tcgetattr(0, &new_tattr);
		old_tattr = (struct termios *)ft_secmalloc(sizeof(struct termios));
		ft_memcpy(old_tattr, &new_tattr, sizeof(struct termios));
		new_tattr.c_lflag &= ~(ICANON | ECHO | ISIG);
		new_tattr.c_cc[VMIN] = 1;
		new_tattr.c_cc[VTIME] = 0;
		tcsetattr(0, TCSAFLUSH, &new_tattr);
	}
	else 
		tcsetattr(0, TCSANOW, old_tattr); 
}

void		ms_init(t_ms_data *msd, char **env)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGHUP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	ft_exitmsg("minishell");
	msd->cmd_list = NULL;
	msd->input_buffer = NULL;
	msd->env = env ? ft_wtdup(env) : NULL;
	msd->envc = env ? ft_wtlen(msd->env) : 0;
	msd->envsize = env ? msd->envc + 1 : 0;
	msd->path = get_path(msd);
	reset_input_mode();
	ft_atexit(reset_input_mode);
}
