/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_builtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 13:57:24 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/17 17:16:11 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_builtins.h"

const t_builtid	g_builtins[BUILTIN_COUNT] =
{
	{"cd", msb_cd},
	{"echo", msb_echo},
	{"env", msb_env},
	{"exit", msb_exit},
	{"pwd", msb_pwd}
};
