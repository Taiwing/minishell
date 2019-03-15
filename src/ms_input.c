/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:42:19 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/15 18:07:24 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "fatal_error.h"

static void	restart_input(int sig)
{
	static int	restart = 0;

	if (!restart && sig == SIGINT)
		restart = 1;
	else if (restart)
	{
		flush_msd(FLUSH_INPUT, NULL);
		restart = 0;
	}
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
	if (get_next_line(0, &msd->input_buffer) == -1)
		fatal_error(msd);
	restart_input(0);
	signal(SIGINT, SIG_IGN);
}
