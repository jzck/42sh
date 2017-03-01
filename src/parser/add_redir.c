/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:39:05 by ariard            #+#    #+#             */
/*   Updated: 2017/03/01 17:59:17 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			isdir_sep(t_btree **ast, t_list **list)
{
	t_astnode	*node;
	t_token		*token;

	token = (*list)->content;
	if (*ast)
	{
		node = (*ast)->item;	
		if ((node->type == TK_WORD || node->type == REDIR) 
			&& (token->type == TK_LESS || token->type == TK_GREAT 
			|| token->type == TK_GREATAND || token->type == TK_LESSAND
			|| token->type == TK_DLESS || token->type == TK_DGREAT))
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
			return (1);
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
			redir->word.word = NULL;
		else if (ft_stris((char *)token->data, &ft_isdigit))
			redir->word.fd = ft_atoi(token->data);	
		else
			redir->word.word = token->data;
	}
	return (0);
}

int			add_redir_type(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;
	t_redir		*redir;

	DG("add redir");
	if (!*ast)
		gen_node(ast);
	token = (*lst)->content;
	node = (*ast)->item;
	node->type = REDIR;
	redir = ft_memalloc(sizeof(redir));
	redir->type = token->type;
	ft_lsteadd(&node->data.cmd.redir, ft_lstnew(redir, sizeof(redir)));
	return (0);
}
