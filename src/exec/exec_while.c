/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_while.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:33:53 by ariard            #+#    #+#             */
/*   Updated: 2017/03/04 17:19:18 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_while(t_btree **ast)
{
	DG("exec while condition");
	ft_exec(&(*ast)->left);
	DG("ret :[%s]", ft_getenv(data_singleton()->env, "?"));
	while (!(ft_strcmp(ft_getenv(data_singleton()->env, "?"), "0")))
	{
		DG("in the while");
		ft_exec(&(*ast)->right);
		ft_exec(&(*ast)->left);
	}
	return (0);
}
