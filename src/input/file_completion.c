/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_completion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:29:46 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/20 19:28:00 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab_completion.h"

static char	*get_path(char *part)
{
	char	*sl;
	char	*ptr;

	sl = NULL;
	ptr = part;
	while ((ptr = ft_strchr(ptr + 1, '/')))
		sl = ptr;
	if (!sl)
		return (ft_strdup("."));
	else
		return (ft_strsub(part, 0, (sl - part) + 1));
}

char		*file_completion(char *part)
{
	size_t	len;
	char	*comp;
	char	*name;
	char	*path;
	t_list	*files;

	comp = NULL;
	path = get_path(part);
	part += ft_strlen(path);
	len = ft_strlen(part);
	if (*part && *part != '/')
	{
		files = ft_ls_files(path, FT_LS_ALL);
		while (files)
		{
			if (!comp || *comp)
			{
				name = (char *)(files->content);
				comp = part_match(comp, name, part, len);
			}
			ft_lst_discard(NULL, &files);
		}
	}
	ft_memdel((void **)&path);
	return (comp);
}
