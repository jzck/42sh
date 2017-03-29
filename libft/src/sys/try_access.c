/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 01:10:56 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/27 19:46:21 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		try_access(char *file, int exists, t_flag a_flag)
{
	if (exists && access(file, F_OK) != 0)
		return (ERR_SET(E_SYS_NOFILE, file));
	else if (is_directory(file))
		return (ERR_SET(E_SYS_ISDIR, file));
	else if (access(file, F_OK) == 0 && access(file, a_flag) != 0)
		return (ERR_SET(E_SYS_NOPERM, file));
	return (0);
}
