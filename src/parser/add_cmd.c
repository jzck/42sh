/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:49:15 by ariard            #+#    #+#             */
/*   Updated: 2017/03/15 02:10:08 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_distrostree		g_distrostree[] =
{
	{&superflous_token, &add_null},
	{&isloop, &add_loop_cmd},
	{&iscondition_branch, &add_branch},
	{&iscondition, &add_condition_cmd},
	{&iscase, &add_case_cmd},
	{&iscase_branch, &add_branch},
	{&issubshell, &add_subshell_cmd},
	{&isfunc_name, &add_null},
	{&isfunc, &add_func_cmd},
	{&isionumber, &add_ionumber},
	{&isbang, &add_bang},
	{&isdir_sep, &add_redir_type},
	{&isdir_word, &add_redir_word},
	{&isnull, &add_null},
};

int					superflous_token(t_btree **ast, t_list **lst)
{
	t_token	*token;

	(void)ast;
	if (*lst)
	{
		token = (*lst)->content;
		if (token->type == TK_IN)
			return (1);
	}
	return (0);
}

static int			no_del_token(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	node = NULL;
	token = (*lst)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if (token->type == TK_WORD && (node->type == TK_CASE
			|| node->type == TK_PAREN_OPEN))
			return (0);
		if (node->type != TK_DO && node->type != TK_THEN
			&& node->type != CMD && node->type != REDIR
			&& node->type != TK_ASSIGNMENT_WORD && node->type != TK_FOR)
			return (1);
	}
	return (0);
}

int					add_cmd(t_btree **ast, t_list **lst)
{
	t_token		*token;
	t_astnode	*node;
	int			i;

	i = -1;
	while (++i < 14)
	{
		if (g_distrostree[i].test(ast, lst) == 1)
		{
			DG("add to %d", i);
			return (g_distrostree[i].add(ast, lst));
		}
	}
	if (!*ast)
		gen_node(ast);
	else if (no_del_token(ast, lst))
		return (add_cmd(&(*ast)->right, lst));
	token = (*lst)->content;
	node = (*ast)->item;
	if (token->type == TK_IF)
		add_if(ast, lst);
	else if (token->type != TK_WORD && token->type != TK_NAME)
		node->type = token->type;
	else if (node->type != TK_CASE && node->type != TK_PAREN_OPEN && node->type != TK_FOR)
		node->type = CMD;
	if (token->type == TK_WORD || token->type == TK_ASSIGNMENT_WORD || token->type == TK_NAME)
	{
		DG("type is %s", read_state(node->type));
		ft_ld_pushback(&node->data.cmd.token,
				gen_tab(token->data, token->esc, token->esc2, 1));
	}
	if ((token->type == TK_WORD || token->type == TK_NAME) 
		&& (node->type == TK_CASE || node->type == TK_PAREN_OPEN))
		node->pattern = 1;
	return (0);
}
