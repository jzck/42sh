/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_until.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:42:20 by ariard            #+#    #+#             */
/*   Updated: 2017/02/06 20:42:21 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			exec_until(t_btree **ast)
{
	ft_exec(&(*ast)->left);
	while (data_singleton()->exec.process.status == 0)
	{
		ft_exec(&(*ast)->right);
		ft_exec(&(*ast)->left);
	}
	return (0);
}
