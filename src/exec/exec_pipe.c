/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 21:13:23 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/27 23:49:35 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_pipe(t_btree *ast, t_data *data)
{
	int		filedes[2];

	pipe(filedes);
	ft_printf("doing dup2\n");
	if ((dup2(filedes[1], 1)) == -1)
		return (-1);
	ft_exec(ast->left, data);
	close(filedes[PIPE_WRITE]);
	dup2(filedes[0], 0);
	ft_exec(ast->right, data);
	close(filedes[0]);
	return (0);
}
