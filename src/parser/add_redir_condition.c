/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_redir_condition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:54:18 by ariard            #+#    #+#             */
/*   Updated: 2017/03/11 15:54:52 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		isdir_sep_condition(t_btree **ast)//, t_list **lst)
{
//	t_token		*token;
	t_astnode	*node;

//	token = (*lst)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if (node->type == TK_IF || node->type == TK_CASE)
			return (1);
	}
	return (0);
}

static int		isdir_word_condition(t_btree **ast)//, t_list **lst)
{
//	t_token		*token;
	t_astnode	*node;

//	token = (*lst)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if (node->type == REDIR)
			return (1);
	}
	return (0);
}

int				isdir_condition(t_btree **ast, t_list **lst)
{
	t_token		*token;
//	t_astnode	*node;

	token = (*lst)->content;
	if (*ast)
	{
//		node = (*ast)->item;
		if ((token->type == TK_LESS || token->type == TK_GREAT
			|| token->type == TK_GREATAND || token->type == TK_LESSAND
			|| token->type == TK_DLESS || token->type == TK_DGREAT)
			&& isdir_sep_condition(&(*ast)->left) == 1)
			return (1);
		if (token->type == TK_WORD
			&& isdir_word_condition(&(*ast)->left) == 1)
			return (1);
	}
	return (0);
}

int				add_redir_condition(t_btree **ast, t_list **lst)
{
	return (add_cmd(&(*ast)->left, lst));
}
