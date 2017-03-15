/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_pattern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:30:23 by wescande          #+#    #+#             */
/*   Updated: 2017/03/14 23:25:44 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		return (1);
	else if (neg && **cmp == c)
		return (0);
	return (-1);
}

static int		match_bracket(t_glob *gl, char c)
{
	char	*cmp;
	int		neg;
	int		ret;

	cmp = (char *)gl->pat + 1;
	while (*gl->pat != ']'
			|| is_char_esc(gl->esc, ((char **)gl->m_pat->content)[0], gl->pat))
	{
		if (!*gl->pat)
			return (0);
		++gl->pat;
	}
	neg = 0;
	if ((*cmp == '^' || *cmp == '!')
		&& !is_char_esc(gl->esc, ((char **)gl->m_pat->content)[0], cmp)
		&& ++neg)
		++cmp;
	while (cmp < gl->pat)
	{
		ret = match_bracket_char(&cmp, gl->pat, c, neg);
		if (ret != -1)
			return (ret);
		++cmp;
	}
	return (neg);
}

static int		match_star(t_glob *gl, char *str, char *full_word)
{
	char	*fix;
	char	*pat;

	if (gl->pat[1] == '*' &&
		!is_char_esc(gl->esc, ((char **)gl->m_pat->content)[0], gl->pat + 1))
		dir_research(gl, full_word, gl->pat + 1, (int[]){1, 0});
	if (!*gl->pat || (*gl->pat == '*' && !*++gl->pat))
		return (1);
	pat = gl->pat;
	fix = str + ft_strlen(str);
	while (fix > str)
	{
		gl->pat = pat;
		if (match_pattern(gl, fix, full_word))
			return (1);
		--fix;
	}
	return (0);
}

static char		*manage_pat(t_glob *gl, char *pat, char *str)
{
	if (pat[0] == '.' && pat[1] == '/'
			&& ((str[0] == '.' && str[1] != '/') || str[0] != '.'))
	{
		gl->cur_dir = 0;
		return (pat + 2);
	}
	return (pat);
}

int				match_pattern(t_glob *gl, char *str, char *full_word)
{
	gl->pat = manage_pat(gl, gl->pat, str);
	while (*gl->pat)
	{
		if (is_char_esc(gl->esc, ((char **)gl->m_pat->content)[0], gl->pat))
		{
			if (*str != *gl->pat)
				return (0);
		}
		else if (*gl->pat == '?')
			;
		else if (*gl->pat == '[')
		{
			if (!match_bracket(gl, *str))
				return (0);
		}
		else if (*gl->pat == '*')
			return (match_star(gl, str, full_word));
		else if (*gl->pat == '/' && !*str && is_directory(full_word))
			return (dir_research(gl, full_word, gl->pat + 1, (int[]){0, 0}));
		else if (*gl->pat != *str)
			return (0);
		++str;
		++gl->pat;
	}
	return (*str ? 0 : 1);
}
