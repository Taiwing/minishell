/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:00:45 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/22 10:36:14 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_DATA
# define MS_DATA

# include "libft.h"

# define HISTMAX	2048		/*maximum number of commands in history*/

/*history structure*/
typedef struct		s_ms_history
{
	char			*cmd[HISTMAX];
	size_t			size;
}					t_ms_history;

void				load_history(t_ms_history *hist, char *home_path);
void				add_to_history(char *input,
						t_ms_history *hist, char *home_path);
void				del_history(t_ms_history *hist, size_t start, size_t len);
void				write_history(int fd, t_ms_history *hist,
						size_t start, size_t len);
void				flush_history(t_ms_history *hist,
						size_t len, char *path);

/*all the data of minishell*/
typedef struct		s_ms_data
{
	t_list			*env;			/*environment*/
	char			**path;			/*easely usable version of PATH variable*/
	int				cmd_exit;		/*exit of las command ($?)*/
	int				process_id;		/*process number ($$)*/
	t_ms_history	hist;			/*command line history*/
	size_t			cmd_c;			/*command count*/
}					t_ms_data;

void				reset_input_mode(void);
void				set_custom_input_mode(void);
void				ms_init(t_ms_data *msd, char **env);

#endif
