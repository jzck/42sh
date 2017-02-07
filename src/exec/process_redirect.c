/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:04:18 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/06 22:23:33 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_redirmap	g_redirmap[] =
{
	{TK_LESS, redirect_less},
	{TK_GREAT, redirect_great},
	/* {TK_DLESS, redirect_dless}, */
	{TK_DGREAT, redirect_dgreat},
	{TK_LESSAND, redirect_lessand},
	{TK_GREATAND, redirect_greatand},
	{0, NULL},
};

int		process_redirect(t_process *p)
{
	t_list	*redirs;
	t_redir	*redir;
	int		i;

	redirs = p->redirs;
	while (redirs)
	{
		i = 0;
		redir = redirs->content;
		if (redir->n > 9)
		{
			bad_fd(redir->n);
			exit(1);
		}
		while (g_redirmap[i].type)
		{
			if (g_redirmap[i].type == redir->type)
			{
				(g_redirmap[i].f)(redir);
				break ;
			}
			i++;
		}
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
