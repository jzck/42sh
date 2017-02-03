/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_do_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:46:40 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/03 14:55:44 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int fd_is_valid(int fd)
{
	return (fcntl(fd, F_GETFD) != -1 || errno != EBADF);
}

void	process_do_redirection(t_redir *redir)
{
	int		fdin;
	int		fdout;

	if (redir->type & (TK_GREAT | TK_DGREAT))
	{
		fdin = redir->n;
		fdout = open(redir->word.word, O_WRONLY | O_CREAT
				| (redir->type & TK_GREAT) ? O_TRUNC : O_APPEND,
				0644);
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
		ft_dprintf(2, "{red}%s: redirection error.", SHELL_NAME);
		return ;
	}
	fd_is_valid(fdout) ? dup2(fdout, fdin) : close(fdin);
	close(fdout);
}
