/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_getopt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 10:29:39 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/29 18:48:07 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

void	init_getopt(t_optdata *data, char *optstring,
					t_opt *longopts, int *longindex)
{
	data->optind = 1;
	data->optopt = 0;
	data->optarg = 0;
	data->longopts = longopts;
	data->lopts_len = 0;
	while (longopts && longopts->name)
	{
		++data->lopts_len;
		++longopts;
	}
	data->longindex = longindex;
	if (*optstring == '+' || *optstring == '-')
		data->order = *optstring++ - 42;
	else
		data->order = DEFAULT;
	data->optstring = optstring;
	data->opterr = *optstring != ':';
	data->longonly = 0;
	data->first_nonopt = 1;
	data->last_nonopt = 1;
	data->nextchar = "\0";
}
