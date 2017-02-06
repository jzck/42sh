/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_do_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:46:40 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/06 22:54:19 by jhalford         ###   ########.fr       */
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

	if (redir->n > 9)
		bad_fd(redir->n);
	if (redir->type & TK_GREAT)
		redirect_great(redir, &fdold, &fdnew);
	else if (redir->type & TK_GREAT)
		redirect_dgreat(redir, &fdold, &fdnew);
	else if (redir->type & TK_LESS)
		redirect_less(redir, &fdold, &fdnew);
	else if (redir->type & TK_GREATAND)
	{
		if (redirect_greatand(redir, &fdold, &fdnew))
			return (0);
	}
	else if (redir->type & TK_LESSAND)
	{
		if (redirect_lessand(redir, &fdold, &fdnew))
			return (0);
	}
	else
		exit(42);
	DG("gonna redirect dup2(%i,%i)", fdold, fdnew);
	if (fd_is_valid(fdnew))
	{
		if (fd_is_valid(fdold))
		{
			dup2(fdold, fdnew);
			close(fdold);
		}
		else
			bad_fd(fdold);
	}
	else
	{
		DG("[%i] is not a valid fd", fdnew);
		if (fdnew <= 2)
			close(fdnew);
		else
			bad_fd(fdnew);
	}
	return (0);
}
