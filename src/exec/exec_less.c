/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:27:08 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 17:45:04 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_less(t_btree *ast, t_data *data)
{
	(void)ast;
	ft_putendl("exec_less");
	ft_exec(ast->left, data);
	ft_exec(ast->right, data);
	return (0);
}
