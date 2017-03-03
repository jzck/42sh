/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_until.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:42:20 by ariard            #+#    #+#             */
/*   Updated: 2017/03/03 16:30:13 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			exec_until(t_btree **ast)
{
	ft_exec(&(*ast)->left);
	while (ft_strcmp(ft_getenv(data_singleton()->env, "?"), "0") == 0)
	{
		ft_exec(&(*ast)->right);
		ft_exec(&(*ast)->left);
	}
	return (0);
}
