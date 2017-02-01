/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_glob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 12:07:16 by wescande          #+#    #+#             */
/*   Updated: 2017/02/01 19:49:44 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

int				is_directory(const char *path)
{
	struct stat		path_stat;

	stat(path, &path_stat);
	return (S_ISDIR(path_stat.st_mode));
}

static int		dir_list_content(t_glob *gl, char **str, const char *pat,
								int recursive)
{
	int			ret;
	char		*path_tmp;

	ret = 0;
	if (ft_strcmp(str[1], ".") && ft_strcmp(str[1], ".."))
	{
		if (*str[0] == '/' && !*(str[0] + 1))
			path_tmp = ft_strjoin(str[0], str[1]);
		else
			path_tmp = ft_strjoinf(ft_strjoin(str[0], "/"), str[1], 1);
		if (recursive)
			dir_research(gl, path_tmp, pat, recursive);
		gl->pat = pat;
		if (match_pattern(gl, str[1], path_tmp) && ++ret)
			ft_ld_pushfront(&gl->match, ft_strdup(path_tmp + 2 *
						(path_tmp[0] == '.' && path_tmp[1] == '/')));
		ft_strdel(&path_tmp);
	}
	return (ret);
}

int				dir_research(t_glob *gl, char *p,
		const char *pat, int recursive)
{
	DIR				*dir;
	struct dirent	*in;
	int				ret;

	ret = 0;
	if ((ft_strlen(p) <= 1 || p[ft_strlen(p) - 1] != '.') && is_directory(p))
	{
		dir = opendir(p);
		while ((in = readdir(dir)))
			ret += dir_list_content(gl,
					(char *[2]){p, in->d_name}, pat, recursive);
		closedir(dir);
	}
	return (ret);
}
