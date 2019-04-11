/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:45:56 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/11 22:30:23 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_data.h"
#include "quotes.h"

void		param_exp(t_ms_data *msd, char **str)
{
	char	*ptr;
	int		qmode;

	if (!*str)
		return ;
	ptr = *str;
	qmode = NO_QUOTE;
	while (*ptr)
	{
		qmode = get_qmode(qmode, *ptr);
		if (*ptr == '$' && (qmode == NO_QUOTE || qmode == DQUOTE))
			
		++ptr;
	}
}
