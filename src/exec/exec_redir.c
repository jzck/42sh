/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:27:51 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/03 13:58:38 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_redir(t_btree **ast)
{
	t_astnode	*node;
	t_process	*p;

	p = &data_singleton()->exec.process;
	node = (*ast)->item;
	node->data.redir.type = node->type;
	ft_lsteadd(&p->redirs, ft_lstnew(&node->data.redir,sizeof(node->data.redir)));
	ft_exec(&(*ast)->left);
	btree_delone(ast, &ast_free);
	return (0);
}
