/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_great.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:27:51 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 17:44:57 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_great(t_btree *ast, t_data *data)
{
	(void)ast;
	ft_putendl("exec_great");
	ft_exec(ast->left, data);
	ft_exec(ast->right, data);
	return (0);
}
