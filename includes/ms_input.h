/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_input.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:50:15 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/05 00:31:18 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_INPUT_H
# define MS_INPUT_H

# include "ms_data.h"
# include "dllst.h"

enum			e_qmode {NO_QUOTE = 0, DQUOTE, SQUOTE, BSQUOTE};

typedef struct	s_input_data
{
	char		c[8];
	int			bol;
	int			qmode;
	t_dllst		*lst;
	char		*buf;
}				t_input_data;

char			*ms_input(t_ms_data *msd, int qmode);

#endif