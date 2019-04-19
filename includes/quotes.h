/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:12:33 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/19 19:34:57 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTES_H
# define QUOTES_H

#define NO_QUOTE	0x00
#define DQUOTE		0x01
#define SQUOTE		0x02
#define BSQUOTE		0x04

int		get_qmode(int qmode, char c);
//int		get_str_qmode(int qmode, char *str);

#endif
