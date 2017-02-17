/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:39:05 by ariard            #+#    #+#             */
/*   Updated: 2017/02/17 17:19:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			isdir(t_btree **ast)
{
	t_astnode	*node;

	node = (*ast)->item;
	if (node->data.redir.word.word)
		return (0);
	if (node->type == TK_LESS || node->type == TK_GREAT 
		|| node->type == TK_LESSAND || node->type == TK_GREATAND 
		|| node->type == TK_DGREAT || node->type == TK_LESSGREAT 
		|| node->type == TK_CLOBBER)
		return (1);
	return (0);
}

int			add_file(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;
	
	DG("add file");
	token = (*lst)->content;
	node = (*ast)->item;
	node->data.redir.n = ft_atoi(token->data);
	node->data.redir.word.word = ft_strdup(token->data);
	return (0);
}	
