/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:42:19 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/19 15:34:16 by yforeau          ###   ########.fr       */
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

static int	exec_input_control_char(t_ms_data *msd, t_dllst **lst, char c)
{
	if (c == '\n')
		return (1);
	if (c == '\003')					/* Ctrl + C */
	{
		dllst_del(dllst_first(*lst));
		*lst = NULL;
		return (1);
	}
	else if (c == '\004' && !*lst)		/* Ctrl + D */
	{
		msd->input_buffer = ft_strdup("exit");
		ft_putstr("exit");
		return (1);
	}
	else if (c == '\177' && *lst)		/* backspace */
	{
		if ((*lst)->c == '\t')
			ft_putstr("\10\10\10\10");
		ft_putstr("\010 \010");
		dllst_remove(lst);
	}
	return (0);
}

static void	handle_multibyte_chars(char c[8], int rd, t_dllst **lst)
{
	if (rd == 3 && c[0] == 27 && c[1] == 91)			/*ARROW KEYS*/
	{
		if (c[2] == 65)									/*UP*/
			return ;
		else if (c[2] == 66)							/*DOWN*/
			return ;
		else if (c[2] == 67 && *lst && (*lst)->next)	/*RIGHT*/
		{
			*lst = (*lst)->next;
			write(1, c, rd);
		}
		else if (c[2] == 68 && *lst && (*lst)->prev)		/*LEFT*/
		{
			*lst = (*lst)->prev;
			write(1, c, rd);
		}
		else if (c[2] == 70)	/*end*/
			return ;
		else if (c[2] == 72)	/*home*/
			return ;
	}
	else if (rd == 4 && c[0] == 27 && c[1] == 91 && c[2] == 51 && c[3] == 126)
		return ;				/*delete*/
}

void		ms_input(t_ms_data *msd)
{
	int		rd;
	char	c[8];
	t_dllst	*lst;

	lst = NULL;
	print_prompt(msd);
	while (1)
	{
		if ((rd = read(0, c, 8)) == -1)
			frexit();
		if (rd > 1)
			handle_multibyte_chars(c, rd, &lst);
		else if (ft_strchr(INPUT_CONTROL_CHARS, *c))
		{
			if (exec_input_control_char(msd, &lst, *c))
				break ;
		}
		else
		{
			write(1, c, 1);
			dllst_insert(&lst, *c);
		}
		ft_bzero(c, 8);
	}
	msd->input_buffer = !msd->input_buffer ?
		dllst_to_str(dllst_first(lst)) : msd->input_buffer;
	dllst_del(dllst_first(lst));
	if (msd->input_buffer && ft_strcmp(msd->input_buffer, "exit"))
		ft_printf("\ninput is: '%s'\n", msd->input_buffer);
	else
		write(1, "\n", 1);
}
