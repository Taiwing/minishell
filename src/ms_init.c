/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:30:45 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/16 18:23:34 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"
#include "ms_data.h"

static char	*get_path(t_ms_data *msd)
{
	char	**env;

	env = msd->env;
	while (env && ft_strncmp(*env, "PATH=", 5))
		++env;
	return (!env || !*env ? NULL : *env + 5);
}

void		ms_init(t_ms_data *msd, char **env)
{
	signal(SIGINT, SIG_IGN);
	msd->cmd_list = NULL;
	msd->input_buffer = NULL;
	msd->env = env ? ft_wtdup(env) : NULL;
	msd->envc = env ? ft_wtlen(msd->env) : 0;
	msd->envsize = env ? msd->envc + 1 : 0;
	msd->path = get_path(msd);
}
