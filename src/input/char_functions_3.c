/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:01:04 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/05 17:38:43 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "charfunc.h"
#include "libft.h"

int	move_end(t_input_data *idat, t_ms_data *msd)
{
	size_t	sz;

	(void)msd;
	if (idat->lst && (idat->lst->next || idat->bol))
	{
		sz = idat->bol ? 1 : 0;
		idat->bol = 0;
		while (idat->lst->next)
		{
			idat->lst = idat->lst->next;
			++sz;
		}
		while (sz--)
			write(0, g_multibyte_chars[RIGHT_ARROW - 11], 3);
	}
	return (CONTINUE_INPUT);
}

int	forwd_delete(t_input_data *idat, t_ms_data *msd)
{
	(void)msd;
	if (idat->lst && (idat->lst->next || idat->bol))
	{
		ft_putstr_fd(" \10", 0);
		if (idat->bol)
			dllst_remove_back(&idat->lst);
		else
			dllst_remove_forwd(&idat->lst);
		if (idat->lst)
		{
			if (idat->bol)
				reprint_line(idat->lst);
			else if (idat->lst->next)
				reprint_line(idat->lst->next);
		}
	}
	return (CONTINUE_INPUT);
}

int	insert_char(t_input_data *idat, t_ms_data *msd)
{
	(void)msd;
	write(0, idat->c, 1);
	if (!idat->bol)
		dllst_insert_forwd(&idat->lst, *idat->c);
	else
		dllst_insert_back(&idat->lst, *idat->c);
	if (idat->lst->next)
		reprint_line(idat->lst->next);
	idat->bol = 0;
	return (CONTINUE_INPUT);
}

int	back_delete(t_input_data *idat, t_ms_data *msd)
{
	(void)msd;
	if (!idat->bol)
	{
		if (!idat->lst->prev)
			idat->bol = 1;
		ft_putstr_fd("\010 \010", 0);
		dllst_remove_back(&idat->lst);
		if (idat->lst)
			reprint_line(idat->bol ? idat->lst : idat->lst->next);
	}
	return (CONTINUE_INPUT);
}
