/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:04:18 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/15 18:06:06 by jhalford         ###   ########.fr       */
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

int		process_redirect(t_process *p)
{
	t_list	*redirs;
	t_redir	*redir;
	int		i;

	redirs = p->redirs;
	if (p->to_close != STDIN)
		close(p->to_close);
	while (redirs)
	{
		redir = redirs->content;
		/* DG("redirs content : %p", redirs->content); */
		DG("redir @ %p", redir);
		DG("redir.type [%li]", redir->type);
		DG("redir.word [%s]", redir->word);
		DG("redir.n    [%i]", redir->n);
		if (redir->n > 9)
			return (bad_fd(redir->n));
		i = 0;
		while (g_redirmap[i].id)
		{
			if (g_redirmap[i].id == redir->type)
			{
				if ((g_redirmap[i].f)(redir))
					return (1);
				break ;
			}
			i++;
		}
		redirs = redirs->next;
	}
	/* DG("redirecting [%i:%i] [%i]", p->fdin, p->fdout, p->to_close); */
	if (p->fdin != STDIN)
		dup2_close(p->fdin, STDIN);
	if (p->fdout != STDOUT)
		dup2_close(p->fdout, STDOUT);
	return (0);
}
