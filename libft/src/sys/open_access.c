/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 01:10:56 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/25 15:07:42 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		open_access(char *file, t_flag a_flag, t_flag o_flag, t_flag o_perm)
{
	int		fd;

	if (a_flag & F_OK && access(file, F_OK) != 0)
		return (-ERR_SET(E_SYS_NOFILE, file));
	if (is_directory(file))
		return (-ERR_SET(E_SYS_ISDIR, file));
	if (access(file, F_OK) == 0 && access(file, a_flag) != 0)
		return (-ERR_SET(E_SYS_NOPERM, file));
	if ((fd = open(file, o_flag, o_perm)) < 0)
		exit(1);
	return (fd);
}
