/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_newline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:26:41 by ariard            #+#    #+#             */
/*   Updated: 2017/02/05 17:17:00 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_newline(t_btree **ast, t_list **start, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	token = (*lst)->content;
	node = (*ast)->item;
	node->type = TK_NEWLINE;
	ft_parse(&(*ast)->right, &(*lst)->next);
	ft_lstdelone(lst, &token_free);
	ft_parse(&(*ast)->left, start);
	return (0);
}
