/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dllst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:56:32 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/18 12:42:13 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_dllst.h"
#include "libft.h"

//TODO: dllst_del to delete the list and dllst_to_str to push it to a string

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
	free(*alst);
	*alst = prev ? prev : next;
}
