/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lessand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:49:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/03 16:44:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_lessand(t_btree **ast, t_list **start, t_list **lst)
{
	t_astnode	*node;
	t_token		*tok;
	char		*and;

	node = (*ast)->item;
	node->type = TK_LESSAND;
	tok = (*lst)->content;
	and = ft_strchr(tok->data, '&');
	node->data.redir.word.fd = ft_atoi(and + 1);
	node->data.redir.close =
		tok->data[ft_strlen(tok->data) - 1] == '-' ? 1 : 0;
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	ft_parse(&(*ast)->left, start);
	return (0);
}
