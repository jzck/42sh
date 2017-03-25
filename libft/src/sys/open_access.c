/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 01:10:56 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/25 01:50:00 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				is_directory(const char *path)
{
	struct stat		path_stat;

	stat(path, &path_stat);
	return (S_ISDIR(path_stat.st_mode));
}

int		open_access(char *file, t_flag a_flag, t_flag o_flag, t_flag o_perm)
{
	int		fd;

	if (access(file, F_OK) != 0)	
		return (-ERR_SET(E_SYS_NOFILE, file));
	if (is_directory(file))
		return (-ERR_SET(E_SYS_ISDIR, file));
	if (access(file, a_flag))
		return (-ERR_SET(E_SYS_NOPERM, file));
	if ((fd = open(file, o_flag, o_perm)) < 0)
	{
		exit(1);
	}
	return (fd);
}
