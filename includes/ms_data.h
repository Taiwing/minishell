/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:00:45 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/13 00:10:27 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_DATA
# define MS_DATA

# include "libft.h"

/*all the data of minishell*/
typedef struct	s_ms_data
{
	t_list		*env;			/*environment*/
	char		**path;			/*easely usable version of PATH variable*/
	int			cmd_exit;		/*exit of las command ($?)*/
	int			process_id;		/*process number ($$)*/
}				t_ms_data;

void			reset_input_mode(void);
void			set_custom_input_mode(void);
void			ms_init(t_ms_data *msd, char **env);

#endif
