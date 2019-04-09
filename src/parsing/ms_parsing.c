/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:48:59 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/09 23:45:16 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quotes.h"
#include "ms_parsing.h"

static void		del_token(void *content, size_t size)
{
	t_token	*tok;

	(void)size;
	tok = (t_token *)content;
	ft_memdel((void **)&(tok->str));
	ft_memdel((void **)&tok);
}

static void		add_token(t_list **lst, int id, char *str)
{
	t_token	tok;

	tok.id = id;
	tok.str = str;
	ft_lst_push_back(lst, (void *)&tok, sizeof(t_token));	
}

static t_list	*tokenize(char *input)
{
	size_t	i;
	size_t	len;
	t_list	*lst;
	int		qmode;

	i = 0;
	len = 0;
	lst = NULL;
	qmode = NO_QUOTE;
	while (input[i])
	{
		qmode = get_qmode(qmode, input[i]);
		if (qmode || !ft_strchr(" \t\n;", input[i]))
			++len;
		else if (!qmode && len)
		{
			add_token(&lst, T_WORD, ft_strsub(input + i - len, 0, len));
			len = 0;
		}
		if (!qmode && (input[i] == '\n' || input[i] == ';'))
			add_token(&lst, T_SEPARATOR, NULL);
		++i;
	}
	return (lst);
}

//TEMP
static void		print_tokens(t_list *lst)
{
	t_token	*tok;

	while (lst)
	{
		tok = (t_token *)lst->content;
		ft_printf(tok->id == T_WORD ? "T_WORD: " : "T_SEPARATOR\n");
		if (tok->str)
			ft_putendl(tok->str);
		lst = lst->next;
	}
}
//TEMP

t_list			*ms_parsing(t_ms_data *msd, char **input)
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
