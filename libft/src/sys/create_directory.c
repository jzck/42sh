/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 03:18:18 by ariard            #+#    #+#             */
/*   Updated: 2017/03/25 04:07:10 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*create_directory(const char *path, const char *old_pathnames)
{
	char	*new_pathnames;
	char	*newdir;
	char	*semi;

	new_pathnames = ft_strdup(old_pathnames);
	temp = new_pathnames;
	while (new_pathnames)
	{
		if ((semi = ft_strchr(new_pathnames, ":")))
			*semi = 0;
		if (!is_directory(newdir = ft_str3join(new_pathnames, "/", path)))
			ft_strdel(&newdir);
		else
			break;
		new_pathnames += new_pathnames + 1;
	}
	ft_strdel(temp);
	return (newdir);
}
