/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:42:55 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/09 22:33:02 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "quotes.h"

char	*join_lines(char *raw_input)
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
