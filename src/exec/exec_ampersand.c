/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ampersand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:01:30 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/05 22:10:08 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_ampersand(t_btree **ast)
{
	if (SHELL_HAS_JOBC(data_singleton()->opts))
		data_singleton()->exec.job.attributes |= JOB_BG;
	ft_exec(&(*ast)->left);
	if (SHELL_HAS_JOBC(data_singleton()->opts))
		data_singleton()->exec.job.attributes &= ~JOB_BG;
	ft_exec(&(*ast)->right);

//	btree_delone(ast, &ast_free);
	return (0);
}
