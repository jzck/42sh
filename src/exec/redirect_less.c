/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_less.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:09:53 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/05 18:11:13 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		redirect_less(t_redir *redir)
{
	int		fdold;
	int		fdnew;

	fdnew = redir->n;
	if ((fdold = open(redir->word, O_RDONLY)) < 0)
	{
		ft_dprintf(2, "{red}%s: no such file or directory: %s{eoc}\n",
				SHELL_NAME, redir->word);
		exit (1);
	}
	dup2(fdold, fdnew);
	return (0);
}
