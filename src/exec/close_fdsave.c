/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fdsave.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:45:23 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/07 17:54:07 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	close_fdsave(void)
{
	t_exec	*exec;

	exec = &data_singleton()->exec;
	close(exec->fd0save);
	close(exec->fd1save);
	close(exec->fd2save);
}
