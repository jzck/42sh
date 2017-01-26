/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:29:54 by wescande          #+#    #+#             */
/*   Updated: 2017/01/24 21:16:42 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

bool			is_directory(const char *path)
{
	struct stat path_stat;

	stat(path, &path_stat);
	return (S_ISDIR(path_stat.st_mode));
}

void			dir_research(const char *pat, char *p, t_ld **match)
{
	DIR				*dir;
	struct dirent	*in;
	char			*path_tmp;

	if (ft_strlen(p) <= 1 || p[ft_strlen(p) - 1] != '.')
	{
		if (!(dir = opendir(p)))
			return ;
		while ((in = readdir(dir)))
		{
			if (ft_strcmp(in->d_name, ".") && ft_strcmp(in->d_name, ".."))
			{
				if (*p == '/' && !*(p + 1))
					path_tmp = ft_strjoin(p, in->d_name);
				else
					path_tmp = ft_strjoinf(ft_strjoin(p, "/"), in->d_name, 1);
				if (match_pattern(pat, in->d_name, path_tmp, match))
					ft_ld_pushfront(match, ft_strdup(path_tmp + 2 *
								(path_tmp[0] == '.' && path_tmp[1] == '/')));
				ft_strdel(&path_tmp);
			}
		}
	}
}

void			dir_research_recursive(const char *pat, char *p, t_ld **match)
{
	DIR				*dir;
	struct dirent	*in;
	char			*path_tmp;

	if (ft_strlen(p) <= 1 || p[ft_strlen(p) - 1] != '.')
	{
		if (!(dir = opendir(p)))
			return ;
		while ((in = readdir(dir)))
		{
			if (ft_strcmp(in->d_name, ".") && ft_strcmp(in->d_name, ".."))
			{
				if (*p == '/' && !*(p + 1))
					path_tmp = ft_strjoin(p, in->d_name);
				else
					path_tmp = ft_strjoinf(ft_strjoin(p, "/"), in->d_name, 1);
				if (is_directory(path_tmp))
					dir_research_recursive(pat, path_tmp, match);
				if (match_pattern(pat, in->d_name, path_tmp, match))
					ft_ld_pushfront(match, ft_strdup(path_tmp + 2 *
								(path_tmp[0] == '.' && path_tmp[1] == '/')));
				ft_strdel(&path_tmp);
			}
		}
	}
}
