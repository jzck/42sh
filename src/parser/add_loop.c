/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 22:17:14 by ariard            #+#    #+#             */
/*   Updated: 2017/03/06 19:06:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		isloop(t_btree **ast, t_list **lst)
{
	t_astnode	*node;

	(void)lst;
	node = NULL;
	if (*ast)
	{
		node = (*ast)->item;
		if ((node->type == TK_NEWLINE || node->type == TK_SEMI
			|| node->type == TK_AMP) && isloop(&(*ast)->right, lst) == 1)
			return (1);
		if ((node->type == TK_WHILE || node->type == TK_UNTIL
			|| node->type == TK_FOR) && node->full == 0)
			return (1);
	}
	return (0);
}

int		isloop_condition(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	node = NULL;
	token = (*lst)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if (node->type == TK_FOR && (token->type == TK_WORD || token->type == TK_NAME) 
			&& node->pattern == 0)
			return (1);
	}
	return (0);
}

int		add_loop_cmd(t_btree **ast, t_list **lst)
{
	t_token		*token;
	t_astnode	*node;

	token = (*lst)->content;
	node = (*ast)->item;
	DG("add loop cmd");
	if (token->type == TK_DO && node->type == TK_FOR)
		node->pattern = 1;
	if ((token->type == TK_WHILE || token->type == TK_UNTIL || token->type == TK_FOR) 
		&& (node->type == TK_WHILE || node->type == TK_UNTIL || node->type == TK_FOR))
		node->nest++;
	if (token->type == TK_DONE && (node->type == TK_WHILE
		|| node->type == TK_UNTIL || node->type == TK_FOR) && node->nest > 0)
		node->nest--;
	else if (token->type == TK_DONE && (node->type == TK_WHILE 
		|| node->type == TK_UNTIL || node->type == TK_FOR) && node->nest == 0)
		return ((node->full = 1));
	if (token->type == TK_DO && node->nest == 0)
		return (add_cmd(&(*ast)->right, lst));
	else if (!(*ast)->right && isloop(&(*ast)->left, lst) != 2)
		return (add_cmd(&(*ast)->left, lst));
	else
		return (add_cmd(&(*ast)->right, lst));
	return (0);
}

int		add_loop_sep(t_btree **ast, t_list **lst)
{
	if (!(*ast)->right)
		return (add_sep(&(*ast)->left, lst));
	else
		return (add_sep(&(*ast)->right, lst));
	return (0);
}

int		add_loop_condition(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;
	char		**my_tab;

	token = (*lst)->content;
	node = (*ast)->item;
	DG("add word");
	if ((my_tab = (char **)malloc(sizeof(char *) * 4)))
	{
		my_tab[0] = ft_strdup(token->data);
		my_tab[1] = (char *)dup_char_esc(token->esc, token->size >> 3);
		my_tab[2] = (char *)dup_char_esc(token->esc2, token->size >> 3);
		my_tab[3] = NULL;
	}	
	ft_ld_pushback(&node->data.cmd.wordlist, my_tab);
	return (0);
}
