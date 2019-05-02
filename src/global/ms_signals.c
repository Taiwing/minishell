/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 01:33:16 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/02 21:46:22 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"
#include "terminal_size.h"
#include "terminal_cursor.h"

pid_t	stat_pid(pid_t in)
{
	static pid_t	out = 0;

	if (in == -1)
		out = 0;
	else if (in > 0)
		out = in;
	return (out);
}

void	signal_hand(int sig)
{
	pid_t	cp;
	int		*ptr;

	if ((cp = stat_pid(0)))
	{
		kill(cp, sig);
		if (sig == SIGINT)
			ft_putchar_fd('\n', 0);
		else if (sig == SIGWINCH)
		{
			//update term width
			if ((ptr = term_width_container(NULL)))
				*ptr = get_terminal_width();
			//update cursor position
			if ((ptr = curs_pos_container(NULL)))
				get_curs_pos(ptr);
		}
	}
}

void	init_signals(void)
{
	int	i;

	i = -1;
	while (++i < 31)
		signal(i, signal_hand);
}
