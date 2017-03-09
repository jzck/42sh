/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:39:05 by ariard            #+#    #+#             */
/*   Updated: 2017/03/09 18:29:45 by ariard           ###   ########.fr       */
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
		if ((node->type == CMD || node->type == TK_IO_NUMBER) && 
			(token->type == TK_LESS || token->type == TK_GREAT
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
	t_redir		*temp;

	token = (*lst)->content;
	node = (*ast)->item;
	if (node->data.cmd.redir)
	{
		DG("add file");
		redir =	(ft_lstlast(node->data.cmd.redir))->content;
		DG("now redir.type :%s", read_state(redir->type));		
		redir->word = ft_strdup(token->data);
		if (redir->type == TK_DLESS)
		{
			temp = ft_lstlast((data_singleton()->heredoc_queue))->content;
			temp->word = redir->word;
		}
	}
	return (0);
}

int			add_redir_type(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;
	t_redir		redir;
	t_redir		*temp;
	t_redir		*temp_heredoc;

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
		ft_lsteadd(&node->data.cmd.redir, ft_lstnew(&redir, sizeof(redir)));
		if (token->type == TK_DLESS)
			ft_lsteadd(&data_singleton()->heredoc_queue, ft_lstnew(&redir, sizeof(redir)));
	}
	else
	{
		temp = (ft_lstlast(node->data.cmd.redir))->content;
		temp->type = token->type;
		if (token->type == TK_DLESS)
		{
			temp_heredoc = data_singleton()->heredoc_queue->content;
			temp_heredoc->n = temp->n;
		}
	}
	node->type = REDIR;
	return (0);
}
