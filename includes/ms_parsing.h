/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:50:31 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/09 16:57:54 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_PARSING_H
# define MS_PARSING_H

# include "ms_data.h"

char	*join_lines(char *raw_input);
t_list	*ms_parsing(t_ms_data *msd, char **input);

#endif
