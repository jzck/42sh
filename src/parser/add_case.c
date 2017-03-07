/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 20:42:13 by ariard            #+#    #+#             */
/*   Updated: 2017/03/06 19:36:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		iscase(t_btree **ast, t_list **lst)
{
	t_astnode	*node;

	(void)lst;
	node = NULL;
	if (*ast)
	{
		node = (*ast)->item;
		if (node->type == TK_CASE || node->type == TK_PAREN_OPEN)
			return (1);
	}
	return (0);
}

int		iscase_pattern(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

//	DG(" add pattern");
	node = NULL;
	token = (*lst)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if ((node->type == TK_CASE || node->type == TK_PAREN_OPEN)
			&& token->type == TK_WORD && node->pattern == 0)
			return (1);
	}
	return (0);
}

int		iscase_branch(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	node = NULL;
	token = (*lst)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if ((node->type == TK_PAREN_OPEN || node->type == TK_CASE)
			&& node->nest == 0 && token->type == TK_PAREN_OPEN)
			return (1);
	}
	return (0);
}

int		add_case_cmd(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	token = (*lst)->content;
	node = (*ast)->item;
	if (token->type == TK_CASE && (node->type == TK_PAREN_OPEN
		|| node->type == TK_CASE))
		node->nest++;
	if (token->type == TK_ESAC && (node->type == TK_PAREN_OPEN
		|| node->type == TK_CASE) && node->nest > 0)
		return ((node->nest--));
	else if (token->type == TK_DSEMI && node->type == TK_PAREN_OPEN 
		&& node->nest == 0)
		return ((node->full = 1));
	else if ((token->type == TK_ESAC || token->type == TK_PAREN_CLOSE)
		&& node->nest == 0)
		return (0);
	return (add_cmd(&(*ast)->right, lst));
}	

int		add_pattern(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;
	char		**my_tab;
	
	token = (*lst)->content;
	node = (*ast)->item;
	if ((my_tab = (char **)malloc(sizeof(char *) * 4)))
	{
		my_tab[0] = ft_strdup(token->data);
		my_tab[1] = (char *)dup_char_esc(token->esc, token->size >> 3);
		my_tab[2] = (char *)dup_char_esc(token->esc2, token->size >> 3);
		my_tab[3] = NULL;
	}
	ft_ld_pushback(&node->data.cmd.wordlist, my_tab);
	node->pattern = 1;
	return (0);
}
