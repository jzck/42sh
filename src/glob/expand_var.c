/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:09:27 by wescande          #+#    #+#             */
/*   Updated: 2017/02/20 15:24:34 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

/*
** expand_var return value of $var in the string.
** input parameters are :
**			-t_glob		*gl  -> struct of expanding
*/

static void			insert_var(t_glob *gl, char *pos, char *name, char *content)
{
	char			*s1;
	char			*s2;
	int				delta;
	unsigned char	*new_esc;

	delta = pos - gl->pat;
	s1 = ft_strsub(gl->pat, 0, delta);
	delta += ft_strlen(name) + 1;
	s2 = ft_strsubf(gl->pat, delta, ft_strlen(gl->pat) - delta, 1);
	gl->pat = ft_strjoinf(ft_strjoin(s1, content), s2, 1);
	new_esc = calc_expand_esc(gl->esc, ft_strlen(s1),
			(int [2]){ft_strlen(content), 1},
			(int [2]){delta, ft_strlen(s2)});
	ft_memdel((void **)&gl->esc);
	gl->esc = new_esc;
	new_esc = calc_expand_esc(gl->esc2, ft_strlen(s1),
			(int [2]){ft_strlen(content), 1},
			(int [2]){delta, ft_strlen(s2)});
	ft_memdel((void **)&gl->esc2);
	gl->esc2 = new_esc;
	ft_strdel(&s1);
	ft_strdel(&s2);
	ft_strdel(&content);
}

static char			*get_name(t_glob *gl, const char *pat)
{
	const char		*str;

	str = pat;
	if (ft_isdigit(*str))
		return (ft_strsub(pat, 0, str - pat + 1));
	if (*str == '?')
		return (ft_strsub(pat, 0, str - pat + 1));
	while ((ft_isalnum(*str) || *str == '_' || *str == '-')
			&& !is_char_esc(gl->esc2, gl->pat, str))
		++str;
	return (ft_strsub(pat, 0, str - pat));
}

void				expand_var(t_glob *gl)
{
	char			*pat;
	char			*var;
	char			*content;

	pat = gl->pat;
	while (*pat)
	{
		if (*pat == '$' && !is_char_esc(gl->esc2, gl->pat, pat) &&
				(var = get_name(gl, pat + 1)))
		{
			if (ft_strlen(var))
			{
				content = ft_getenv(data_singleton()->env, var);
				insert_var(gl, pat, var, content);
				pat = gl->pat;
			}
			ft_strdel(&var);
		}
		++pat;
	}
}
