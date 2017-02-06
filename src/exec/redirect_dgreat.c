/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_dgreat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:07:37 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/06 22:27:10 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		redirect_dgreat(t_redir *redir, int *fdold, int *fdnew)
{
	*fdold = redir->n;
	if ((*fdnew = open(redir->word.word,
					O_WRONLY | O_CREAT | O_APPEND, 0644)) < 0)
	{
		DG("open errno=%i", errno);
		exit(1);
	}
	return (0);
}
