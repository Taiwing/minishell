/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:19:15 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/15 14:28:05 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_CMD_H
# define MS_CMD_H

/*this is used to execute a command*/
typedef struct		s_ms_cmd
{
	void			(*ms_builtin)(t_ms_data *msd, int argc, char **argv);
	int				argc;
	char			**argv;
	char			**env;
}					t_ms_cmd;

void				del_cmd(void *cmd_ptr, size_t size);

#endif
