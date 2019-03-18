/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dllst.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:44:58 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/18 12:38:04 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_DLLST_H
# define MS_DLLST_H

typedef struct		s_dllst
{
	struct s_dllst	*prev;
	struct s_dllst	*next;
	char			c;
}					t_dllst;

t_dllst				*dllst_new(char c);
t_dllst				*dllst_insert(t_dllst **alst, char c);
void				dllst_remove(t_dllst **alst);

#endif
