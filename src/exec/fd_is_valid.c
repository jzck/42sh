/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:46:40 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/06 16:58:38 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		fd_is_valid(int fd, int has_flag)
{
	int		flags;

	flags = fcntl(fd, F_GETFD);
	return ((flags != -1 || errno != EBADF) && flags & has_flag);
}
