/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:49:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/20 21:03:20 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_word(t_btree **ast, t_list **start, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;
	char		**the_tab;

	token = (*lst)->content;
	node = (*ast)->item;
	node->type = TK_COMMAND;
	if ((the_tab = (char **)malloc(sizeof(char *) * 4)))
	{
		the_tab[0] = ft_strdup(token->data);
		the_tab[1] = (char *)dup_char_esc(token->esc, token->size >> 3);
		the_tab[2] = (char *)dup_char_esc(token->esc2, token->size >> 3);
		the_tab[3] = NULL;
	}
	ft_ld_pushback(&node->data.token, the_tab);
	ft_parse(ast, &(*lst)->next);
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	DG("parse word end");
	return (0);
}
