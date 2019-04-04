/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:00:45 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/04 22:00:06 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_DATA
# define MS_DATA

/*all the data of minishell*/
typedef struct		s_ms_data
{
	char			**env;					/*environment*/
	int				envc;					/*count env vars (max = 255)*/
}					t_ms_data;

void				ms_init(t_ms_data *msd, char **env);

#endif
