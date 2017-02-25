/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:39:05 by ariard            #+#    #+#             */
/*   Updated: 2017/02/25 19:29:53 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			isdir(t_btree **ast, t_list **list)
{
	t_astnode	*node;
	t_token		*token;

	token = (*list)->content;
	if (ast)
	{
		DG("isdir");
		node = (*ast)->item;
		if ((node->type == TK_LESS || node->type == TK_GREAT 
			|| node->type == TK_LESSAND || node->type == TK_GREATAND 
			|| node->type == TK_DGREAT)
			&& token->type == TK_WORD)
			return (1);	
		if ((node->type == TK_LESS || node->type == TK_GREAT 
			|| node->type == TK_LESSAND || node->type == TK_GREATAND 
			|| node->type == TK_DGREAT)
			&& (token->type == TK_LESS || token->type == TK_GREAT 
			|| token->type == TK_LESSAND || token->type == TK_GREATAND 
			|| token->type == TK_DGREAT))
			return (2);
	}
	return (0);
}

int			add_file(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;
	t_redir		*redir;

	token = (*lst)->content;
	node = (*ast)->item;
	if (node->data.wordlist)
	{
		DG("add file");
		redir =	(ft_lstlast(node->data.wordlist))->content;
		redir->word.word = token->data;
	}	
	return (0);
}

int			add_redir(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;
	t_redir		*redir;

	DG("add_redir");
	token = (*lst)->content;
	node = (*ast)->item;
	redir = ft_memalloc(sizeof(redir));
	redir->type = token->type;
	ft_lsteadd(&node->data.wordlist, ft_lstnew(redir, sizeof(redir)));
	return (0);
}
