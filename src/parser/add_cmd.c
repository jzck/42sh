/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:49:15 by ariard            #+#    #+#             */
/*   Updated: 2017/03/02 21:53:48 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			add_cmd(t_btree **ast, t_list **lst)
{
	t_token		*token;
	t_astnode	*node;
	t_cmd		*cmd;
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
		&& node->type != TK_PAREN_CLOSE && node->type != JOB
		&& node->type != REDIR)
		return (add_cmd(&(*ast)->right, lst));
	my_tab = NULL;
	node = (*ast)->item;
	node->type = JOB;
	if (token->type == TK_WORD || token->type == TK_ASSIGNEMENT_WORD)
	{
		
		DG("add data");
		return ; 
		if (!node->data.cmds)	
			node->data.cmds = ft_lstnew(&cmd, sizeof(t_ld));
		ft_lstlast(node->data.cmds)->content;	
		my_tab = ft_sstradd(my_tab, token->data);
		my_tab = ft_sstradd(my_tab, (char *)token->esc);
		my_tab = ft_sstradd(my_tab, (char *)token->esc2);
		
		ft_ld_pushback(&cmd->token, my_tab);
	}
	return (0);
}
