/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_less.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:49:45 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 16:23:48 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_dgreat(t_btree **ast, t_list *start, t_list *lst)
{
	t_astnode	*item;
	t_token		*tok;
	t_token		*next_tok;

	item = (*ast)->item;
	item->type = TK_LESS;
	if (!lst->next)
		return (1);
	tok = lst->content;
	next_tok = lst->next->content;
	if (next_tok->type != TK_WORD)
		return (1);
	item->u_data.redir.u_word.word = ft_strdup(next_tok->data);
	ft_parse(&(*ast)->left, start);
	ft_lst_delif(&start, lst->content, &ft_addrcmp, &token_free);
	ft_lst_delif(&start, lst->next->content, &ft_addrcmp, &token_free);
	ft_parse(&(*ast)->right, lst->next);
	return (0);
}

