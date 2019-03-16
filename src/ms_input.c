/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:42:19 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/16 18:10:31 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include "ms_data.h"

static void	restart_input(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	frexit();
}

/*right now this function is pretty useless, but there are
  cool and easy bonuses to do here*/
static void	print_prompt(t_ms_data *msd)
{
	(void)msd;
	ft_printf("$> ");
}

static void	read_input(t_ms_data *msd, int fildes[2])
{
	int	size;

	size = 0;
	signal(SIGINT, restart_input);
	get_next_line(0, &msd->input_buffer);
	signal(SIGINT, SIG_IGN);
	size = msd->input_buffer ? ft_strlen(msd->input_buffer) + 1 : 0;
	write(fildes[1], &size, sizeof(int));
	if (size)
		write(fildes[1], msd->input_buffer, size);
	heap_collector(NULL, HS_FREE);
	exit(EXIT_SUCCESS);
}

static char	*get_input(int fildes[2])
{
	char	*buf;
	int		size;

	buf = NULL;
	read(fildes[0], &size, sizeof(int));
	if (size)
	{
		buf = (char *)ft_secmalloc(size * sizeof(char));
		read(fildes[0], buf, size);
		ft_printf("input is: '%s'\n", buf);
	}
	return (buf);
}

void		ms_input(t_ms_data *msd)
{
	pid_t	p;
	int		ret;
	int		fildes[2];

	ret = 0;
	if (pipe(fildes))
		frexit();
	print_prompt(msd);
	if ((p = fork()) == -1)
		frexit();
	if (!p)
		read_input(msd, fildes);
	if (wait(&ret) == -1)
		frexit();
	msd->input_buffer = !ret ? get_input(fildes) : NULL;
	close(fildes[0]);
	close(fildes[1]);
}
