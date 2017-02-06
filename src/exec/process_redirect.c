/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:04:18 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/06 16:46:06 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		process_redirect(t_process *p)
{
	t_list	*redirs;

	redirs = p->redirs;
	while (redirs)
	{
		process_do_redirection(redirs->content);
		redirs = redirs->next;
	}
	if (p->toclose != STDIN)
		close(p->toclose);
	if (p->fdin != STDIN)
	{
		dup2(p->fdin, STDIN);
		close(p->fdin);
	}
	if (p->fdout != STDOUT)
	{
		dup2(p->fdout, STDOUT);
		close(p->fdout);
	}
	return (0);
}
