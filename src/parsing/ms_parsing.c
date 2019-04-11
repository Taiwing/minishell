/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:31:22 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/11 18:28:01 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "tilde_exp.h"

static int	expand(t_ms_data *msd, t_list *cmd_list)
{
	t_token	*tok;
	int		argc;

	(void)msd;
	argc = 0;
	while (cmd_list && (tok = (t_token *)cmd_list->content)->id == T_WORD)
	{
		tilde_exp(msd, &tok->str);
//		param_exp(msd, &tok->str);
//		rm_quotes(&tok->str);
		cmd_list = cmd_list->next;
		argc = tok->str ? argc + 1 : argc;
	}
	return (argc);
}

char		**ms_parsing(t_ms_data *msd, t_list **cmd_list)
{
	t_token	*tok;
	int		argc;
	char	**argv;
	
	argc = expand(msd, *cmd_list);
	argv = argc ? ft_secmalloc((argc + 1) * sizeof(char *)) : NULL;
	argc = 0;
	while (*cmd_list
			&& (tok = (t_token *)(*cmd_list)->content)->id == T_WORD)
	{
		if (tok->str)
			argv[argc++] = tok->str;
		tok->str = NULL;
		discard_token(cmd_list);
	}
	if (argc)
		argv[argc] = NULL;
	while (*cmd_list
		&& (tok = (t_token *)(*cmd_list)->content)->id == T_SEPARATOR)
		discard_token(cmd_list);
	return (argv);
}
