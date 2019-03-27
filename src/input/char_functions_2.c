/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:01:02 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/27 17:20:41 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "charfunc.h"

int	last_cmd(char *c, int *bol, t_dllst **lst, t_ms_data *msd)
{
	(void)c;
	(void)bol;
	(void)lst;
	(void)msd;
	return (CONTINUE_INPUT);
}

int	next_cmd(char *c, int *bol, t_dllst **lst, t_ms_data *msd)
{
	(void)c;
	(void)bol;
	(void)lst;
	(void)msd;
	return (CONTINUE_INPUT);
}

/*TODO: modify this so that it can move back at the first position on the line*/
int	move_left(char *c, int *bol, t_dllst **lst, t_ms_data *msd)
{
	(void)msd;
	if (*lst && !*bol)
	{
		if ((*lst)->prev)
			*lst = (*lst)->prev;
		else
			*bol = 1;
		write(0, c, 3);
	}
	return (CONTINUE_INPUT);
}

int	move_right(char *c, int *bol, t_dllst **lst, t_ms_data *msd)
{
	(void)msd;
	if (*lst)
	{
		if (!*bol)
		{
			if (!(*lst)->next)
				return (CONTINUE_INPUT);
			else
				*lst = (*lst)->next;
		}
		*bol = 0;
		write(0, c, 3);
	}
	return (CONTINUE_INPUT);
}

/*TODO: implement this shit (must keep track of the cursor somehow)*/
int	move_beg(char *c, int *bol, t_dllst **lst, t_ms_data *msd)
{
	(void)c;
	(void)bol;
	(void)lst;
	(void)msd;
	return (CONTINUE_INPUT);
}
