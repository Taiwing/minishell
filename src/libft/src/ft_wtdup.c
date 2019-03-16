/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wtdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:11:08 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/16 12:18:02 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_wtdup(char **wt)
{
	static int	size = 0;
	char		*p;
	char		**tb;

	if (!wt)
		return (NULL);
	tb = NULL;
	size = size == -1 ? 1 : size + 1;
	if (*wt && !(p = ft_strdup(*wt)))
		size = -1;
	else if (!*wt)
		p = NULL;
	if (size != -1 && !(tb = p ? ft_wtdup(++wt) :
		(char **)ft_secmalloc(size * sizeof(char *))))
		size = -1;
	if (size == -1 && p)
		free(heap_collector(p, HS_GET));
	else if (size != -1)
		tb[--size] = p;
	return (tb);
}