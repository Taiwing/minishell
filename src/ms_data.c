/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:20:09 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/16 12:39:19 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_cmd.h"

void	flush_msd(int op, t_ms_data *msd_ptr)
{
	static t_ms_data	*msd = NULL;

	if (op == LOAD_MSD)
		msd = msd_ptr;
	else if (op == FLUSH_ENV)
		ft_wtfree(msd->env);
	else if (op == FLUSH_INPUT)
	{
		free(heap_collector(msd->input_buffer, HS_GET));
		msd->input_buffer = NULL;
	}
	else if (op == FLUSH_CMD)
		ft_lstdel(&msd->cmd_list, del_cmd);
	else if (op == FLUSH_ALL)
	{
		ft_wtfree(msd->env);
		free(heap_collector(msd->input_buffer, HS_GET));
		ft_lstdel(&msd->cmd_list, del_cmd);
	}
}
