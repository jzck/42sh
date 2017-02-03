/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:56:55 by ariard            #+#    #+#             */
/*   Updated: 2017/02/03 17:16:53 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		get_instruction(t_btree **ast, t_list **start, t_list **lst)
{
	t_token		*token;

	token = (*lst)->content;
	if (token->type == TK_NEWLINE)
		return (parse_newline(ast, start, lst));
	else if (token->type == TK_WHILE)
		return (parse_while(ast, start, lst));
	return (0);
}
