/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 22:53:52 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/31 17:10:03 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_data.h"

void	ms_execute(t_ms_data *msd)
{
	ft_dprintf(0, "\ncurrent command:\n");	/*TEMP TESTING*/
	ft_print_words_tables_fd(msd->cmd, 0);	/*TEMP TESTING*/
	ft_wtfree(msd->cmd);
	msd->cmd = NULL;
}
