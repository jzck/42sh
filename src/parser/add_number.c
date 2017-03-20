/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:28:31 by ariard            #+#    #+#             */
/*   Updated: 2017/03/20 15:39:36 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		isionumber(t_btree **ast, t_list **lst)
{
	t_token		*token;
	t_astnode	*node;

	token = (*lst)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if (node->type == CMD && token->type == TK_IO_NUMBER)
			return (1);
	}
	if (!*ast)
	{
		if (token->type == TK_IO_NUMBER)
			return (1);
	}
	return (0);
}

int		add_ionumber(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;
	t_redir		redir;

	if (!*ast)
		gen_node(ast);
	token = (*lst)->content;
	node = (*ast)->item;
	node->cache = node->type;
	node->type = token->type;
	redir_init(token->type, &redir);
	redir.n = ft_atoi(token->data);
	ft_lsteadd(&node->data.cmd.redir, ft_lstnew(&redir, sizeof(redir)));
	return (0);
}
