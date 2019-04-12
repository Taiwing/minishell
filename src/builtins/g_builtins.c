/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_builtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 13:57:24 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/12 17:19:41 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_builtins.h"

const t_builtid	g_builtins[BUILTIN_COUNT] =
{
	{"echo", msb_echo},
	{"exit", msb_exit}
};