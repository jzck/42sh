/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:31:42 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/26 21:56:52 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_destroy(t_exec *exec)
{
	t_jobc	*jobc;
	int		i;

	if (!exec)
		return (0);
	jobc = &data_singleton()->jobc;
	ft_lstdel(&exec->op_stack, ft_lst_cfree);
	ft_lstdel(&jobc->first_job, job_free);
	i = -1;
	while (++i < 10)
		ft_lstdel(&exec->fd_save[i], ft_lst_cfree);
	exec_init(exec);
	return (0);
}
