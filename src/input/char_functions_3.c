/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:01:04 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/27 17:51:28 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "charfunc.h"

/*TODO: implement this shit (must keep track of the cursor somehow)*/
int	move_end(char *c, int *bol, t_dllst **lst, t_ms_data *msd)
{
	(void)c;
	(void)bol;
	(void)lst;
	(void)msd;
	return (CONTINUE_INPUT);
}

/*TODO: same as above, also we will have to reprint the line when*/
/*when deleting forward, backward and inserting in the middle of the line*/
/*this will have to be checked for*/
int	forwd_delete(char *c, int *bol, t_dllst **lst, t_ms_data *msd)
{
	(void)c;
	(void)bol;
	(void)lst;
	(void)msd;
	return (CONTINUE_INPUT);
}

int	insert_char(char *c, int *bol, t_dllst **lst, t_ms_data *msd)
{
	(void)msd;
	write(0, c, 1);
	if (!*bol)
		dllst_insert_forwd(lst, *c);
	else
		dllst_insert_back(lst, *c);
	if ((*lst)->next)
		reprint_line((*lst)->next);
	*bol = 0;
	return (CONTINUE_INPUT);
}

int	back_delete(char *c, int *bol, t_dllst **lst, t_ms_data *msd)
{
	(void)c;
	(void)msd;
	if (!*bol)
	{
		if (!(*lst)->prev)
			*bol = 1;
		ft_putstr_fd("\010 \010", 0);
		dllst_remove_back(lst);
		if (*lst)
			reprint_line(*bol ? *lst : (*lst)->next);
	}
	return (CONTINUE_INPUT);
}
