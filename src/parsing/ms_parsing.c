/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:31:22 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/10 22:46:46 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_data.h"
#include "token.h"

char	**ms_parsing(t_ms_data *msd, t_list **cmd_list)
{
	t_token	*tok;

	while (*cmd_list
		&& (tok = (t_token *)(*cmd_list)->content)->id == T_SEPARATOR)
		dicard_token(cmd_list);
}
