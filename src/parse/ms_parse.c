/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:07:45 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/31 17:05:20 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_data.h"

/*TODO: actually expand*/
static char	*expand(char *raw, int l)
{
	return (ft_strndup(raw, l));
}

static char	**build_arg_vector(char *raw)
{
	static int	size = 0;
	int			l;
	char		*p;
	char		**tb;

	if (!raw)
		return (NULL);
	++size;
	p = NULL;
	while (*raw && (*raw == 32 || (*raw > 8 && *raw < 12)))
		++raw;
	l = 0;
	while (raw[l] && !(raw[l] == 32 || (raw[l] > 8 && raw[l] < 12)))
		++l;
	if (l && (p = expand(raw, l)))
		tb = build_arg_vector(raw + l);
	else if (!l && size > 1)
		tb = ft_secmalloc(size * sizeof(char *));
	else
	{
		--size;
		return (l ? build_arg_vector(raw + l) : NULL);
	}
	tb[--size] = p;
	return (tb);
}

void		ms_parse(t_ms_data *msd)
{
	char	*cur;
	char	*next;

	if ((next = ft_strchr(msd->input_buffer, ';')))
	{
		cur = ft_strndup(msd->input_buffer, next - msd->input_buffer);
		next = ft_strdup(next + 1);
	}
	else
		cur = msd->input_buffer;
	msd->cmd = build_arg_vector(cur);
	ft_memdel((void **)&msd->input_buffer);
	if (next)
	{
		free(ft_heap_collector(cur, FT_COLLEC_GET));
		msd->input_buffer = next;
	}
}
