/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_less.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:49:45 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 17:48:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

int		parse_word(t_btree **ast, t_list *start, t_list *lst)
{
	t_astnode	*item;
	t_token		*tok;

	(void)start;
	item = (*ast)->item;
	tok = lst->content;
	item->type = TK_COMMAND;
	item->u_data.sstr = ft_sstradd(item->u_data.sstr, tok->data);
	ft_parse(ast, lst->next);
	ft_lstdelone(&lst, &token_free);
	return (0);
}
