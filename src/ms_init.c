/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:30:45 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/20 17:53:54 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include "ms_data.h"
#include "t_shvar.h"
#include "ms_signals.h"

void		set_custom_input_mode(void)
{
	struct termios			new_tattr;
	
	if (tcgetattr(0, &new_tattr) == -1)
		ft_exit("failed to get terminal attributes", EXIT_FAILURE);
	new_tattr.c_lflag &= ~(ICANON | ECHO | ISIG);
	new_tattr.c_cc[VMIN] = 1;
	new_tattr.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSAFLUSH, &new_tattr) == -1)
		ft_exit("failed to set terminal attributes", EXIT_FAILURE);
}

void		reset_input_mode(void)
{
	static struct termios	*old_tattr = NULL;

	if (!old_tattr)
	{
		old_tattr = (struct termios *)ft_secmalloc(sizeof(struct termios));
		if (tcgetattr(0, old_tattr) == -1)
			ft_exit("failed to get terminal attributes", EXIT_FAILURE);
		set_custom_input_mode();
	}
	else 
		tcsetattr(0, TCSANOW, old_tattr); 
}

void			ms_init(t_ms_data *msd, char **env)
{
	init_signals();
	ft_exitmsg("minishell");
	ft_dir_container();
	ft_atexit(ft_close_dir_stack);
	if (!isatty(0))
		ft_exit("not a terminal", EXIT_FAILURE);
	reset_input_mode();
	ft_atexit(reset_input_mode);
	msd->env = env_to_list(env);
	msd->path = ft_strsplit(get_shvar_val("PATH", msd->env), ':');
	msd->cmd_exit = 0;
	msd->process_id = 0;	//TEMP (see how to get this shit)
}
