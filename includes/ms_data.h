/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:00:45 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/21 19:06:52 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_DATA
# define MS_DATA

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

void				ms_init(t_ms_data *msd, char **env);
void				ms_input(t_ms_data *msd);
void				ms_parse(t_ms_data *msd);
void				ms_execute(t_ms_data *msd);

#endif
