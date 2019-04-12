/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msb_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:14:36 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/12 14:28:39 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_data.h"

static int	isnumstring(char *str)
{
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (0);
	}
	return (1);
}

int			msb_exit(char **argv, t_ms_data *msd)
{
	int	ret;

	if (!argv[1])
		ret = msd->cmd_exit;
	else if (isnumstring(argv[1]))
		ret = ft_atoi(argv[1]);
	else
	{
		ft_putstr_fd("minishell: exit: numeric argument required\n", 0);
		return (1);
	}
	if (ft_wtlen(argv) > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 0);
		return (1);
	}
	ft_exit(NULL, ret);
	return (0);
}
