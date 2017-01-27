/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:29:54 by wescande          #+#    #+#             */
/*   Updated: 2017/01/27 19:05:38 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

/*
** glob return expansion of a string.
** pattern searched are ~, *, ?, [a-z], [!a-z], [^a-z], {ab, ac}, **
** input parameters are :
**			-char	*pat  -> pattern string to be looking for match
**			-char	**env -> env var. could be NULL
**				to just expanse in local directory and not in path
*/

static void		path_research(t_glob *tglob, char **path)
{
	int				i;

	i = -1;
	while (path[++i])
		dir_research(tglob, path[i]);
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

static void		add_simple_pat(t_glob *gl)
{
	char	*str;
	int		start;

	str = ((char **)gl->m_pat->content)[0];
	start = 0;
	while (*str)
	{
		if (!is_char_esc(((char **)gl->m_pat->content)[1],
					((char **)gl->m_pat->content)[0], str))
		{
		if (*str == '[')
			start = 1;
		else if (*str == ']' && start == 1)
			return ;
		else if (*str == '*' || *str == '?')
			return ;
		}
		++str;
	}
	ft_ld_pushfront(&gl->match, ((char **)gl->m_pat->content)[0]);
}

char			**glob(const char *pat, const char *esc, char **env)
{
	t_glob	tglob;
	char	**path;

	tglob = (t_glob){pat, esc, NULL, NULL};
	expand_brace(&tglob, tglob.pat);
	while (tglob.m_pat->next)
	{
		add_simple_pat(&tglob);
		if (!(((char **)tglob.m_pat->content)[0][0] == '/'
			|| (((char **)tglob.m_pat->content)[0][0] == '.'
			&& ((char **)tglob.m_pat->content)[0][1] == '/'))
			&& env && (path = ft_strsplit(ft_getenv(env, "PATH"), ':')))
		{
			path_research(&tglob, path);
			ft_tabdel(&path);
		}
		if (((char **)tglob.m_pat->content)[0][0] != '/')
			dir_research(&tglob, ".");
		else
			dir_research(&tglob, "/");
		tglob.m_pat = tglob.m_pat->next;
	}
	ft_ld_clear(&tglob.m_pat, &ft_strdel);
	return (treat_glob(&tglob.match));
}
