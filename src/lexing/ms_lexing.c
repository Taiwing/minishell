/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:02:54 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/21 19:49:24 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "quotes.h"
#include "ms_lexing.h"

t_list		*ms_lexing(t_ms_data *msd, char **input)
{
	t_list	*lst;

	lst = NULL;
	(void)msd;	//TEST
//	add_to_history(*input, msd->hist, get_shvar_val("HOME", msd->env));
	*input = join_lines(*input, NO_QUOTE);
	if (*input)
	{
		lst = tokenize(*input);
		ft_memdel((void **)input);
	}
	return (lst);
}
