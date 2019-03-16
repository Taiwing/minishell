/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:17:11 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/16 12:37:44 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_cmd.h"
#include "fatal_error.h"

void	fatal_error(t_ms_data *msd)
{
	(void)msd;	//this will have to be removed from parameters
	heap_collector(NULL, HS_FREE);
	exit(FATAL_ERROR);
}
