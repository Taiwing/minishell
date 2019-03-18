/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_input_mode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 09:03:47 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/18 09:13:54 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <termios.h>

//TODO: check where this function can fail
void	ft_reset_input_mode(int op)
{
	static struct termios	*tattr = NULL;

	if (op == SAVE_ATTR)
	{
		tattr = (struct termios *)ft_secmalloc(sizeof(struct termios));
		tcgetattr(0, tattr);
	}
	else if (op == RESET_ATTR && tattr)
		tcsetattr(0, TCSANOW, tattr);	
}
