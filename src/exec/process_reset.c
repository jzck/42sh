/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_reset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:44:22 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/07 17:48:22 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	process_reset(t_process	*p)
{
	process_resetfds();
	p->av = NULL;
	p->pid = 0;
	p->redirs = NULL;
	p->attributes &= ~(PROCESS_STATE_MASK | PROCESS_TYPE_MASK);
}
