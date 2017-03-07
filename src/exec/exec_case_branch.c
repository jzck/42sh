/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_case_branch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:33:45 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 20:34:48 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_case_branch(t_btree **ast)
{
	t_astnode	*node;
	char		**av;
	t_exec		*exec;
	int			i;

	exec = &data_singleton()->exec;
	if (EXEC_IS_CASE_BRANCH(exec->attrs))
		return (0);
	node = (*ast)->item;
	av = token_to_argv(node->data.cmd.wordlist, 1);
	i = 0;
	while (av[i])
	{
		if (ft_strcmp(av[i], ((char **)exec->case_pattern)[0]) == 0)
		{ 
			exec->attrs |= EXEC_CASE_BRANCH;
		 	ft_exec(&(*ast)->right);
			break ;
		}
		i++;
	}
	return (0);
}
