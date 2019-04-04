/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:01:04 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/04 23:15:08 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "charfunc.h"
#include "libft.h"

/*TODO: implement this shit (must keep track of the cursor somehow)*/
int	move_end(t_input_data *idat, t_ms_data *msd)
{
	(void)msd;
	(void)idat;
	return (CONTINUE_INPUT);
}

/*TODO: same as above, also we will have to reprint the line when*/
/*when deleting forward, backward and inserting in the middle of the line*/
/*this will have to be checked for*/
int	forwd_delete(t_input_data *idat, t_ms_data *msd)
{
	(void)msd;
	(void)idat;
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
