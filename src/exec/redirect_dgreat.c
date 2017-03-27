/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_dgreat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:07:37 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/27 17:09:31 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		redirect_dgreat(t_redir *redir)
{
	int		fdold;
	int		fdnew;

	fdnew = redir->n;
	fdnew = redir->n;
	if ((try_access(redir->word, 0, W_OK)))
		return (ft_perror(NULL));
	if ((fdold = open(redir->word, O_WRONLY | O_CREAT | O_APPEND, 0644)) < 0)
		exit(1);
	fd_replace(fdold, fdnew);
	return (0);
}
