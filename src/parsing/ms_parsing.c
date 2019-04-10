/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:48:59 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/10 17:43:46 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "quotes.h"
#include "ms_parsing.h"

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

/*t_list		*build_cmd_list(t_list *lst)
{
	t_list	*cmd_list;
	t_list	*cmd;
	t_token	*tok;

	cmd_list = NULL;
	cmd = NULL;
	while (lst)
	{
		tok = (t_token *)lst->content;
		if (!cmd && tok->id == T_WORD)
		{
			cmd = lst;
			ft_lst_push_back(&cmd_list, NULL, 0)->content = (void *)cmd;
		}
		else if (cmd && tok->id == T_WORD)
			cmd = cmd->next;
		else if (tok->id == T_SEPARATOR)
		{
			if (cmd)
				cmd->next = NULL;
			cmd = NULL;
				
		}
		lst = lst->next;
	}
}*/

t_list		*ms_parsing(t_ms_data *msd, char **input)
{
	t_list	*lst;

	(void)msd;
	lst = NULL;
	*input = join_lines(*input);
	if (*input)
	{
		lst = tokenize(*input);
		print_tokens(lst);
		ft_lstdel(&lst, &del_token);
		//keep this commented to print raw_input
		//ft_memdel(input);
	}
	return (lst);
}
