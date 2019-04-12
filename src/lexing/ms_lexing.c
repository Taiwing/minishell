/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:02:54 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/12 13:36:26 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "quotes.h"
#include "ms_lexing.h"

static char	*join_lines(char *raw_input)
{
	int	i;
	int	qmode;

	i = 0;
	qmode = NO_QUOTE;
	while (raw_input && raw_input[i])
	{
		if (raw_input[i] == '\n' && (qmode & BSQUOTE))
		{
			raw_input = ft_strrm(&raw_input, i - 1, 2);
			qmode &= ~BSQUOTE;
		}
		else
			qmode = get_qmode(qmode, raw_input[i++]);
	}
	return (raw_input);
}


t_list		*ms_lexing(char **input)
{
	t_list	*lst;

	lst = NULL;
	*input = join_lines(*input);
	if (*input)
	{
		lst = tokenize(*input);
		ft_memdel((void **)input);
	}
	return (lst);
}
