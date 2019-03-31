/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:42:19 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/31 00:16:09 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "charfunc.h"

/*right now this function is pretty useless, but there are
  cool and easy bonuses to do here*/
static void	print_prompt(t_ms_data *msd)
{
	(void)msd;
	ft_dprintf(0, "$> ");
}

static int	ms_getchar(char c[8], int *rd)
{
	int	i;
	
	if ((*rd = read(0, c, 8)) == -1)
		ft_exit("read_error", EXIT_FAILURE);
	if (*rd == 1 && (c[0] > 31 || ft_strchr(INPUT_CONTROL_CHARS, c[0])))
		return (c[0]);
	else if (*rd > 1)
	{
		i = -1;
		while (g_multibyte_chars[++i])
		{
			if (!ft_strcmp(g_multibyte_chars[i], c))
				return (i + 11);
		}	
	}
	return (0);
}

void		ms_input(t_ms_data *msd)
{
	int		rd;
	char	c[8];
	t_dllst	*lst;
	int		bol;

	bol = 1;
	lst = NULL;
	print_prompt(msd);
	while (g_charfunc[ms_getchar(c, &rd)](c, &bol, &lst, msd))
		ft_bzero(c, 8);
	msd->input_buffer = !msd->input_buffer ?
		dllst_to_str(dllst_first(lst)) : msd->input_buffer;
	dllst_del(dllst_first(lst));
	if (msd->input_buffer && ft_strcmp(msd->input_buffer, "exit"))
		ft_dprintf(0, "\ninput is: '%s'\n", msd->input_buffer);
	else
		write(0, "\n", 1);
}
