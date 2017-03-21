/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findexec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:37:49 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 15:11:09 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*create_path(char *path, char *name, char **spath)
{
	char			*execpath;

	if (path[ft_strlen(path)] != '/')
		execpath = ft_str3join(path, "/", name);
	else
		execpath = ft_strjoin(path, name);
	ft_sstrfree(spath);
	return (execpath);
}

char		*ft_findexec(char *path, char *file)
{
	int				i;
	DIR				*dir;
	char			**spath;
	struct dirent	*dirent;
	char			*execpath;

	i = -1;
	spath = ft_strsplit(path, ':');
	while (spath && spath[++i])
	{
		if (!(dir = opendir(spath[i])))
			continue ;
		while ((dirent = readdir(dir)))
		{
			if (ft_strcmp(dirent->d_name, file))
				continue ;
			execpath = create_path(spath[i], dirent->d_name, spath);
			closedir(dir);
			return (execpath);
		}
		closedir(dir);
	}
	ft_sstrfree(spath);
	return (NULL);
}
