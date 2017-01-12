/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:49:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/11 17:24:55 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_word(t_btree **ast, t_list **start, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	(void)start;
	token = (*lst)->content;
	node = (*ast)->item;
	node->type = TK_COMMAND;
	node->data.sstr = ft_sstradd(node->data.sstr, token->data);
	ft_parse(ast, &(*lst)->next);
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	return (0);
}
