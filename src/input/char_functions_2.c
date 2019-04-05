/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:01:02 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/05 16:41:20 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "charfunc.h"

int	last_cmd(t_input_data *idat, t_ms_data *msd)
{
	(void)msd;
	(void)idat;
	return (CONTINUE_INPUT);
}

int	next_cmd(t_input_data *idat, t_ms_data *msd)
{
	(void)msd;
	(void)idat;
	return (CONTINUE_INPUT);
}

/*TODO: modify this so that it can move back at the first position on the line*/
int	move_left(t_input_data *idat, t_ms_data *msd)
{
	(void)msd;
	if (idat->lst && !idat->bol)
	{
		if (idat->lst->prev)
			idat->lst = idat->lst->prev;
		else
			idat->bol = 1;
		write(0, idat->c, 3);
	}
	return (CONTINUE_INPUT);
}

int	move_right(t_input_data *idat, t_ms_data *msd)
{
	(void)msd;
	if (idat->lst)
	{
		if (!idat->bol)
		{
			if (!idat->lst->next)
				return (CONTINUE_INPUT);
			else
				idat->lst = idat->lst->next;
		}
		idat->bol = 0;
		write(0, idat->c, 3);
	}
	return (CONTINUE_INPUT);
}

int	move_beg(t_input_data *idat, t_ms_data *msd)
{
	size_t	sz;

	(void)msd;
	if (!idat->bol)
	{
		sz = 1;
		while (idat->lst->prev)
		{
			idat->lst = idat->lst->prev;
			++sz;
		}
		while (sz--)
			write(0, g_multibyte_chars[LEFT_ARROW - 11], 3);
		idat->bol = 1;
	}
	return (CONTINUE_INPUT);
}
