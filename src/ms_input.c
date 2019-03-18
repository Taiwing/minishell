/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:42:19 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/18 14:58:01 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ms_data.h"
#include "dllst.h"

/*right now this function is pretty useless, but there are
  cool and easy bonuses to do here*/
static void	print_prompt(t_ms_data *msd)
{
	(void)msd;
	ft_printf("$> ");
}

static void	exec_input_control_char(t_ms_data *msd, t_dllst **lst, char c)
{
	if (c == '\003')					/* Ctrl + C */
	{
		dllst_del(dllst_first(*lst));
		*lst = NULL;
	}
	else if (c == '\004' && !*lst)		/* Ctrl + D */
	{
		msd->input_buffer = ft_strdup("exit");
		ft_putstr("exit");
	}
	else if (c == '\177' && *lst)		/* backspace */
	{
		ft_putstr("\010 \010");
		dllst_remove(lst);
	}
}

void		ms_input(t_ms_data *msd)
{
	char	c;
	t_dllst	*lst;

	c = 0;
	lst = NULL;
	print_prompt(msd);
	while (c != '\n' && c != '\003' && !(c == '\004' && !lst))
	{
		if (read(0, &c, 1) == -1)
			frexit();
		if (ft_strchr(INPUT_CONTROL_CHARS, c))
			exec_input_control_char(msd, &lst, c);
		else
		{
			write(1, &c, 1);
			dllst_insert(&lst, c);	
		}
	}
	msd->input_buffer = !msd->input_buffer ?
		dllst_to_str(dllst_first(lst)) : msd->input_buffer;
	if (msd->input_buffer && ft_strcmp(msd->input_buffer, "exit"))
		ft_printf("\ninput is: '%s'\n", msd->input_buffer);
	else
		write(1, "\n", 1);
}
