/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_great.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:03:53 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/05 18:07:25 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		redirect_great(t_redir* redir)
{
	int		fdold;
	int		fdnew;

	fdnew = redir->n;
	if ((fdold = open(redir->word,
					O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
	{
		DG("open errno=%i", errno);
		exit(1);
	}
	dup2(fdold, fdnew);
	return (0);
}
