/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:37:49 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/06 18:05:46 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_findexec(char *path, char *file)
{
	int				i;
	DIR				*dir;
	char			*execpath;
	char			**spath;
	struct dirent	*dirent;

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
			if (spath[i][ft_strlen(spath[i])] != '/')
				execpath = ft_str3join(spath[i], "/", dirent->d_name);
			else
				execpath = ft_strjoin(spath[i], dirent->d_name);
			ft_sstrfree(spath);
			closedir(dir);
			return (execpath);
		}
		closedir(dir);
	}
	ft_sstrfree(spath);
	return (NULL);
}
