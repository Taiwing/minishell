/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:29:38 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/12 14:59:38 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_builtins.h"

static int	builtin_match(char *name)
{
	int	i;

	i = -1;
	while (++i < BUILTIN_COUNT)
	{
		if (!ft_strcmp(name, g_builtins[i].name))
			return (0);
	}
	return (-1);
}

void		ms_execution(t_ms_data *msd, char ***cmd)
{
	char	**argv;
	int		buid;

	argv = *cmd;
	/*if (ft_strchr(argv[0], '/'))
		exec_local_file(msd, argv);
	else*/ if ((buid = builtin_match(argv[0])) >= 0)
		msd->cmd_exit = g_builtins[buid].bi(argv, msd);
	else			//TEMP (to avoid freeing cmd at the end)
		return ;	//TEMP
	/*else
		exec_on_path(msd, argv);*/
	ft_wtfree(argv);
	*cmd = NULL;
}
