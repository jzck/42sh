/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:37:49 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 13:37:49 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_findexec(char **path, char *file)
{
	int				i;
	DIR				*dir;
	char			*execpath;
	struct dirent	*dirent;

	i = -1;
	while (path && path[++i])
	{
		if (!(dir = opendir(path[i])))
			continue ;
		while ((dirent = readdir(dir)))
		{
			if (ft_strcmp(dirent->d_name, file))
				continue ;
			if (path[i][ft_strlen(path[i])] != '/')
				ft_strcat(path[i], "/");
			execpath = ft_strjoin(path[i], dirent->d_name);
			return (execpath);
		}
	}
	return (NULL);
}
