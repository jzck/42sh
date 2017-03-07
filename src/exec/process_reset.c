/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_reset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:44:22 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/07 14:36:21 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_reset(t_process	*p)
{
//	p->av = NULL;
//	p->path = NULL;
//	p->execf = NULL;
	p->pid = 0;
	/* p->fdin = STDIN; */
	/* p->fdout = STDOUT; */
	p->to_close = 0;
	p->redirs = NULL;
	p->status = -1;
	p->attrs = 0;
//	p->condition = NULL;
//	p->content = NULL;
}
