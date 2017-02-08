/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ampersand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:01:30 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/11 14:41:54 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_ampersand(t_btree **ast)
{
	if (SH_HAS_JOBC(data_singleton()->opts))
		data_singleton()->exec.job.attributes |= JOB_BG;
	ft_exec(&(*ast)->left);
	if (SH_HAS_JOBC(data_singleton()->opts))
		data_singleton()->exec.job.attributes &= ~JOB_BG;
	ft_exec(&(*ast)->right);
	btree_delone(ast, &ast_free);
	return (0);
}
