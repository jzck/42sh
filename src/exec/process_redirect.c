/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:04:18 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 14:31:15 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		process_redirect(t_process *p)
{
	if (p->fdin != STDIN)
	{
		/* DG("redirect STDIN to %i", p->fdin); */
		dup2(p->fdin, STDIN);
		close(p->fdin);
	}
	if (p->fdout != STDOUT)
	{
		/* DG("redirect STDOUT to %i", p->fdout); */
		dup2(p->fdout, STDOUT);
		close(p->fdout);
	}
	return (0);
}
