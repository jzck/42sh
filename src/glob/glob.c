/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:29:54 by wescande          #+#    #+#             */
/*   Updated: 2017/03/14 23:30:59 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** glob return expansion of a string.
** pattern searched are *, ?, [a-z], [!a-z], [^a-z], {ab, ac}, **
** input parameters are :
**			-char	*pat  -> pattern string to be looking for match
**			-char	*esc  -> escape binary sequence of *pat
**			-char	**env -> env var. could be NULL
**				to just expanse in local directory and not in path dir
*/

static int		order_glob(const char *s1, const char *s2)
{
	char	c1;
	char	c2;

	if (!s1 || !s2)
		return (1);
	c1 = ft_tolower(*s1++);
	c2 = ft_tolower(*s2++);
	if (!c1)
		return (-(c1 - c2));
	while (c1 == c2)
	{
		c1 = ft_tolower(*s1++);
		c2 = ft_tolower(*s2++);
		if (!c1)
			return (-(c1 - c2));
	}
	return (-(c1 - c2));
}

static void		merge_ld_glob(t_ld **match, t_ld **tmp)
{
	t_ld	*ultimate;

	*tmp = ft_ld_order(*tmp, &order_glob);
	ultimate = ft_ld_back(*tmp);
	ultimate->next = *match;
	if (*match)
		(*match)->prev = ultimate;
	*match = *tmp;
	*tmp = NULL;
}

static char		**treat_glob(t_glob *gl)
{
	char	**ret;

	ret = NULL;
	ft_ld_clear(&gl->m_pat, &ft_tabdel);
	ft_ld_reverse(&gl->match);
	ret = ft_ld_to_tab(gl->match);
	ft_ld_clear(&gl->match, &ft_strdel);
	return (ret);
}

static void		normal_expand_before_match(t_glob *gl, int do_match)
{
	char	*home;

	expand_var(gl);
	expand_bquote(gl);
	if (do_match)
		expand_brace(gl);
	if ((home = ft_getenv(data_singleton()->env, "HOME")))
		expand_home(gl, home);
}

char			**glob(char *pat, unsigned char *esc,
		unsigned char *esc2, int do_match)
{
	t_glob	gl;
	int		len;

	len = ft_strlen(pat);
	gl = (t_glob){0, 0, ft_strdup(pat), dup_char_esc(esc, (len >> 3) + 1),
		dup_char_esc(esc2, (len >> 3) + 1), NULL, NULL, NULL};
	normal_expand_before_match(&gl, do_match);
	if (do_match)
		while (gl.m_pat && !(gl.found = 0))
		{
			gl.cur_dir = 1;
			gl.pat = CH(gl.m_pat)[0];
			if ((gl.esc = UCH(gl.m_pat)[1]) && gl.pat[0] != '/')
				dir_research(&gl, ".", gl.pat, (int[]){0, 1});
			else
				dir_research(&gl, "/", gl.pat + 1, (int[]){0, 1});
			if (!gl.found)
				ft_ld_pushfront(&gl.match, ft_strdup(CH(gl.m_pat)[0]));
			else
				merge_ld_glob(&gl.match, &gl.match_tmp);
			if (!gl.m_pat->next)
				break ;
			gl.m_pat = gl.m_pat->next;
		}
	return (treat_glob(&gl));
}
