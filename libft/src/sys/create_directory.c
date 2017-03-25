/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 03:18:18 by ariard            #+#    #+#             */
/*   Updated: 2017/03/25 20:24:44 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*create_directory(const char *path, const char *old_pathnames)
{
	char	*new_pathnames;
	char	*newdir;
	char	*temp;
	char	*semi;

	if (!path || !old_pathnames)
		return (NULL);
	new_pathnames = ft_strdup(old_pathnames);
	temp = new_pathnames;
	while (new_pathnames)
	{
		if ((semi = ft_strchr(new_pathnames, ':')))
			*semi = 0;
		if (!is_directory(newdir = ft_str3join(new_pathnames, "/", path)))
			ft_strdel(&newdir);
		else
			break ;
		new_pathnames += ft_strlen(new_pathnames) + 1;
	}
	ft_strdel(&temp);
	DG("newdir %s", newdir);
	return (newdir);
}
