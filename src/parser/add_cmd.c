/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:49:15 by ariard            #+#    #+#             */
/*   Updated: 2017/03/03 17:33:28 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			add_cmd(t_btree **ast, t_list **lst)
{
	t_token		*token;
	t_astnode	*node;
	char		**my_tab;

	if ((token = (*lst)->content)->type == TK_IN || token->type == TK_PAREN_OPEN)
		return (0);
	else if (isdir_sep(ast, lst))
		return (add_redir_type(ast, lst));
	else if (!*ast)
		gen_node(ast);
	else if (isdir_word(ast, lst))
		return (add_redir_word(ast, lst));
	else if (isloop(ast, lst) == 3)
		return (add_loop_condition(ast, lst));
	else if (isloop(ast, lst))
		return (add_loop_cmd(ast, lst));
	else if (iscondition(ast, lst) == 1)
		return (add_condition_cmd(ast, lst));
	else if (iscondition(ast, lst) == 2)
		return (add_branch(ast, lst));
	else if (iscase(ast, lst) == 1)
		return (add_pattern(ast, lst));
	else if (iscase(ast, lst) == 2)
		return (add_case_cmd(ast, lst));
	else if (iscase(ast, lst) == 3)
		return (add_branch(ast, lst));
	else if (issubshell(ast, lst))
		return (add_subshell_cmd(ast, lst));
	else if (isfunc(ast, lst))
		return (add_func_cmd(ast, lst));
	else if ((node = (*ast)->item)->type != TK_DO && node->type != TK_THEN
		&& node->type != TK_PAREN_CLOSE && node->type != CMD
		&& node->type != REDIR)
		return (add_cmd(&(*ast)->right, lst));
	node = (*ast)->item;
	node->type = CMD;
	if (token->type == TK_WORD || token->type == TK_ASSIGNEMENT_WORD)
	{
		DG("add data");
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
