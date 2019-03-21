/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charfunc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:46:27 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/21 19:06:59 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARFUNC_H
# define CHARFUNC_H

# include "dllst.h"
# include "ms_data.h"

# define INPUT_CONTROL_CHARS	"\003\004\011\n"

# define CONTINUE_INPUT	1
# define STOP_INPUT		0

# define UP_ARROW		11
# define DOWN_ARROW		12
# define LEFT_ARROW		13
# define RIGHT_ARROW	14
# define HOME_KEY		15
# define END_KEY		16
# define DELETE_KEY		17

/*TODO: rd is not really necessary, it could be removed for another variable*/

extern char	* const g_multibyte_chars[8];

extern int	(* const g_charfunc[256])(char *c, int rd,
			t_dllst **lst, t_ms_data *msd);

int	discard_input(char *c, int rd, t_dllst **lst, t_ms_data *msd);
int	reset_input(char *c, int rd, t_dllst **lst, t_ms_data *msd);
int	end_of_transmission(char *c, int rd, t_dllst **lst, t_ms_data *msd);
int	tab_completion(char *c, int rd, t_dllst **lst, t_ms_data *msd);
int	new_line(char *c, int rd, t_dllst **lst, t_ms_data *msd);
int	last_cmd(char *c, int rd, t_dllst **lst, t_ms_data *msd);
int	next_cmd(char *c, int rd, t_dllst **lst, t_ms_data *msd);
int	move_right(char *c, int rd, t_dllst **lst, t_ms_data *msd);
int	move_left(char *c, int rd, t_dllst **lst, t_ms_data *msd);
int	move_beg(char *c, int rd, t_dllst **lst, t_ms_data *msd);
int	move_end(char *c, int rd, t_dllst **lst, t_ms_data *msd);
int	forwd_delete(char *c, int rd, t_dllst **lst, t_ms_data *msd);
int	insert_char(char *c, int rd, t_dllst **lst, t_ms_data *msd);
int	back_delete(char *c, int rd, t_dllst **lst, t_ms_data *msd);

#endif