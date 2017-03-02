/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_if.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:07:31 by ariard            #+#    #+#             */
/*   Updated: 2017/03/01 16:29:20 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			exec_case(t_btree **ast)
{
	t_astnode	*node;
	char		**av;

	data_singleton()->exec.process.case_branch = 0;
	node = (*ast)->item;
	av = token_to_argv(node);
	data_singleton()->exec.process.case_pattern = av[0];
	return (0);
}
