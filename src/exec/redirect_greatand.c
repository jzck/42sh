/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_greatand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:12:31 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/27 03:18:37 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		redirect_greatand(t_redir *redir)
{
	int		fdold;
	int		fdnew;

	if (ft_strcmp(redir->word, "-") == 0)
	{
		close(redir->n);
		return (0);
	}
	if (!ft_stris(redir->word, ft_isdigit))
	{
		SH_ERR("%s: can only be digits{eoc}\n", redir->word);
		return (1);
	}
	fdold = ft_atoi(redir->word);
	fdnew = redir->n;
	if (fdold > 9)
		return (bad_fd(fdold));
	if (fd_is_valid(fdold, O_WRONLY | O_RDWR))
		dup2(fdold, fdnew);
	else
		return (bad_fd(fdold));
	return (0);
}
