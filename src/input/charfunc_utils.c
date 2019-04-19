/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charfunc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:40:04 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/19 18:52:46 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "charfunc.h"
#include "quotes.h"

/*
this function reprints the entire line after the last edited character
and adds the number one space and as many backspaces as there were characters
in the list (so that the cursor moves back into the right position)
*/

void	reprint_line(t_dllst *lst)
{
	size_t	sz;

	sz = dllst_print(lst) + 1;
	write(0, " ", 1);
	while (sz--)
		write(0, g_multibyte_chars[LEFT_ARROW - 11], 3);
}


void	check_input(t_input_data *idat, t_ms_data *msd)
{
	char	*recbuf;

	if ((idat->qmode = get_str_qmode(idat->qmode, idat->buf)) != NO_QUOTE)
	{
		if (!(recbuf = ms_input(msd, idat->qmode)))
		{
			ft_memdel((void **)&idat->buf);
			dllst_del(dllst_first(idat->lst));
			idat->lst = NULL;
			return ;
		}
		idat->buf = ft_stradd(&idat->buf, recbuf, ft_strlen(recbuf));
		free(ft_heap_collector(recbuf, FT_COLLEC_GET));
	}
}
