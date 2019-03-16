/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wtfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:04:19 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/16 12:25:48 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_wtfree(char **wt)
{
	char	**ptr;

	if (!wt)
		return ;
	ptr = wt;
	while (*wt)
		free(heap_collector(*wt++, HS_GET));
	free(heap_collector(*wt, HS_GET));
	free(heap_collector(ptr, HS_GET));
}
