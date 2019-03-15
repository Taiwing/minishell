/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:17:11 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/15 17:41:47 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_cmd.h"
#include "fatal_error.h"

void	fatal_error(t_ms_data *msd)
{
	ft_wtfree(msd->env);
	free(msd->input_buffer);
	ft_lstdel(&msd->cmd_list, del_cmd);
	exit(FATAL_ERROR);
}
