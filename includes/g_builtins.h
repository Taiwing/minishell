/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_builtins.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:00:10 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/12 14:13:20 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_BUILTINS_H
# define G_BUILTINS_H

# include "ms_data.h"

# define BUILTIN_COUNT	1

typedef	int				(*t_builtin)(char **argv, t_ms_data *msd);

typedef struct			s_builtid
{
	char				*name;
	t_builtin			bi;
}						t_builtid;

extern const t_builtid	g_builtins[BUILTIN_COUNT];

int						msb_exit(char **argv, t_ms_data *msd);

#endif
