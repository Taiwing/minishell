/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:00:59 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/05 00:50:44 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "charfunc.h"
#include "libft.h"

int	discard_input(t_input_data *idat, t_ms_data *msd)
{
	(void)msd;
	(void)idat;
	return (CONTINUE_INPUT);
}

int	reset_input(t_input_data *idat, t_ms_data *msd)
{
	(void)msd;
	ft_memdel((void **)&idat->buf);
	dllst_del(dllst_first(idat->lst));
	idat->lst = NULL;
	if (idat->qmode == NO_QUOTE)
		write(0, "\n", 1);
	return (STOP_INPUT);
}

int	end_of_transmission(t_input_data *idat, t_ms_data *msd)
{
	(void)msd;
	if (!idat->lst && idat->qmode == NO_QUOTE)
	{
		idat->buf = ft_strdup("exit\n");
		ft_putstr_fd("exit\n", 0);
		return (STOP_INPUT);
	}
	return (CONTINUE_INPUT);
}

/*like in bash, do nothing except completion stuff with tab*/
int	tab_completion(t_input_data *idat, t_ms_data *msd)
{
	(void)msd;
	(void)idat;
	return (CONTINUE_INPUT);
}

int	new_line(t_input_data *idat, t_ms_data *msd)
{
	int		curmode;
	char	*recbuf;

	curmode = idat->qmode;
	if ((idat->lst = dllst_last(idat->lst)) || idat->qmode != NO_QUOTE)
		insert_char(idat, msd);
	else
		write(0, "\n", 1);
	idat->buf = dllst_to_str(dllst_first(idat->lst));
	dllst_del(dllst_first(idat->lst));
	idat->lst = NULL;
	if ((idat->qmode = get_quote_mode(idat->qmode, idat->buf)) != NO_QUOTE)
	{
		if (!(recbuf = ms_input(msd, idat->qmode)))
		{
			idat->qmode = curmode;
			return (reset_input(idat, msd));
		}
		idat->buf = ft_stradd(&idat->buf, recbuf, ft_strlen(recbuf));
		free(ft_heap_collector(recbuf, FT_COLLEC_GET));
	}
	return (STOP_INPUT);
}
