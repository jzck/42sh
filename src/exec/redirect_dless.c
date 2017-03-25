/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_dless.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 12:36:10 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/25 01:45:49 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		redirect_dless(t_redir *redir)
{
	int		fds[2];
	char	*str;

	pipe(fds);
	str = redir->heredoc_data;
	write(fds[PIPE_WRITE], str, ft_strlen(str));
	close(fds[PIPE_WRITE]);
	dup2(fds[PIPE_READ], redir->n);
	close(fds[PIPE_READ]);
	return (0);
}
