/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:46:40 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/27 00:51:02 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		fd_is_valid(int fd, int has_mode)
{
	int		fd_flags;
	int		fd_modes;

	fd_modes = fcntl(fd, F_GETFL);
	fd_flags = fcntl(fd, F_GETFD);
	return ((fd_flags != -1 || errno != EBADF)
			&& (has_mode == -1 || fd_modes & has_mode));
}
