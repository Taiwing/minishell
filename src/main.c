/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:58:02 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/06 20:10:18 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_input.h"

int		main(int argc, char **argv, char **env)
{
	t_ms_data	msd;
	char		*input;

	(void)argc;
	(void)argv;
	input = NULL;
	ms_init(&msd, env);
	while (1)
	{
		if (!input)
			input = ms_input(&msd, NO_QUOTE);
		//TEMP
		if (input)
		{
			if (!ft_strcmp(input, "exit\n"))
			{
				ft_atexit(NULL);
				ft_heap_collector(NULL, FT_COLLEC_FREE);
				break ;
			}
			else if (ft_strcmp(input, "\n"))
				ft_dprintf(0, "-> %s", input);
			ft_memdel((void **)&input);
		}
	}
	return (0);
}
