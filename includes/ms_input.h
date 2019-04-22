/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_input.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:50:15 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/21 20:03:17 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_INPUT_H
# define MS_INPUT_H

# include "ms_data.h"
# include "t_dllst.h"

typedef struct	s_input_data
{
	char		c[8];
	int			bol;
	int			qmode;
	int			word;
	t_dllst		*lst;
	char		*buf;
	int			hi;
}				t_input_data;

char			*ms_input(t_ms_data *msd, int qmode, int word);

#endif
