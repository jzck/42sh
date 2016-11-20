/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_less.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:49:45 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 16:28:31 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_dless(t_btree **ast, t_list **start, t_list **lst)
{
	t_astnode	*node;
	t_token		*tok;
	t_token		*next_tok;

	node = (*ast)->item;
	node->type = TK_DGREAT;
	if (!(*lst)->next)
		return (1);
	tok = (*lst)->content;
	next_tok = (*lst)->next->content;
	if (next_tok->type != TK_WORD)
		return (1);
	node->u_data.redir.u_word.word = ft_strdup(next_tok->data);
	/* ft_lst_delif(&start, lst->content, &ft_addrcmp, &token_free); */
	/* ft_lst_delif(&start, lst->next->content, &ft_addrcmp, &token_free); */
	/* ft_parse(&(*ast)->right, (*lst)->next->next); */
	ft_lstdelone(lst, &token_free);
	ft_lstdelone(&(*lst)->next, &token_free);
	ft_parse(&(*ast)->left, start);
	return (0);
}

