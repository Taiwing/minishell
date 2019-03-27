/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:10:47 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/27 13:04:06 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "charfunc.h"

char	* const g_multibyte_chars[8] = {
	"\033[A",
	"\033[B",
	"\033[C",
	"\033[D",
	"\033[H",
	"\033[F",
	"\033[3~",
	NULL
};

int		(* const g_charfunc[256])(char *c, int *bol,
		t_dllst **lst, t_ms_data *msd) = {
	[0] = discard_input,						/*non-printable characters*/
	['\003'] = reset_input,						/*Ctrl+C*/
	['\004'] = end_of_transmission,				/*Ctrl+D*/
	['\t'] = tab_completion,
	['\n'] = new_line,
	[UP_ARROW] = last_cmd,						/*UP AND DOWN not implemented*/
	[DOWN_ARROW] = next_cmd,					/*yet, these are history func*/
	[LEFT_ARROW] = move_left,
	[RIGHT_ARROW] = move_right,
	[HOME_KEY] = move_beg,
	[END_KEY] = move_end,
	[DELETE_KEY] = forwd_delete,
	[' ' ... '~'] = insert_char,
	['\177'] = back_delete,
};
