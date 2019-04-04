/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:00:45 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/04 13:46:15 by yforeau          ###   ########.fr       */
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
	char			**cmd;					/*after parsing*/
}					t_ms_data;

void				ms_init(t_ms_data *msd, char **env);
void				ms_input(t_ms_data *msd);

#endif
