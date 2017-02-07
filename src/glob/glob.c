/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:29:54 by wescande          #+#    #+#             */
/*   Updated: 2017/02/07 16:13:36 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

/*
** glob return expansion of a string.
** pattern searched are *, ?, [a-z], [!a-z], [^a-z], {ab, ac}, **
** input parameters are :
**			-char	*pat  -> pattern string to be looking for match
**			-char	*esc  -> escape binary sequence of *pat
**			-char	**env -> env var. could be NULL
**				to just expanse in local directory and not in path dir
*/

static char		**treat_glob(t_ld **match)
{
	char	**gl;

	gl = NULL;
	ft_ld_reverse(match);
	gl = ft_ld_to_tab(*match);
	ft_ld_clear(match, &ft_strdel);
	return (gl);
}

char			**glob(char *pat, unsigned char *esc,
										unsigned char *esc2)
{
	t_glob	gl;
	int		ret;
	int		len;

	len = ft_strlen(pat);
	gl = (t_glob){ft_strdup(pat), dup_char_esc(esc, len),
		dup_char_esc(esc2, len), NULL, NULL};
	expand_var(&gl);
	ft_memdel((void **)&gl.esc2);
	expand_brace(&gl);
	while (gl.m_pat->next)
	{
		gl.pat = ((char **)gl.m_pat->content)[0];
		gl.esc = ((unsigned char **)gl.m_pat->content)[1];
		if (gl.pat[0] != '/')
			ret = dir_research(&gl, ".", gl.pat, 0);
		else
			ret = dir_research(&gl, "/", gl.pat + 1, 0);
		if (!ret)
			ft_ld_pushfront(&gl.match,
					ft_strdup(((char **)gl.m_pat->content)[0]));
		gl.m_pat = gl.m_pat->next;
	}
	ft_ld_clear(&gl.m_pat, &ft_tabdel);
	return (treat_glob(&gl.match));
}
