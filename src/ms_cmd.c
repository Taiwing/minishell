/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:22:44 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/15 14:30:21 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_cmd.h"

void	del_cmd(void *cmd_ptr, size_t size)
{
	t_ms_cmd	*cmd;

	cmd = (t_ms_cmd *)cmd_ptr;
	ft_wtfree(cmd->argv);
	ft_wtfree(cmd->env);
	free(cmd);
}
