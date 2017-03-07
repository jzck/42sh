/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_until.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:42:20 by ariard            #+#    #+#             */
/*   Updated: 2017/03/04 18:16:38 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_until(t_btree **ast)
{
	ft_exec(&(*ast)->left);
	while (ft_strcmp(ft_getenv(data_singleton()->env, "?"), "1") == 0)
	{
		DG("before right");
		ft_exec(&(*ast)->right);
		DG("before left");
		ft_exec(&(*ast)->left);
	}
	return (0);
}
