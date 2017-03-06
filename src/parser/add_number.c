/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:28:31 by ariard            #+#    #+#             */
/*   Updated: 2017/03/06 15:56:00 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		isionumber(t_btree **ast, t_list **lst)
{
	t_token 	*token;
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

	DG("add io_number");
	if (!*ast)
		gen_node(ast);
	token = (*lst)->content;
	node = (*ast)->item;
	node->type = token->type;
	redir.n = ft_atoi(token->data);			
	ft_lsteadd(&node->data.cmd.redir, ft_lstnew(&redir, sizeof(redir)));
	return (0);	
}
