/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 22:53:52 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/31 01:32:11 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_data.h"

void	ms_execute(t_ms_data *msd)
{
	ft_print_words_tables(msd->cmd);	/*TEMP TESTING*/
	ft_wtfree(msd->cmd);
	msd->cmd = NULL;
}
