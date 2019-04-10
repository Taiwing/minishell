/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:29:41 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/10 17:43:00 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "quotes.h"

void	del_token(void *content, size_t size)
{
	t_token	*tok;

	(void)size;
	tok = (t_token *)content;
	ft_memdel((void **)&(tok->str));
	ft_memdel((void **)&tok);
}

void	add_token(t_list **lst, int id, char *str)
{
	t_token	tok;

	tok.id = id;
	tok.str = str;
	ft_lst_push_back(lst, (void *)&tok, sizeof(t_token));	
}

t_list	*tokenize(char *input)
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
void	print_tokens(t_list *lst)
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

