/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:29:54 by wescande          #+#    #+#             */
/*   Updated: 2017/01/24 20:42:45 by wescande         ###   ########.fr       */
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

static void		path_research(const char *pat, char **path, t_ld **match)
{
	int				i;

	i = -1;
	while (path[++i])
		dir_research(pat, path[i], match);
}

static char		**treat_glob(t_ld **match)
{
	char	**gl;

	gl = NULL;
	ft_ld_reverse(match);
	*match = ft_ld_order(*match, &ft_strcmp, &ft_strdel);
	gl = ft_ld_to_tab(*match);
	ft_ld_clear(match, &ft_strdel);
	return (gl);
}

char			**glob(const char *pat, char **env)
{
	t_ld	*match;
	char	**path;
	t_ld	*mul_pat;

	match = NULL;
	mul_pat = expand_brace(pat);
	while (mul_pat->next)
	{
		if (env && (path = ft_strsplit(ft_getenv(env, "PATH"), ':')))
		{
			path_research(mul_pat->content, path, &match);
			ft_tabdel(&path);
		}
		if (((char *)mul_pat->content)[0] != '/')
			dir_research(mul_pat->content, ".", &match);
		else
			dir_research(mul_pat->content + 1, "/", &match);
		mul_pat = mul_pat->next;
	}
	ft_ld_clear(&mul_pat, &ft_strdel);
	return (treat_glob(&match));
}
