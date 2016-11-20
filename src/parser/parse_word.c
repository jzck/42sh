/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:49:45 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 17:48:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_word(t_btree **ast, t_list **start, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	(void)start;
	token = (*lst)->content;
	node = (*ast)->item;
	node->type = TK_COMMAND;
	ft_printf("adding '%s' to sstr\n", token->data);
	node->u_data.sstr = ft_sstradd(node->u_data.sstr, token->data);
	/* ft_printf("added '%s'\n", node->u_data.sstr[0]); */
	ft_sstrprint(node->u_data.sstr, ',');
	ft_putchar('\n');
	ft_parse(ast, &(*lst)->next);
	ft_lstdelone(lst, &token_free);
	return (0);
}
