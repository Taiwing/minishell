/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_shvar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:24:44 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/16 21:18:21 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_shvar	*get_shvar(char *name, t_list *env)
{
	t_shvar	sv;
	t_list	*lst;

	sv.name = name;
	if (!(lst = ft_lst_find(env, (void *)&sv, shvar_cmp)))
		return (NULL);
	return ((t_shvar *)lst->content);
}

char	*get_shvar_val(char *name, t_list *env)
{
	t_shvar	*ptr;

	if (!(ptr = get_shvar(name, env)))
		return (NULL);
	else
		return (ptr->value);
}

void	set_shvar(const char *name, const char *value, t_list **env)
{
	t_shvar	*svar;
	t_shvar	envar;

	if (!(svar = get_shvar((char *)name, *env)))
	{
		envar.name = ft_strdup((char *)name);
		envar.value = value ? ft_strdup((char *)value) : NULL;
		envar.type = ENV_GLOBAL;
		ft_lst_sorted_insert(env, ft_lstnew((void *)&envar, sizeof(t_shvar)),
			shvar_cmp);
	}
	else
	{
		ft_memdel((void **)&svar->value);
		svar->value = value ? ft_strdup((char *)value) : NULL;
	}
}
