/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_dless.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Updated: 2017/02/07 16:05:09 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		redirect_dless(t_redir *redir)
{
	int		fds[2];
	char	*str;

	pipe(fds);
	str = redir->word.word;
	write(fds[PIPE_WRITE], str, ft_strlen(str));
	close(fds[PIPE_WRITE]);
	dup2(fds[PIPE_READ], 0);
	close(fds[PIPE_READ]);
	return (0);
}
