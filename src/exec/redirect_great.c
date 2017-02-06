/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_great.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:03:53 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/06 22:42:05 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		redirect_great(t_redir* redir, int *fdold, int *fdnew)
{
	*fdnew = redir->n;
	if ((*fdold = open(redir->word.word,
					O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
	{
		DG("open errno=%i", errno);
		exit(1);
	}
	return (0);
	dup2(fdold, fdnew);
}
