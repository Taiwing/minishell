/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:33:05 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/12 22:25:20 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_data.h"
#include "t_shvar.h"

static int	exec_file(char *file_path, char **argv, char **env)
{
	pid_t	cp;
	int		ret;

	cp = 0;
	ret = 1;
	if ((cp = fork()) == -1)
		ft_putstr_fd("minishell: error while forking ;)\n", 2);
	else if (!cp)
	{
		if (execve(file_path, argv, env) == -1)
			ft_putstr_fd("minishell: execve() error\n", 2);
	}
	else if (wait(&ret) == -1)
		ft_putstr_fd("minishell: wait() error\n", 2);
	return (ret);
}

void		exec_local_file(t_ms_data *msd, char **argv)
{
	char	**env;

	if (access(argv[0], F_OK) == -1)
		ft_dprintf(2, "minishell: %s: command not found\n", argv[0]);
	else if (access(argv[0], X_OK) == -1)
		ft_dprintf(2, "minishell: %s: permission denied\n", argv[0]);
	else
	{
		env = load_env(msd->env);
		msd->cmd_exit = exec_file(argv[0], argv, env);
		ft_wtfree(env);
	}
}

void		exec_on_path(t_ms_data *msd, char **argv)
{
	char	*fp;
	char	**wt;

	wt = msd->path;
	while (wt && *wt)
	{
		fp = ft_strnew(ft_strlen(*wt) + 1 + ft_strlen(argv[0]));
		ft_strcat(ft_strcat(ft_strcat(fp, *wt), "/"), argv[0]);
		if (!access(fp, F_OK))
		{
			if (access(fp, X_OK) == -1)
				ft_dprintf(2, "minishell: %s: permission denied\n", argv[0]);
			else
			{
				wt = load_env(msd->env);
				msd->cmd_exit = exec_file(fp, argv, wt);
				ft_wtfree(wt);
			}
			ft_memdel((void **)&fp);
			return ;
		}
		ft_memdel((void **)&fp);
		++wt;
	}
	ft_dprintf(2, "minishell: %s: command not found\n", argv[0]);
}
