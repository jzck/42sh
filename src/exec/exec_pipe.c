/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 21:13:23 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/21 21:47:43 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_pipe(t_btree **ast)
{
	t_data		*data;
	t_process	*p;

	DG("exec pipe");
	data = data_singleton();
	p = &data->exec.process;
	p->pipe_count++;
	ft_exec(&(*ast)->left);
	ft_exec(&(*ast)->right);
	/* btree_delone(ast, &ast_free); */
	return (0);
}
