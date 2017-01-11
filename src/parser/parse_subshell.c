/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:52:44 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/11 17:50:54 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_subshell(t_btree **ast, t_list **start, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	(void)start;
	token = (*lst)->content;
	node = (*ast)->item;
	node->type = TK_SUBSHELL;
	node->data.sstr = malloc(4 * sizeof(char *));
	node->data.sstr[0] = ft_strdup(data_singleton()->argv[0]);
	node->data.sstr[1] = ft_strdup("-c");
	node->data.sstr[2] = ft_strdup(token->data);
	node->data.sstr[3] = NULL;
	ft_parse(ast, &(*lst)->next);
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	return (0);
}
