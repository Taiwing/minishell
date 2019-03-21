/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllst_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:05:04 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/21 14:06:31 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dllst.h"
#include "libft.h"

t_dllst	*dllst_first(t_dllst *lst)
{
	while (lst && lst->prev)
		lst = lst->prev;
	return (lst);
}

t_dllst	*dllst_last(t_dllst *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
