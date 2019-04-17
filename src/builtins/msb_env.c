/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msb_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:17:06 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/18 00:44:15 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_data.h"
#include "t_shvar.h"

/*static int		mod_env(char **argv, t_ms_data *msd, int empty_env)
{
	t_list	*env_backup;
	t_shvar	*tmpvar;

	env_backup = NULL;
	if (empty_env)
	{
		env_backup = msd->env;
		msd->env = NULL;
	}
	while ((svar = get_tmpvar(*argv)))
	{
		
	}
}*/

int				msb_env(char **argv, t_ms_data *msd)
{
	//t_optdata	od;
	int			argc;
	char		**env;
	int			empty_env;

	empty_env = 0;
	if ((argc = ft_wtlen(argv)) == 1)
	{
		if ((env = list_to_env(msd->env)))
		{
			ft_print_words_tables(env);
			ft_wtfree(env);
		}
		return (0);
	}
	/*
	else
	{
		while (ft_getopt(argc, argv, &od) != -1)
			empty_env = 1;
		argv += od.optind;
		if (*argv)
			return (mod_env(argv, msd, empty_env));
	}*/
	return (1);
}
