/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_while.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:33:53 by ariard            #+#    #+#             */
/*   Updated: 2017/02/06 22:05:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_while(t_btree **ast)
{
	ft_exec(&(*ast)->left);
	while (data_singleton()->exec.process.status == 1)
	{
		ft_exec(&(*ast)->right);
		ft_exec(&(*ast)->left);
	}
	return (0);
}
