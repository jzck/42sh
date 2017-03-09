/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:49:15 by ariard            #+#    #+#             */
/*   Updated: 2017/03/09 16:04:46 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_distrostree	g_distrostree[] =
{
	{&superflous_token, &add_null},
	{&isdir_sep, &add_redir_type},
	{&isdir_word, &add_redir_word},
	{&isvar, &add_var},
	{&isloop_condition, &add_loop_condition},
	{&isloop, &add_loop_cmd},
	{&iscondition_branch, &add_branch},
	{&iscondition, &add_condition_cmd},
	{&iscase_pattern, &add_pattern},
	{&iscase_branch, &add_branch},
	{&iscase, &add_case_cmd},
	{&ismath, &add_null},
	{&ismath_expr, &add_pattern},
	{&issubshell, &add_subshell_cmd},
	{&isfunc_name, &add_null},
	{&isfunc, &add_func_cmd},
	{&isionumber, &add_ionumber},
	{&isnull, &add_null},
};

int					superflous_token(t_btree **ast, t_list **lst)
{
	t_token	*token;

	(void)ast;
	if (*lst)
	{
		token = (*lst)->content;
		if (token->type == TK_IN || token->type == TK_DSEMI)
			return (1);
	}
	return (0);
}

static int			no_del_token(t_btree **ast, t_list **lst)
{
	t_astnode	*node;

	(void)lst;
	node = NULL;
	if (*ast)
	{
		node = (*ast)->item;
		if (node->type != TK_DO && node->type != TK_THEN
			&& node->type != CMD && node->type != REDIR)
			return (1);
	}
	return (0);
}

int			add_cmd(t_btree **ast, t_list **lst)
{
	t_token		*token;
	t_astnode	*node;
	int			i;

	i = -1;
	while (++i < 17)
		if (g_distrostree[i].test(ast, lst) == 1)
		{
			DG("add : %d", i);
			return (g_distrostree[i].add(ast, lst));
		}
	if (!*ast)
		gen_node(ast);
	else if (no_del_token(ast, lst))
		return (add_cmd(&(*ast)->right, lst));
	token = (*lst)->content;
	node = (*ast)->item;
	if (token->type != TK_WORD)
		node->type = token->type;
	else
		node->type = CMD;
	if (token->type == TK_WORD || token->type == TK_ASSIGNEMENT_WORD)
		ft_ld_pushback(&node->data.cmd.token,
				gen_tab(token->data, token->esc, token->esc2, 1));
	return (0);
}
