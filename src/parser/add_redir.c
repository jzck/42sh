/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:39:05 by ariard            #+#    #+#             */
/*   Updated: 2017/03/13 16:11:16 by jhalford         ###   ########.fr       */
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
			node->type = node->cache;
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
	/* t_redir		*temp; */

	token = (*lst)->content;
	node = (*ast)->item;
	if (node->data.cmd.redir)
	{
		redir = (ft_lstlast(node->data.cmd.redir))->content;
		redir->word = ft_strdup(token->data);
		/* DG("redir1 @ %p word=[%s]", redir, redir->word); */
		/* if (redir->type == TK_DLESS) */
		/* { */
		/* 	temp = ft_lstlast((data_singleton()->heredoc_queue))->content; */
		/* 	temp->word = redir->word; */
		/* } */
	}
	return (0);
}

static int	add_redir_type_number(t_btree **ast, t_list **lst)
{
	t_redir		*temp;
	t_redir		*temp_heredoc;
	t_astnode	*node;
	t_token		*token;

	token = (*lst)->content;
	node = (*ast)->item;
	temp = (ft_lstlast(node->data.cmd.redir))->content;
	temp->type = token->type;
	if (token->type == TK_DLESS)
	{
		temp_heredoc = data_singleton()->heredoc_queue->content;
		temp_heredoc->n = temp->n;
	}
	return (0);
}

int		redir_init(t_type type, t_redir *redir)
{
	redir->n = (type == TK_LESS || type == TK_DLESS
	|| type == TK_LESSAND) ? STDIN : STDOUT;
	redir->type = type;
	redir->heredoc_data = NULL;
	redir->word = NULL;
	return (0);
}

int			add_redir_type(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;
	t_redir		redir;
	t_list		*redir_lst;
	t_list		**queue;

	queue = &data_singleton()->heredoc_queue;
	if (!*ast)
		gen_node(ast);
	token = (*lst)->content;
	node = (*ast)->item;
	if (!(node->type == TK_IO_NUMBER))
	{
		redir_init(token->type, &redir);
		redir_lst = ft_lstnew(&redir, sizeof(redir));
		ft_lsteadd(&node->data.cmd.redir, redir_lst);
		/* DG("redir1 @ %p word=[%s]", redir_lst->content, ((t_redir*)redir_lst->content)->word); */
		if (token->type == TK_DLESS)
		{
			ft_lsteadd(queue, ft_lstnew(&redir_lst->content, sizeof(t_redir*)));
			/* DG("redir2 @ %p word=[%s]", *(t_redir**)(*queue)->content, (*(t_redir**)(*queue)->content)->word); */
		}
	}
	else
		add_redir_type_number(ast, lst);
	if (!node->cache)
		node->cache = node->type;
	node->type = REDIR;
	return (0);
}
