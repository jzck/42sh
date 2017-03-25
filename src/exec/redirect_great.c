/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_great.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:03:53 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/25 00:57:59 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		redirect_great(t_redir *redir)
{
	int		fdold;
	int		fdnew;

	fdnew = redir->n;
	if ((fdold = open(redir->word,
					O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
	{
		SH_ERR("open(): %s", strerror(errno));
		exit(1);
	}
	fd_replace(fdold, fdnew);
	return (0);
}
