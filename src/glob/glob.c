/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:29:54 by wescande          #+#    #+#             */
/*   Updated: 2017/01/28 01:17:04 by wescande         ###   ########.fr       */
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

static void		path_research(t_glob *gl, char **path)
{
	int				i;

	i = -1;
	while (path[++i])
		dir_research(gl, path[i], gl->pat);
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

	str = (char *)gl->pat;
	start = 0;
	while (*str)
	{
		if (!is_char_esc(gl->esc, gl->pat, str))
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
	ft_ld_pushfront(&gl->match, ft_strdup(gl->pat));
}

static void		printme_me(const char *pat, const unsigned char *esc)
{
	char	*str;
	int		index;
	int		len;

	str = (char *)pat;
	while (*str)
	{
		ft_dprintf(3, is_char_esc(esc, pat, str) ? "\\%c" : "%c", *str);
		++str;
	}
	ft_dprintf(3, "\n");
	len = ft_strlen(pat);
	index = -1;
	while (++index < len)
		ft_dprintf(3, ((esc[index / 8] >> (7 - index % 8)) & 1) ? " 1" : "0");
	ft_dprintf(3, "\n");
	index = 0;
	while (index < len)
	{
		ft_dprintf(3, "%08b", esc[index / 8]);
		index += 8;
	}
	ft_dprintf(3, "\n");
}

char			**glob(const char *pat, const unsigned char *esc, char **env)
{
	t_glob	gl;
	char	**path;

	gl = (t_glob){pat, esc, NULL, NULL};
	expand_brace(&gl);
	while (gl.m_pat->next)
	{
		gl.pat = ((char **)gl.m_pat->content)[0];
		gl.esc = ((unsigned char **)gl.m_pat->content)[1];
		printme_me(gl.pat, gl.esc);
		add_simple_pat(&gl);
		if (!(gl.pat[0] == '/' || (gl.pat[0] == '.' && gl.pat[1] == '/'))
				&& env && (path = ft_strsplit(ft_getenv(env, "PATH"), ':')))
		{
			path_research(&gl, path);
			ft_tabdel(&path);
		}
		gl.pat = ((char **)gl.m_pat->content)[0];
		if (gl.pat[0] != '/')
			dir_research(&gl, ".", gl.pat);
		else
			dir_research(&gl, "/", gl.pat + 1);
		gl.m_pat = gl.m_pat->next;
	}
	ft_ld_clear(&gl.m_pat, &ft_tabdel);
	return (treat_glob(&gl.match));
}
