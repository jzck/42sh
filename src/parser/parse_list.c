/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:34:21 by ariard            #+#    #+#             */
/*   Updated: 2017/01/30 17:22:54 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_list(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	(void)list_ast;
	token = (*lst)->content;
	node = (*ast)->item;
	node->type = TK_LIST;
	node->data.sstr = ft_sstradd(node->data.sstr, token->data);
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	return (0);
}
