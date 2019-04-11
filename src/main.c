/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:58:02 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/11 22:16:20 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_input.h"
#include "ms_lexing.h"
#include "ms_parsing.h"

int		main(int argc, char **argv, char **env)
{
	t_ms_data	msd;
	char		**cmd;
	char		*input;
	t_list		*cmd_list;

	(void)argc;
	(void)argv;
	cmd = NULL;
	input = NULL;
	cmd_list = NULL;
	ms_init(&msd, env);

	int	c; //TEMP

	while (1)
	{
		if (!input)
			input = ms_input(&msd, NO_QUOTE);
		if (input)
			cmd_list = ms_lexing(&input);
		c = 0;
		while (cmd_list)
		{
			if ((cmd = ms_parsing(&msd, &cmd_list)))
				//ms_execute(&msd, &cmd);
				//TEMP
			{
				ft_dprintf(0, "command %d: %#*t%s \n", ++c, ft_wtlen(cmd), cmd);
				ft_wtfree(cmd);
				cmd = NULL;
			}
		}
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
