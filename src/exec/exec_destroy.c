/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 03:09:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/27 03:10:37 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_destroy(t_exec *exec)
{
	if (!exec)
		return (0);
	ft_lstdel(&exec->op_stack, ft_lst_cfree);
	return (0);
}
