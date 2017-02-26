/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_else.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:55:07 by ariard            #+#    #+#             */
/*   Updated: 2017/02/06 19:13:05 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_else(t_btree **ast)
{
	if (data_singleton()->exec.process.if_branch == 0)
	{
		data_singleton()->exec.process.if_branch = 1;
		ft_exec(&(*ast)->right);
	}
	return (0);
}
