/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:01:02 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/21 19:00:49 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "charfunc.h"

int	last_cmd(char *c, int rd, t_dllst **lst, t_ms_data *msd)
{
	(void)c;
	(void)rd;
	(void)lst;
	(void)msd;
	return (CONTINUE_INPUT);
}

int	next_cmd(char *c, int rd, t_dllst **lst, t_ms_data *msd)
{
	(void)c;
	(void)rd;
	(void)lst;
	(void)msd;
	return (CONTINUE_INPUT);
}

/*TODO: modify this so that it can move back at the first position on the line*/
int	move_left(char *c, int rd, t_dllst **lst, t_ms_data *msd)
{
	(void)msd;
	if (*lst && (*lst)->prev)	/*change this shit, this does not work*/
	{
		*lst = (*lst)->prev;
		write(0, c, rd);
	}
	return (CONTINUE_INPUT);
}

int	move_right(char *c, int rd, t_dllst **lst, t_ms_data *msd)
{
	(void)msd;
	if (*lst && (*lst)->next)
	{
		*lst = (*lst)->next;
		write(0, c, rd);
	}
	return (CONTINUE_INPUT);
}

/*TODO: implement this shit (must keep track of the cursor somehow)*/
int	move_beg(char *c, int rd, t_dllst **lst, t_ms_data *msd)
{
	(void)c;
	(void)rd;
	(void)lst;
	(void)msd;
	return (CONTINUE_INPUT);
}
