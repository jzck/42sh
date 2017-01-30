/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_separator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:21:51 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/30 17:11:05 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_separator(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst)
{
	t_token		*token;
	t_astnode	*node;

	DG("parsing separator");
	token = (*lst)->content;
	node = (*ast)->item;
	node->type = token->type;
	ft_parse(list_ast, &(*ast)->right, &(*lst)->next);
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	ft_parse(list_ast, &(*ast)->left, start);
	return (0);
}
