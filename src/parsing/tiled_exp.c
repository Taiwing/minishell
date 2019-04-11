/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiled_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:43:21 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/11 15:52:46 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_data.h"
#include "t_shvar.h"

void		tilde_exp(t_ms_data *msd, char **str)
{
	char	*dir;
	char	*user;
	char	*slash;

	user = NULL;
	if (!*str || **str != '~')
		return ;
	slash = ft_strchr(*str, '/');
	if (!(*str)[1] || slash == (*str + 1))
	{
		dir = get_shvar_val("HOME", msd->env);
		dir = ft_strdup(dir ? dir : "");
	}
	else if (slash)
		user = ft_strsub(*str, 1, slash - (*str + 1));
	else
		user = ft_strsub(*str, 1, ft_strlen(*str + 1));
//	if (user)
//		dir = get_user_dir(user);	/*TODO: must return allocated "" on fail*/
	ft_memdel((void **)&user);
	dir = slash ? ft_stradd(&dir, slash, ft_strlen(slash)) : dir;
	ft_memdel((void **)str);
	*str = dir;
}
