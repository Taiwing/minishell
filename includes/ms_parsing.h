/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:50:31 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/09 22:45:51 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_PARSING_H
# define MS_PARSING_H

# include "ms_data.h"

enum	e_tokenid {T_WORD, T_SEPARATOR};

typedef struct	s_token
{
	int			id;
	char		*str;
}				t_token;

char	*join_lines(char *raw_input);
t_list	*ms_parsing(t_ms_data *msd, char **input);

#endif
