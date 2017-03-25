/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_glob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 12:07:16 by wescande          #+#    #+#             */
/*   Updated: 2017/03/25 01:39:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			dir_research(gl, path, pat, (int[]){recursive, 0});
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
		char *pat, int *mode)
{
	DIR				*dir;
	struct dirent	*in;

	if (!*pat)
	{
		gl->found = 1;
		if (!mode[1])
			ft_ld_pushfront(&gl->match_tmp, ft_strjoin(p + gl->cur_dir * 2 *
						(p[0] == '.' && p[1] == '/'), "/"));
		else
			ft_ld_pushfront(&gl->match_tmp, ft_strdup(CH(gl->m_pat)[0]));
		return (0);
	}
	if ((ft_strlen(p) <= 1 || p[ft_strlen(p) - 1] != '.') && is_directory(p))
	{
		if (!(dir = opendir(p)))
			return (0);
		while ((in = readdir(dir)))
			dir_list_content(gl,
					(char *[2]){p, in->d_name}, pat, mode[0]);
		closedir(dir);
	}
	return (0);
}
