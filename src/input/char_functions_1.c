/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:00:59 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/04 21:08:45 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "charfunc.h"

int	discard_input(char *c, int *bol, t_dllst **lst, t_ms_data *msd)
{
	(void)c;
	(void)bol;
	(void)lst;
	(void)msd;
	return (CONTINUE_INPUT);
}

int	reset_input(char *c, int *bol, t_dllst **lst, t_ms_data *msd)
{
	(void)c;
	(void)bol;
	ft_memdel((void **)&msd->input_buffer);
	dllst_del(dllst_first(*lst));
	*lst = NULL;
	write(0, "\n", 1);
	return (STOP_INPUT);
}

int	end_of_transmission(char *c, int *bol, t_dllst **lst, t_ms_data *msd)
{
	(void)c;
	(void)bol;
	if (!*lst && !msd->input_buffer)
	{
		msd->input_buffer = ft_strdup("exit\n");
		ft_putstr_fd("exit\n", 0);
		return (STOP_INPUT);
	}
	return (CONTINUE_INPUT);
}

/*like in bash, do nothing except completion stuff with tab*/
int	tab_completion(char *c, int *bol, t_dllst **lst, t_ms_data *msd)
{
	(void)c;
	(void)bol;
	(void)lst;
	(void)msd;
	return (CONTINUE_INPUT);
}

int	new_line(char *c, int *bol, t_dllst **lst, t_ms_data *msd)
{
	(void)c;
	(void)bol;
	
	if ((*lst = dllst_last(*lst)))
		insert_char(c, bol, lst, msd);
	else
		write(0, "\n", 1);
	msd->input_buffer = dllst_to_str(dllst_first(*lst));
	dllst_del(dllst_first(*lst));
	*lst = NULL;
	return (STOP_INPUT);
}
