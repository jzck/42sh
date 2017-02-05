/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 18:20:53 by ariard            #+#    #+#             */
/*   Updated: 2017/02/05 20:24:57 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			get_instruction2(t_btree **ast, t_list **start, t_list **lst)
{
	t_token		*token;

	token = (*lst)->content;
	if (token->type == TK_NEWLINE)
		return (parse_separator(ast, start, lst));
	else if (token->type == TK_WHILE)
		return (parse_while(ast, start, lst));
	return (0);
}
