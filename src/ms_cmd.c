/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:22:44 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/16 12:35:40 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_cmd.h"

void	del_cmd(void *cmd_ptr, size_t size)
{
	t_ms_cmd	*cmd;

	(void)size;
	cmd = (t_ms_cmd *)cmd_ptr;
	ft_wtfree(cmd->argv);
	ft_wtfree(cmd->env);
	free(heap_collector(cmd, HS_GET));
}
