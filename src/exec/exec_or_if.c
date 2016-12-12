/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_or_if.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:06:17 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/12 18:04:08 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_or_if(t_btree **ast)
{
	t_data		*data;

	data = data_singleton();
	if (data->exec.aol_status == NULL
			|| (data->exec.aol_search == TK_AND_IF
				&& *data->exec.aol_status == '0')
			|| (data->exec.aol_search == TK_OR_IF
				&& *data->exec.aol_status != '0'))
	{
		ft_exec(&(*ast)->left);
		data->exec.aol_status = ft_getenv(data->env, "?");
	}
	data->exec.aol_search = TK_OR_IF;
	if (*data->exec.aol_status != '0'
			|| ((t_astnode*)(*ast)->right->item)->type != TK_COMMAND)
		ft_exec(&(*ast)->right);
	data->exec.aol_status = NULL;
	data->exec.aol_search = 0;
	btree_delone(ast, &ast_free);
	return (0);
}
