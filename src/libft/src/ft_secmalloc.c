/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:17:19 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/16 16:14:00 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		malloc_sigint(int sig)
{
	static int	exit = 0;

	if (sig == SIGINT)
		exit = 1;
	else if (sig == CHECK_SIG && exit)
	{
		exit = 0;
		return (1);
	}
	return (0);
}

void	frexit(void)
{
	heap_collector(NULL, HS_FREE);
//	dir_heap_collector(NULL, HS_FREE);
	exit(EXIT_FAILURE);
}

void	*ft_secmalloc(size_t size)
{
	void	*ptr;
	void	(*sig_hand)(int);

	sig_hand = signal(SIGINT, (void(*)(int))malloc_sigint);
	if (!(ptr = malloc(size)))
		frexit();
	heap_collector(ptr, HS_ADD);
	signal(SIGINT, sig_hand);
	if (malloc_sigint(CHECK_SIG))
		sig_hand(SIGINT);
	return (ptr);
}
