/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_while.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:33:53 by ariard            #+#    #+#             */
/*   Updated: 2017/03/03 16:05:12 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_while(t_btree **ast)
{
	ft_exec(&(*ast)->left);
	while (ft_strcmp(ft_getenv(data_singleton()->env, "?"), "0"))
	{
		ft_exec(&(*ast)->right);
		ft_exec(&(*ast)->left);
	}
	return (0);
}
