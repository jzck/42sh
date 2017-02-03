/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:49:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/03 14:30:10 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_word(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;
	char		**my_tab;

	(void)start;
	my_tab = NULL;
	token = (*lst)->content;
	node = (*ast)->item;
	node->type = TK_COMMAND;
	my_tab = ft_sstradd(my_tab, token->data);
	my_tab = ft_sstradd(my_tab, (char *)token->esc);
	ft_ld_pushback(&node->data.token, my_tab);
	ft_parse(ast, &(*lst)->next);
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	return (0);
}
