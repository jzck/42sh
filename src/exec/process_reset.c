/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_reset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:44:22 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/08 14:51:19 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_reset(t_process	*p)
{
//	p->av = NULL;
//	p->path = NULL;
//	p->execf = NULL;
	p->pid = 0;
	p->fdin = STDIN;
	p->fdout = STDOUT;
	p->to_close = 0;
	p->redirs = NULL;
	p->status = -1;
	p->attrs = 0;
}
