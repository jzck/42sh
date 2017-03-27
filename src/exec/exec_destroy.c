/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 03:09:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/27 15:56:47 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_destroy(t_exec *exec)
{
	if (!exec)
		return (1);
	ft_lstdel(&exec->op_stack, ft_lst_cfree);
	exec->attrs = 0;
	exec->fdin = STDIN;
	return (0);
}
