/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_if.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:07:31 by ariard            #+#    #+#             */
/*   Updated: 2017/02/20 22:31:46 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			exec_if(t_btree **ast)
{
	data_singleton()->exec.process.if_branch = 0;
	ft_exec(&(*ast)->left);
	if (data_singleton()->exec.process.status == 1)
	{
		data_singleton()->exec.process.if_branch = 1;
		ft_exec(&(*ast)->right);
	}
	return (0);
}
