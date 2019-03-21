/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:00:59 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/21 18:32:37 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "charfunc.h"

int	discard_input(char *c, int rd, t_dllst **lst, t_ms_data *msd)
{
	(void)c;
	(void)rd;
	(void)lst;
	(void)msd;
	return (CONTINUE_INPUT);
}

int	reset_input(char *c, int rd, t_dllst **lst, t_ms_data *msd)
{
	(void)c;
	(void)rd;
	(void)msd;
	dllst_del(dllst_first(*lst));
	*lst = NULL;
	return (STOP_INPUT);
}

int	end_of_transmission(char *c, int rd, t_dllst **lst, t_ms_data *msd)
{
	(void)c;
	(void)rd;
	if (!*lst)
	{
		msd->input_buffer = ft_strdup("exit");
		ft_putstr_fd("exit", 0);
		return (STOP_INPUT);
	}
	return (CONTINUE_INPUT);
}

int	tab_completion(char *c, int rd, t_dllst **lst, t_ms_data *msd)
{
	(void)rd;
	(void)msd;
	write(0, " ", 1);
	dllst_insert_forwd(lst, *c);
	return (CONTINUE_INPUT);
}

int	new_line(char *c, int rd, t_dllst **lst, t_ms_data *msd)
{
	(void)c;
	(void)rd;
	(void)lst;
	(void)msd;
	return (STOP_INPUT);
}
