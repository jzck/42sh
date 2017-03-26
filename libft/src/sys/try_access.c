/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 01:10:56 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/26 22:36:13 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		try_access(char *file, int exists, t_flag a_flag)
{
	if (exists && access(file, F_OK) != 0)
		return (ERR_SET(E_SYS_NOFILE, file) * 0 - 1);
	else if (is_directory(file))
		return (ERR_SET(E_SYS_ISDIR, file) * 0 - 1);
	else if (access(file, F_OK) == 0 && access(file, a_flag) != 0)
		return (ERR_SET(E_SYS_NOPERM, file) * 0 - 1);
	return (0);
}
