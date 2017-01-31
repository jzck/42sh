/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_spe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 20:49:30 by wescande          #+#    #+#             */
/*   Updated: 2017/01/31 23:15:41 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

static int		ft_strlen_c(const char *str, const char *fix,
							const unsigned char *esc, char c)
{
	int			len;
	int			nb;

	len = 0;
	nb = 0;
	while (*str && (*str != c || nb))
	{
		nb += *str == '{' && !is_char_esc(esc, fix, str);
		nb -= *str == '}' && !is_char_esc(esc, fix, str);
		++str;
		++len;
	}
	return (len);
}

static int		ft_nbstr_c(const char *str, const unsigned char *esc, char c)
{
	int			len;
	int			nb;
	const char	*fix;

	len = 0;
	nb = 0;
	fix = str;
	while (*str)
	{
		while (*str && *str == c)
			++str;
		if (*str)
			++len;
		while (*str && (*str != c || nb))
		{
			nb += *str == '{' && !is_char_esc(esc, fix, str);
			nb -= *str == '}' && !is_char_esc(esc, fix, str);
			++str;
		}
	}
	return (len);
}

char			**ft_strsplit_spe(const char *str,
								const unsigned char *esc, char c)
{
	char		**s1;
	int			i;
	const char	*fix;
	int			len;

	if (!str)
		return (NULL);
	if (!(s1 = (char**)malloc(sizeof(*s1) * (ft_nbstr_c(str, esc, c) + 1))))
		return (NULL);
	i = 0;
	fix = str;
	while (*str && *str == c)
		++str;
	while (*str && (len = ft_strlen_c(str, fix, esc, c)))
	{
		if (!(s1[i] = (char*)malloc(sizeof(**s1) * (len + 1))))
			return (NULL);
		ft_strncpy(s1[i], str, len);
		str = str + len;
		++i;
		while (*str && *str == c)
			++str;
	}
	s1[i] = 0;
	return (s1);
}
