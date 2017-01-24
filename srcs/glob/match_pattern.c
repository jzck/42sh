/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_pattern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:30:23 by wescande          #+#    #+#             */
/*   Updated: 2017/01/24 20:42:30 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

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

static int		match_star(const char *pat, char *str,
							char *full_word, t_ld **match)
{
	char	*fix;

	if (!pat[1])
		return (1);
	fix = str + ft_strlen(str);
	while (fix > str)
	{
		if (match_pattern(pat + 1, fix, full_word, match))
			return (1);
		--fix;
	}
	return (0);
}

const char		*manage_pat(const char *pat, char *str)
{
	if (pat[0] == '.' && pat[1] == '/'
			&& ((str[0] == '.' && str[1] != '/') || str[0] != '.'))
		return (pat + 2);
	return (pat);
}

int				match_pattern(const char *pat, char *str,
							char *full_word, t_ld **match)
{
	pat = manage_pat(pat, str);
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
			return (match_star(pat, str, full_word, match));
		else if (*pat == '\\')
		{
			if (!*++pat || *str != *pat)
				return (0);
		}
		else if (*pat == '/' && !*str && is_directory(full_word))
			dir_research((pat + 1), full_word, match);
		else if (*pat != *str)
			return (0);
		++str;
		++pat;
	}
	return (*str ? 0 : 1);
}
