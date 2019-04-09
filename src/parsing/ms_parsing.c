/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:48:59 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/09 22:34:40 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parsing.h"

t_list		*ms_parsing(t_ms_data *msd, char **input)
{
	(void)msd;
	*input = join_lines(*input);
	return (NULL);
}
