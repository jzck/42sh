/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_elif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:08:53 by ariard            #+#    #+#             */
/*   Updated: 2017/02/20 22:35:47 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			exec_elif(t_btree **ast)
{
	int		test;

	(void)ast;
	test = 0;
	if (test)
	{
		ft_exec(&(*ast)->right);
	}
	//	btree_delone(ast, &ast_free);
	return (0);
}
