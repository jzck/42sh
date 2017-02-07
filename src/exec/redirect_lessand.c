/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_lessand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:11:18 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/07 12:01:56 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		redirect_lessand(t_redir *redir)
{
	int		fdold;
	int		fdnew;

	if (redir->word.fd == redir->n)
		return (0);
	if (redir->word.fd > 9)
		bad_fd(redir->word.fd);
	if (redir->close)
	{
		close(redir->n);
		return (1);
	}
	else
	{
		fdold = redir->word.fd;
		fdnew = redir->n;
	}
	if (fd_is_valid(fdold))
	{
		dup2(fdold, fdnew);
		close(fdold);
	}
	else
		bad_fd(fdold);
	return (0);
}
