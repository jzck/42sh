/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_or_if.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:06:17 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/01 17:46:53 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_or_if(t_btree *ast, t_data *data)
{
	if (data->aol_status == NULL
			|| (data->aol_search == TK_AND_IF && *data->aol_status == '0')
			|| (data->aol_search == TK_OR_IF && *data->aol_status != '0'))
	{
		ft_exec(ast->left, data);
		data->aol_status = ft_getenv(data->env, "?");
	}
	data->aol_search = TK_OR_IF;
	if (*data->aol_status != '0'
			|| ((t_astnode*)ast->right->item)->type != TK_COMMAND)
		ft_exec(ast->right, data);
	data->aol_status = NULL;
	data->aol_search = 0;
	return (0);
}
