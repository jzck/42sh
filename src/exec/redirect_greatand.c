/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_greatand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:12:31 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/15 17:49:18 by jhalford         ###   ########.fr       */
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
		ft_dprintf(2, "{red}%s: %s: can only be digits{eoc}\n", SHELL_NAME, redir->word);
		return (1);
	}
	fdold = ft_atoi(redir->word);
	fdnew = redir->n;
	if (fdold == fdnew)
		return (0);
	if (fdold > 9)
		return (bad_fd(fdold));
	if (fd_is_valid(fdold, O_WRONLY | O_RDWR))
		dup2_close(fdold, fdnew);
	else
		return (bad_fd(fdold));
	return (0);
}
