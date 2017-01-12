/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:29:54 by wescande          #+#    #+#             */
/*   Updated: 2017/01/12 18:37:44 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

/*
 ** glob return expansion of a string.
 ** pattern searched are ~, *, ?, [a-z], [!a-z], [^a-z], {ab}.
 ** input parameters are :
 **			-char	*pat  -> pattern string to be looking for match
 **			-char	**env -> env var. could be NULL
 **				to just expanse in local directory and not in path
 */

static void		ft_tabdel(char ***mytab)
{
	char	**erase;
	int		i;

	if (!mytab || !*mytab)
		return ;
	erase = *mytab;
	i = 0;
	while (erase[i])
	{
		ft_strdel(&erase[i]);
		++i;
	}
	free(*mytab);
	*mytab = NULL;
}

static int		match_bracket_char(char **cmp, const char *pat, char c, int neg)
{
	int		dir;
	char	s;

	if ((*cmp + 2) < pat && (*cmp)[1] == '-' && (s = (*cmp)[0]))
	{
		dir = s > (*cmp)[2];
		while ((dir && s >= (*cmp)[2]) || (!dir && s <= (*cmp)[2]))
		{
			if (!neg && s == c)
				return (1);
			else if (neg && s == c)
				return (0);
			s += (dir * -2 + 1);
		}
		*cmp += 2;
	}
	else if (!neg && **cmp == c)
	{
		return (1);
	}
	else if (neg && **cmp == c)
	{
		return (0);
	}
	return (-1);
}

static int		match_bracket(const char **pat, char c)
{
	char	*cmp;
	int		neg;
	int		ret;

	cmp = (char *)*pat + 1;
	while (**pat != ']')
	{
		if (!**pat)
			return (0);
		++*pat;
	}
	neg = 0;
	if ((*cmp == '^' || *cmp == '!') && ++neg)
		++cmp;
	while (cmp < *pat)
	{
		ret = match_bracket_char(&cmp, *pat, c, neg);
		if (ret != -1)
			return (ret);
		++cmp;
	}
	return (neg);
}

static int		match_star(const char *pat, char *str)
{
	char	*fix;

	(void)pat;
	fix = str + ft_strlen(str);
	return (1);
}

static int		match_pattern(const char *pat, char *str)
{
	while (*pat)
	{
		if (*pat == '?')
			str++;
		else if (*pat == '[')
		{
			if (!match_bracket(&pat, *str))
				return (0);
		}
		else if (*pat == '*')
			return (match_star(pat, str));
		else if (*pat == '\\')
		{
			if (!*++pat || *str != *pat)
				return (0);
		}
		else if (*pat != *str)
			return (0);
		++str;
		++pat;
	}
	return (*str ? 0 : 1);
}

static void		dir_research(const char *pat, char *path, t_ld **match)
{
	DIR				*dir;
	struct dirent	*inside;

	if (!(dir = opendir(path)))
		return ;
	while ((inside = readdir(dir)))
	{
		if (match_pattern(pat, inside->d_name))
			ft_ld_pushfront(match, ft_strdup(inside->d_name));
	}
}

static void		path_research(const char *pat, char **path, t_ld **match)
{
	int				i;
	int				len;
	char			*good_path;

	i = -1;
	good_path = NULL;
	while (path[++i])
	{
		good_path = ft_strjoin(path[i], "/");
		while ((len = ft_strlen(good_path)) && good_path[len - 1] == '/'
				&& good_path[len - 2] == '/')
			good_path[ft_strlen(good_path) - 1] = '\0';
		dir_research(pat, good_path, match);
		ft_strdel(&good_path);
	}
}

char			**glob(const char *pat, char **env)
{
	t_ld	*match;
	char	**gl;
	char	**path;

	match = NULL;
	gl = NULL;
	if (env && (path = ft_strsplit(ft_getenv(env, "PATH"), ':')))
	{
		path_research(pat, path, &match);
		ft_tabdel(&path);
	}
	dir_research(pat, "./", &match);
	if (match)
	{
		gl = ft_ld_to_tab(match);
		ft_ld_clear(&match, &ft_strdel);
	}
	return (gl);
}
