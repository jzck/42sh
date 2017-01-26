/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dless.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:31:40 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/26 19:53:00 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_dless(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst)
{
	t_astnode	*node;
	t_token		*tok;
	t_token		*next_tok;

	node = (*ast)->item;
	node->type = TK_DLESS;
	if (!(*lst)->next)
		return (1);
	tok = (*lst)->content;
	next_tok = (*lst)->next->content;
	if (next_tok->type != TK_WORD)
		return (1);
	node->data.redir.word.word = ft_strdup(next_tok->data);
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	ft_lst_delif(start, (*lst)->next->content, &ft_addrcmp, &token_free);
	ft_parse(list_ast, &(*ast)->left, start);
	return (0);
}
