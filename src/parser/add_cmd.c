/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:49:15 by ariard            #+#    #+#             */
/*   Updated: 2017/03/06 16:40:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
	{&issubshell, &add_subshell_cmd},
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
		if (token->type == TK_IN || token->type == TK_PAREN_CLOSE
			|| token->type == TK_DSEMI)
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
	char		**my_tab;
	int			i;

	i = 0;
	DG("add cmd");
	while (i < 14)
	{
		if (g_distrostree[i].test(ast, lst) == 1)
		{
			DG("add : %d", i);
			return (g_distrostree[i].add(ast, lst));
		}
		i++;
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
	{
		DG("add cmd default");
		if ((my_tab = (char **)malloc(sizeof(char *) * 4)))
		{
			my_tab[0] = ft_strdup(token->data);
			my_tab[1] = (char *)dup_char_esc(token->esc, token->size >> 3);
			my_tab[2] = (char *)dup_char_esc(token->esc2, token->size >> 3);
			my_tab[3] = NULL;
		}
		ft_ld_pushback(&node->data.cmd.token, my_tab);
	}
	return (0);
}
