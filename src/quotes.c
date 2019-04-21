/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:11:28 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/21 14:35:57 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quotes.h"
#include "libft.h"

int		get_qmode(int qmode, char c)
{
	if (c && (qmode & BSQUOTE))
		return (qmode & ~BSQUOTE);
	else if (c == '\\' && qmode != SQUOTE)
		return (qmode | BSQUOTE);
	else if (c == '"' && qmode != SQUOTE)
		return (qmode == DQUOTE ? NO_QUOTE : DQUOTE);
	else if (c == '\'' && qmode != DQUOTE)
		return (qmode == SQUOTE ? NO_QUOTE : SQUOTE);
	return (qmode);
}

char	*join_lines(char *str, int qmode)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n' && (qmode & BSQUOTE))
		{
			str = ft_strrm(&str, --i, 2);
			qmode &= ~BSQUOTE;
		}
		else
			qmode = get_qmode(qmode, str[i++]);
	}
	return (str);
}

/*
int		get_str_qmode(int qmode, char *str)
{
	if (!str)
		return (NO_QUOTE);
	while (*str && *str != '\n')
		qmode = get_qmode(qmode, *str++);
	if ((qmode & ~BSQUOTE))
		qmode &= ~BSQUOTE;
	return (qmode);
}
*/
