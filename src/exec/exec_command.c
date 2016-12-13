/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:28:14 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 12:35:12 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_command(t_btree **ast)
{
	t_astnode	*node;

	node = (*ast)->item;
	ft_strappend(&data->jobc.process.command, ft_sstrcat(node->data.sstr));
	DG("gonna exec_command '%s'", data->joc.process.command);
	ft_cmd_process(node->data.sstr);
	btree_delone(ast, &ast_free);
	return (0);
}
