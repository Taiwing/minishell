/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 01:33:16 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/13 01:48:38 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

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

	if ((cp = stat_pid(0)))
		kill(cp, sig);
}

void	init_signals(void)
{
	int	i;

	i = 0;
	while (++i < 31)
		signal(i, &signal_hand);
}
