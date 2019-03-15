/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:17:11 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/15 14:30:52 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_data.h"
#include "ms_cmd.h"

void	fatal_error(t_ms_data *msd)
{
	ft_wtfree(msd->env);
	free(msd->input_buffer);
	if (msd->cmd_list)
		ft_lstdel(&msd->cmd_list, del_cmd);
	exit(FATAL_ERROR);
}
