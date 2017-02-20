/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_greatand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:12:31 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/07 17:54:40 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		redirect_greatand(t_redir *redir)
{
	int		fdold;
	int		fdnew;

	DG("redir greatand");
	if (redir->close)
	{
		close(redir->n);
		return (0);
	}
	if (redir->word.fd == redir->n)
		return (0);
	if (redir->word.fd > 9)
		return (bad_fd(redir->word.fd));
	fdold = redir->word.fd;
	fdnew = redir->n;
	if (fd_is_valid(fdold))
		dup2_close(fdold, fdnew);
	else
		return (bad_fd(fdold));
	return (0);
}
