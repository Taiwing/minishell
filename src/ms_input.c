/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:42:19 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/18 12:42:35 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include "ms_data.h"

/*right now this function is pretty useless, but there are
  cool and easy bonuses to do here*/
static void	print_prompt(t_ms_data *msd)
{
	(void)msd;
	ft_printf("$> ");
}

void		ms_input(t_ms_data *msd)
{
	print_prompt(msd);
	get_next_line(0, &msd->input_buffer);
	if (msd->input_buffer)
		ft_printf("input is: '%s'\n", msd->input_buffer);
}
