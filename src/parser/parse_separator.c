/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_separator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:21:51 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/28 16:21:56 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_separator(t_btree **ast, t_list **start, t_list **lst)
{
	t_token		*token;
	t_astnode	*node;

	token = (*lst)->content;
	node = (*ast)->item;
	ft_parse(&(*ast)->right, &(*lst)->next);
	node->type = token->type;
	ft_lstdelone(lst, &token_free);
	ft_parse(&(*ast)->left, start);
	return (0);
}
