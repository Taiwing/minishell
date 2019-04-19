/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:42:19 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/19 19:27:22 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "charfunc.h"

const char	*g_inputstr[4] = {
	"$",
	"dquote",
	"squote",
	""
};

/*right now this function is pretty useless, but there are
  cool and easy bonuses to do here*/
static void	print_prompt(t_ms_data *msd, int qmode)
{
	(void)msd;
	ft_dprintf(0, "%s> ", g_inputstr[qmode]);
}

static int	ms_getchar(char c[8])
{
	int	i;
	int	rd;
	
	if ((rd = read(0, c, 8)) == -1)
		ft_exit("read_error", EXIT_FAILURE);
	if (rd == 1 && (c[0] > 31 || ft_strchr(INPUT_CONTROL_CHARS, c[0])))
		return (c[0]);
	else if (rd > 1)
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

char		*ms_input(t_ms_data *msd, int qmode, int word)
{
	t_input_data	idat;

	print_prompt(msd, qmode);
	idat.bol = 1;
	idat.lst = NULL;
	idat.buf = NULL;
	idat.word = word;
	ft_bzero(idat.c, 8);
	idat.qmode = qmode == BSQUOTE ? NO_QUOTE : qmode;
	while (g_charfunc[ms_getchar(idat.c)](&idat, msd))
		ft_bzero(idat.c, 8);
	return (idat.buf);
}
