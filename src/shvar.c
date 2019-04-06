/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shvar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:39:50 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/06 20:52:46 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_shvar.h"

int		shvar_cmp(void *svar1, void *svar2)
{
	return (ft_strcmp(((t_shvar *)svar1)->name, ((t_shvar *)svar2)->name));
}

void	shvar_del(void *content, size_t content_size)
{
	t_shvar	*svar;

	(void)content_size;
	svar = (t_shvar *)content;
	if (svar->name)
		free(ft_heap_collector((void *)svar->name, FT_COLLEC_GET));
	if (svar->value)
		free(ft_heap_collector((void *)svar->value, FT_COLLEC_GET));
	free(ft_heap_collector(content, FT_COLLEC_GET));
}
