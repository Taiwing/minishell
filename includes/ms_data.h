/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:00:45 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/14 09:45:09 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_DATA
# define MS_DATA

# define ENV_SIZE	256

typedef struct	s_ms_data
{
	char		**env;					/*environment*/
	int			envc;					/*count env vars (max = 255)*/
	char		*st_env[ENV_SIZE];		/*static env*/
	char		**al_env;				/*allocated env*/
	char		*path;					/*PATH string*/
	char		*input_buffer;			/*raw input*/
	char		**command;				/*after parsing*/
}				t_ms_data;

void	ms_init(t_ms_data *msd, char **env);
void	ms_input(t_ms_data *msd);
void	ms_parse(t_ms_data *msd);
void	ms_execute(t_ms_data *msd);

#endif
