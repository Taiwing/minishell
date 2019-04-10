/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:33:22 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/10 19:53:13 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "libft.h"

enum			e_tokenid {T_WORD, T_SEPARATOR};

typedef struct	s_token
{
	int			id;
	char		*str;
}				t_token;

void			discard_token(t_list **alst);
void			del_token(void *content, size_t size);
void			add_token(t_list **lst, int id, char *str);
t_list			*tokenize(char *input);

//TEMP
void			print_tokens(t_list *lst);

#endif
