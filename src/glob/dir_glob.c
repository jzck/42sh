/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_glob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 12:07:16 by wescande          #+#    #+#             */
/*   Updated: 2017/01/31 18:00:16 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

int				is_directory(const char *path)
{
	struct stat path_stat;

	stat(path, &path_stat);
	return (S_ISDIR(path_stat.st_mode));
}

int				dir_research(t_glob *gl, char *p, const char *pat)
{
	DIR				*dir;
	struct dirent	*in;
	char			*path_tmp;
	int				ret;

	ret = 0;
	if ((ft_strlen(p) <= 1 || p[ft_strlen(p) - 1] != '.')
			&& is_directory(p) && (dir = opendir(p)))
		while ((in = readdir(dir)))
		{
			if (ft_strcmp(in->d_name, ".") && ft_strcmp(in->d_name, ".."))
			{
				if (*p == '/' && !*(p + 1))
					path_tmp = ft_strjoin(p, in->d_name);
				else
					path_tmp = ft_strjoinf(ft_strjoin(p, "/"), in->d_name, 1);
				gl->pat = pat;
				if (match_pattern(gl, in->d_name, path_tmp) && ++ret)
					ft_ld_pushfront(&gl->match, ft_strdup(path_tmp + 2 *
								(path_tmp[0] == '.' && path_tmp[1] == '/')));
				ft_strdel(&path_tmp);
			}
		}
	return (ret);
}

int				dir_research_recursive(t_glob *gl, char *p, const char *pat)
{
	DIR				*dir;
	struct dirent	*in;
	char			*path_tmp;
	int				ret;

	ret = 0;
	if ((ft_strlen(p) <= 1 || p[ft_strlen(p) - 1] != '.')
			&& is_directory(p) && (dir = opendir(p)))
		while ((in = readdir(dir)))
		{
			if (ft_strcmp(in->d_name, ".") && ft_strcmp(in->d_name, ".."))
			{
				if (*p == '/' && !*(p + 1))
					path_tmp = ft_strjoin(p, in->d_name);
				else
					path_tmp = ft_strjoinf(ft_strjoin(p, "/"), in->d_name, 1);
				dir_research_recursive(gl, path_tmp, pat);
				gl->pat = pat;
				if (match_pattern(gl, in->d_name, path_tmp) && ++ret)
					ft_ld_pushfront(&gl->match, ft_strdup(path_tmp + 2 *
								(path_tmp[0] == '.' && path_tmp[1] == '/')));
				ft_strdel(&path_tmp);
			}
		}
	return (ret);
}
