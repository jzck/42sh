/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_greatand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:49:45 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 16:24:04 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_greatand(t_btree **ast, t_list **start, t_list **lst)
{
	t_astnode	*node;
	t_token		*tok;
	char		*and;

	node = (*ast)->item;
	node->type = TK_GREATAND;
	tok = (*lst)->content;
	and = ft_strchr(tok->data, '&');
	node->u_data.redir.u_word.fd = ft_atoi(and + 1);
	node->u_data.redir.close =
		tok->data[ft_strlen(tok->data) - 1] == '-' ? 1 : 0;
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	ft_parse(&(*ast)->left, start);
	return (0);
}