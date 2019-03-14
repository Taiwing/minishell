/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:17:11 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/14 16:25:43 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ms_data.h"

void	fatal_error(t_ms_data *msd)
{
	ft_wtfree(msd->env);
	free(msd->input_buffer);
	if (msd->msc)
	{
		ft_wtfree(msd->msc->argv);
		ft_wtfree(msd->msc->env);
		free(msd->msc);
	}
	exit(FATAL_ERROR);
}
