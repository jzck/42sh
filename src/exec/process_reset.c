/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_reset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:44:22 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/21 21:42:40 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	process_reset(t_process	*p)
{
	p->fdout = STDOUT;
	p->to_close = 0;
	p->av = NULL;
	p->pid = 0;
	p->redirs = NULL;
	p->attributes &= ~(PROCESS_STATE_MASK | PROCESS_TYPE_MASK);
}
