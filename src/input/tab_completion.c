/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_completion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:38:12 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/19 20:34:40 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab_completion.h"
#include "quotes.h"

/*static int	get_dllst_word_qmode(int *word, int qmode, t_dllst *lst)
{
	t_dllst	*ptr;

	ptr = dllst_start(lst);
	while (ptr != lst->next)
	{
		qmode = get_qmode(qmode, ptr->c);
		if (!qmode && !ft_strchr(" \t\n", ptr->c))
		{
			if (ptr->c == ';')
				*word = 0;
			else if (!ptr->next || ft_strchr(" \t\n", ptr->next->c))
				++(*word);
		}
		ptr = ptr->next;
	}
	if ((qmode & ~BSQUOTE))
		qmode &= ~BSQUOTE;
	return (qmode);
}

int		check_completion(t_input_data *idat, char **part)
{
	int		word;
	int		qmode;

	if (idat->bol || ft_strchr(" \t\n", idat->lst->c)
		|| (idat->lst->next && !ft_strchr(" \t\n", idat->lst->next->c)))	
		return (NO_COMP);
	word = idat->word;
	qmode = get_dllst_word_qmode(&word, idat->qmode, idat->lst);
}

void	complete_input(int completion, char *part,
			t_input_data *idat, t_ms_data *msd)
{
	
}*/
