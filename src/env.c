/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:50:06 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/16 20:50:31 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_shvar.h"

char	**load_env(t_list *lst)
{
	int		i;
	int		size;
	char	**env;
	t_shvar	*svar;

	if (!(size = ft_lst_size(lst)))
		return (NULL);
	env = ft_secmalloc((size + 1) * sizeof(char *));
	i = -1;
	while (++i < size)
	{
		svar = (t_shvar *)lst->content;
		env[i] = !(svar->name && svar->value) ? ft_strjoin(svar->name, "=") :
			ft_strnew(ft_strlen(svar->name) + ft_strlen(svar->value) + 1);
		if (svar->value)
		{
			ft_strcat(env[i], svar->name);
			ft_strcat(env[i], "=");
			ft_strcat(env[i], svar->value);
		}
		lst = lst->next;
	}
	env[i] = NULL;
	return (env);
}
