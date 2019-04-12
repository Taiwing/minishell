/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_shvar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:15:11 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/12 15:58:18 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SHVAR_H
# define T_SHVAR_H

# define ENV_GLOBAL		0x01
# define ENV_LOCAL		0x02
# define ENV_VARIABLE	0x04

# include "libft.h"

typedef struct	s_shvar
{
	char		*name;
	char		*value;
	int			type;
}				t_shvar;

int				shvar_cmp(void *svar1, void *svar2);
void			shvar_del(void *content, size_t content_size);
t_shvar			*get_shvar(char *name, t_list *env);
char			*get_shvar_val(char *name, t_list *env);
char			**load_env(t_list *lst);

#endif
