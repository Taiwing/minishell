/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllst.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:30:21 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/18 14:50:02 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLLST_H
# define DLLST_H

# include <stddef.h>

typedef struct		s_dllst
{
	struct s_dllst	*prev;
	struct s_dllst	*next;
	char			c;
}					t_dllst;

t_dllst				*dllst_new(char c);
t_dllst				*dllst_insert(t_dllst **alst, char c);
void				dllst_remove(t_dllst **alst);
void				dllst_del(t_dllst *lst);
t_dllst				*dllst_first(t_dllst *lst);
size_t				dllstlen(t_dllst *lst);
char				*dllst_to_str(t_dllst *lst);
t_dllst				*str_to_dllst(char *str);

#endif
