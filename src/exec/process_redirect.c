/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:04:18 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 17:40:35 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_itof		g_redirmap[] =
{
	{TK_LESS, redirect_less},
	{TK_GREAT, redirect_great},
	{TK_DLESS, redirect_dless},
	{TK_DGREAT, redirect_dgreat},
	{TK_LESSAND, redirect_lessand},
	{TK_GREATAND, redirect_greatand},
	{0, NULL},
};

int			process_redirect(t_process *p)
{
	t_list	*redirs;
	t_redir	*redir;
	int		i;

	redirs = p->redirs;
	if (p->to_close != STDIN)
		close(p->to_close);
	fd_replace(p->fdin, STDIN);
	fd_replace(p->fdout, STDOUT);
	while (redirs)
	{
		redir = redirs->content;
		if (redir->n > 9)
			return (bad_fd(redir->n));
		i = -1;
		while (g_redirmap[++i].id)
			if (g_redirmap[i].id == redir->type)
			{
				if ((g_redirmap[i].f)(redir))
					return (1);
				break ;
			}
		redirs = redirs->next;
	}
	return (0);
}
