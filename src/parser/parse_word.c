/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:49:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/30 16:45:53 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_word(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	token = (*lst)->content;
	node = (*ast)->item;
	node->type = TK_COMMAND;
	node->data.sstr = ft_sstradd(node->data.sstr, token->data);
	ft_parse(list_ast, ast, &(*lst)->next);
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	return (0);
}
