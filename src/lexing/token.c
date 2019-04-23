/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:29:41 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/23 11:24:23 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "quotes.h"

void	discard_token(t_list **alst)
{
	t_list	*next;

	next = (*alst)->next;
	del_token((*alst)->content, 0);
	free(ft_heap_collector(*alst, FT_COLLEC_GET));
	*alst = next;
}

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

void	check_alias(t_ms_data *msd)

t_list	*tokenize(t_ms_data *msd, char *input, int qmode, int alias)
{
	int		i;
	size_t	len;
	t_list	*lst;

	i = -1;
	len = 0;
	lst = NULL;
	while (input[++i])
	{
		qmode = get_qmode(qmode, input[i]);
		if (qmode || !ft_strchr(" \t\n;", input[i]))
			++len;
		else if (!qmode && len)
		{
			if (alias && (!lst || ((t_token *)lst->content)->id == T_SEPARATOR))
				check_alias(msd->alias, &lst,
					ft_strsub(input + i - len, 0, len));
			else
				add_token(&lst, T_WORD, ft_strsub(input + i - len, 0, len));
			len = 0;
		}
		if (!qmode && (input[i] == '\n' || input[i] == ';'))
			add_token(&lst, T_SEPARATOR, NULL);
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

