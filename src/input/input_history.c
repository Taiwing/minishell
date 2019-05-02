/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 07:54:37 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/03 00:25:53 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_input.h"
#include "charfunc.h"
#include "terminal_cursor.h"

void		save_current_line(t_input_data *idat, t_ms_history *hist)
{
	char	*raw;

	if (!idat->hi)
		idat->buf = dllst_to_str(dllst_first(idat->lst));
	else
	{
		ft_memdel((void **)&hist->cmd[hist->size - idat->hi]);
		raw = dllst_to_str(dllst_first(idat->lst));
		hist->cmd[hist->size - idat->hi] = ft_stradd(&raw, "\n", 1);
	}
}

static void	erase_current_line(t_input_data *idat, t_ms_data *msd)
{
	if (!idat->lst)
		return ;
	move_end(idat, msd);
	while (!idat->bol)
	{
		if (!idat->lst->prev)
			idat->bol = 1;
		if (idat->cursor_pos[X] == 1)
		{
			--idat->cursor_pos[Y];
			idat->cursor_pos[X] = msd->term_width;
		}
		else
			--idat->cursor_pos[X];
		ft_putstr_fd("\010 \010", 0);
		dllst_remove_back(&idat->lst);
	}
}

void		restore(t_input_data *idat, t_ms_history *hist, t_ms_data *msd)
{
	erase_current_line(idat, msd);
	if (!idat->hi && idat->buf)
	{
		idat->lst = dllst_last(str_to_dllst(idat->buf));
		ft_dprintf(0, "%s", idat->buf);
		get_curs_pos(idat->cursor_pos);
		idat->bol = idat->lst ? 0 : 1;
	}
	else if (idat->hi)
	{
		idat->lst = dllst_last(str_to_dllst(hist->cmd[hist->size - idat->hi]));
		if (idat->lst)
		{
			dllst_remove_back(&idat->lst);
			ft_dprintf(0, "%.*s",
				ft_strlen(hist->cmd[hist->size - idat->hi]) - 1,
				hist->cmd[hist->size - idat->hi]);
			get_curs_pos(idat->cursor_pos);
		}
		idat->bol = idat->lst ? 0 : 1;
	}
}
