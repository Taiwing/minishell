/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllst.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:31:06 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/19 14:03:42 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dllst.h"
#include "libft.h"

t_dllst	*dllst_new(char c)
{
	t_dllst	*new;

	if ((new = (t_dllst *)ft_secmalloc(sizeof(t_dllst))))
	{
		new->prev = NULL;
		new->next = NULL;
		new->c = c;
	}
	return (new);
}

t_dllst	*dllst_insert(t_dllst **alst, char c)
{
	t_dllst	*new;

	if (!alst || !(new = dllst_new(c)))
		return (NULL);
	if (*alst)
	{
		new->next = (*alst)->next;
		if (new->next)
			new->next->prev = new;
		new->prev = (*alst);
		(*alst)->next = new;
	}
	*alst = new;
	return (new);
}

/*
** delete current element and replace it by the preceding one
** or the next if there is no previous element
*/
void	dllst_remove(t_dllst **alst)
{
	t_dllst	*prev;
	t_dllst	*next;

	if (!alst || !*alst)
		return ;
	prev = (*alst)->prev;
	next = (*alst)->next;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	free(heap_collector(*alst, HS_GET));
	*alst = prev ? prev : next;
}

void	dllst_del(t_dllst *lst)
{
	if (!lst)
		return ;
	dllst_del(lst->next);
	free(heap_collector(lst, HS_GET));
}

t_dllst	*dllst_first(t_dllst *lst)
{
	while (lst && lst->prev)
		lst = lst->prev;
	return (lst);
}
