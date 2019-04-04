/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charfunc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:46:27 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/05 00:05:53 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARFUNC_H
# define CHARFUNC_H

# include "ms_input.h"

# define INPUT_CONTROL_CHARS	"\003\004\011\n"

# define CONTINUE_INPUT	1
# define STOP_INPUT		0

# define UP_ARROW		11
# define DOWN_ARROW		12
# define RIGHT_ARROW	13
# define LEFT_ARROW		14
# define HOME_KEY		15
# define END_KEY		16
# define DELETE_KEY		17

/*TODO: rd is not really necessary, it could be removed for another variable*/

extern char	* const g_multibyte_chars[8];

extern int	(* const g_charfunc[256])(t_input_data *idat, t_ms_data *msd);

void	reprint_line(t_dllst *lst);
int		get_quote_mode(int qmode, char *input);

int		discard_input(t_input_data *idat, t_ms_data *msd);
int		reset_input(t_input_data *idat, t_ms_data *msd);
int		end_of_transmission(t_input_data *idat, t_ms_data *msd);
int		tab_completion(t_input_data *idat, t_ms_data *msd);
int		new_line(t_input_data *idat, t_ms_data *msd);
int		last_cmd(t_input_data *idat, t_ms_data *msd);
int		next_cmd(t_input_data *idat, t_ms_data *msd);
int		move_right(t_input_data *idat, t_ms_data *msd);
int		move_left(t_input_data *idat, t_ms_data *msd);
int		move_beg(t_input_data *idat, t_ms_data *msd);
int		move_end(t_input_data *idat, t_ms_data *msd);
int		forwd_delete(t_input_data *idat, t_ms_data *msd);
int		insert_char(t_input_data *idat, t_ms_data *msd);
int		back_delete(t_input_data *idat, t_ms_data *msd);

#endif
