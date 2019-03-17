/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:00:45 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/17 10:40:43 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_DATA
# define MS_DATA

# define ENV_SIZE	256

# include "libft.h"

/*all the data of minishell*/
typedef struct		s_ms_data
{
	char			**env;					/*environment*/
	int				envc;					/*count env vars (max = 255)*/
	size_t			envsize;				/*keeps the size of env*/
	char			*path;					/*PATH string*/
	char			*input_buffer;			/*raw input*/
	t_list			*cmd_list;				/*after parsing*/
}					t_ms_data;

/*this is used to execute a command*/
typedef struct		s_ms_command
{
	void			(*ms_builtin)(t_ms_data *msd, int argc, char **argv);
	int				argc;
	char			**argv;
	char			**env;
}					t_ms_command;

enum				rs_do {MS_LOAD, MS_RESTART};

void				ms_restart(int iargc, char **iargv, char **ienv, int rs_do);
void				ms_init(t_ms_data *msd, char **env);
void				ms_input(t_ms_data *msd);
void				ms_parse(t_ms_data *msd);
void				ms_execute(t_ms_data *msd);

#endif
