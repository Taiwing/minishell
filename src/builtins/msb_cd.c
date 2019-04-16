/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msb_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:32:03 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/16 21:44:33 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_data.h"
#include "t_shvar.h"
#include <sys/syslimits.h>

int	msb_cd(char **argv, t_ms_data *msd)
{
	char	curdir[PATH_MAX];
	
	if (!argv[1] || argv[2])
	{
		ft_putstr_fd("cd: wrong number of argument\n", 2);
		return (1);
	}
	if (chdir(argv[1]) == -1)
	{
		if (access(argv[1], F_OK) == -1)
			ft_dprintf(2, "cd: %s: no such file or directory\n", argv[1]);
		else
			ft_dprintf(2, "cd: %s: is not a directory\n", argv[1]);
		return (1);
	}
	else if (!getcwd(curdir, PATH_MAX))
	{
		set_shvar("PWD", NULL, &msd->env);
		return (1);
	}
	else
		set_shvar("PWD", curdir, &msd->env);
	return (0);
}
