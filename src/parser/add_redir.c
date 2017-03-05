/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:39:05 by ariard            #+#    #+#             */
/*   Updated: 2017/03/05 18:14:00 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			isdir_sep(t_btree **ast, t_list **list)
{
	t_token		*token;

	(void)ast;
	token = (*list)->content;
	if (token->type == TK_LESS || token->type == TK_GREAT
		|| token->type == TK_GREATAND || token->type == TK_LESSAND
		|| token->type == TK_DLESS || token->type == TK_DGREAT)
		return (1);
	return (0);
}

int			isdir_word(t_btree **ast, t_list **list)
{
	t_astnode	*node;
	t_token		*token;

	token = (*list)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if (token->type == TK_WORD && node->type == REDIR)
		{
			node->type = CMD;
			return (1);
		}
	}
	return (0);
}

int			add_redir_word(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;
	t_redir		*redir;

	token = (*lst)->content;
	node = (*ast)->item;
	if (node->data.cmd.redir)
	{
		DG("add file");
		redir =	(ft_lstlast(node->data.cmd.redir))->content;
		if (redir->type == TK_DLESS)
			redir->word = NULL;
		else
			redir->word = ft_strdup(token->data);
	}
	return (0);
}

int			add_redir_type(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;
	t_redir		redir;

	if (!*ast)
		gen_node(ast);
	token = (*lst)->content;
	node = (*ast)->item;
	if (!(node->type == TK_IO_NUMBER))
	{
		redir.n = (token->type == TK_LESS || token->type == TK_DLESS
		|| token->type == TK_LESSAND) ? STDIN : STDOUT;
		ft_lsteadd(&node->data.cmd.redir, ft_lstnew(&redir, sizeof(redir)));
	}
	node->type = REDIR;
	redir.type = token->type;
	return (0);
}
