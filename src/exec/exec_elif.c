/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_elif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:08:53 by ariard            #+#    #+#             */
/*   Updated: 2017/02/06 19:26:00 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			exec_elif(t_btree **ast)
{
	int		test;

	(void)ast;
	test = 1;
	if (test && data_singleton()->script.lc == 0)
	{
		ft_exec(&(*ast)->right);
		data_singleton()->script.lc = 1;
	}
	//	btree_delone(ast, &ast_free);
	return (0);
}
