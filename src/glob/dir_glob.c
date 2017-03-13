/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_glob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 12:07:16 by wescande          #+#    #+#             */
/*   Updated: 2017/03/09 03:24:59 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				is_directory(const char *path)
{
	struct stat		path_stat;

	stat(path, &path_stat);
	return (S_ISDIR(path_stat.st_mode));
}

static void		dir_list_content(t_glob *gl, char **str, char *pat,
		int recursive)
{
	char		*path;

	if (str[1][0] != '.')
	{
		if (*str[0] == '/' && !*(str[0] + 1))
			path = ft_strjoin(str[0], str[1]);
		else
			path = ft_strjoinf(ft_strjoin(str[0], "/"), str[1], 1);
		if (recursive)
			dir_research(gl, path, pat, recursive, 0);
		gl->pat = pat;
		if (match_pattern(gl, str[1], path))
		{
			gl->found = 1;
			ft_ld_pushfront(&gl->match_tmp, ft_strdup(path + gl->cur_dir * 2 *
						(path[0] == '.' && path[1] == '/')));
		}
		gl->pat = pat;
		ft_strdel(&path);
	}
}

int				dir_research(t_glob *gl, char *p,
		char *pat, int recursive, int first)
{
	DIR				*dir;
	struct dirent	*in;

	if (!*pat)
	{
		gl->found = 1;
		if (!first)
			ft_ld_pushfront(&gl->match_tmp, ft_strjoin(p + gl->cur_dir * 2 *
						(p[0] == '.' && p[1] == '/'), "/"));
		else
			ft_ld_pushfront(&gl->match_tmp, ft_strdup(CH(gl->m_pat)[0]));
		return (0);
	}
	if ((ft_strlen(p) <= 1 || p[ft_strlen(p) - 1] != '.') && is_directory(p))
	{
		dir = opendir(p);
		while ((in = readdir(dir)))
			dir_list_content(gl,
					(char *[2]){p, in->d_name}, pat, recursive);
		closedir(dir);
	}
	return (0);
}
