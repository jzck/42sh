/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_do_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:46:40 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/03 14:10:01 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_do_redirection(t_redir *redir)
{
	int		fdin;
	int		fdout;

	if (redir->type & TK_GREAT)
	{
		fdin = redir->n;
		fdout = open(redir->word.word, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		DG("opened [%s] in fd[%i]", redir->word.word, fdout);
	}
	else if (redir->type & TK_DGREAT)
	{
		fdin = redir->n;
		fdout = open(redir->word.word, O_WRONLY | O_APPEND | O_CREAT, 0644);
	}
	else if (redir->type & TK_LESS)
	{
		fdin = open(redir->word.word, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		fdout = redir->n;
	}
	else if (redir->type & (TK_LESSAND | TK_GREATAND))
	{
		if (redir->close)
		{
			DG("gonna close(%i)", redir->n);
			close(redir->n);
			return ;
		}
		else
		{
			fdin = redir->type & TK_LESSAND ? redir->word.fd : redir->n;
			fdout = redir->type & TK_LESSAND ? redir->n : redir->word.fd;
		}
	}
	else
	{
		DG("redir->type not well set !");
		return ;
	}
	DG("gonna dup2(%i,%i)", fdout, fdin);
	dup2(fdout, fdin);
	close(fdout);
}
