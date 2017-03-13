/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:39:05 by ariard            #+#    #+#             */
/*   Updated: 2017/03/13 15:56:25 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			isdir_sep(t_btree **ast, t_list **list)
{
	t_token		*token;
	t_astnode	*node;

	token = (*list)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if ((node->type == CMD || node->type == TK_IO_NUMBER
			|| node->type == TK_WHILE || node->type == TK_IF
			|| node->type == TK_FOR || node->type == SUBSHELL
			|| node->type == TK_CASE || node->type == TK_RBRACE
			|| node->type == TK_UNTIL)
			&& (token->type == TK_LESS || token->type == TK_GREAT
			|| token->type == TK_GREATAND || token->type == TK_LESSAND
			|| token->type == TK_DLESS || token->type == TK_DGREAT))
			return (1);
	}
	if (!*ast)
	{
		if (token->type == TK_LESS || token->type == TK_GREAT
			|| token->type == TK_GREATAND || token->type == TK_LESSAND
			|| token->type == TK_DLESS || token->type == TK_DGREAT)
			return (1);
	}
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
			if (node->cache != TK_NEWLINE)
				node->type = node->cache;
			else
				node->type = CMD;
			node->cache = 0;
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
		redir = (ft_lstlast(node->data.cmd.redir))->content;
		redir->word = ft_strdup(token->data);
	}
	return (0);
}

static int	add_redir_type_number(t_btree **ast, t_list **lst)
{
	t_redir		*redir;
	t_astnode	*node;
	t_token		*token;

	DG();
	token = (*lst)->content;
	node = (*ast)->item;
	redir = (ft_lstlast(node->data.cmd.redir))->content;
	redir->type = token->type;
	if (token->type == TK_DLESS)
		ft_lsteadd(&data_singleton()->heredoc_queue, ft_lstlast(node->data.cmd.redir));
	return (0);
}

int			add_redir_type(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;
	t_redir		redir;
	t_list		*temp;

	if (!*ast)
		gen_node(ast);
	token = (*lst)->content;
	node = (*ast)->item;
	if (!(node->type == TK_IO_NUMBER))
	{
		redir.n = (token->type == TK_LESS || token->type == TK_DLESS
		|| token->type == TK_LESSAND) ? STDIN : STDOUT;
		redir.type = token->type;
		redir.heredoc_data = NULL;
		redir.word = NULL;
		temp = ft_lstnew(&redir, sizeof(redir));
		ft_lsteadd(&node->data.cmd.redir, temp);
		if (token->type == TK_DLESS)
			ft_lsteadd(&data_singleton()->heredoc_queue, temp);
	}
	else
		add_redir_type_number(ast, lst);
	if (!node->cache)
		node->cache = node->type;
	node->type = REDIR;
	return (0);
}
