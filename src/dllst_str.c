/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllst_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:32:33 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/18 14:47:59 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dllst.h"
#include "libft.h"

size_t	dllstlen(t_dllst *lst)
{
	size_t	len;

	len = 0;
	while (lst)
	{
		++len;
		lst = lst->next;
	}
	return (len);
}

char	*dllst_to_str(t_dllst *lst)
{
	char	*str;
	size_t	size;
	size_t	i;

	if (!(size = dllstlen(lst)) || !(str = ft_strnew(size)))
		return (NULL);
	i = 0;
	while (lst)
	{
		str[i++] = lst->c;
		lst = lst->next;
	}
	return (str);
}

t_dllst	*str_to_dllst(char *str)
{
	t_dllst	*lst;

	lst = NULL;
	while (str && *str)
	{
		if (!dllst_insert(&lst, *str++))
		{
			dllst_del(dllst_first(lst));
			return (NULL);
		}
	}
	return (dllst_first(lst));
}
