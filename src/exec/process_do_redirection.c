/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_do_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:46:40 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/06 16:51:17 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		fd_is_valid(int fd)
{
	return (fcntl(fd, F_GETFD) != -1 || errno != EBADF);
}

int		process_do_redirection(t_redir *redir)
{
	int		fdold;
	int		fdnew;

	if (redir->type & (TK_GREAT | TK_DGREAT))
	{
		fdold = redir->n;
		if ((fdnew = open(redir->word.word, O_WRONLY | O_CREAT
				| ((redir->type & TK_GREAT) ? O_TRUNC : O_APPEND),
				0644)) < 0)
		{
			DG("open errno=%i", errno);
			exit(1);
		}
	}
	else if (redir->type & TK_LESS)
	{
		fdold = redir->n;
		if ((fdnew = open(redir->word.word, O_RDONLY)) < 0)
		{
			ft_dprintf(2, "{red}%s: no such file or directory: %s{eoc}\n",
					SHELL_NAME, redir->word.word);
			exit (1);
		}
	}
	else if (redir->type & (TK_LESSAND | TK_GREATAND))
	{
		if (redir->close)
		{
			close(redir->n);
			return (0);
		}
		else
		{
			fdold = redir->type & TK_LESSAND ? redir->word.fd : redir->n;
			fdnew = redir->type & TK_LESSAND ? redir->n : redir->word.fd;
		}
	}
	else
	{
		ft_dprintf(2, "{red}%s: redirection error.{eoc}\n", SHELL_NAME);
		return (-1);
	}
	fd_is_valid(fdold) ? dup2(fdnew, fdold) : close(fdnew);
	close(fdnew);
	return (0);
}
