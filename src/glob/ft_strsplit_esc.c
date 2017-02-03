/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_esc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 22:18:46 by wescande          #+#    #+#             */
/*   Updated: 2017/01/31 23:15:17 by wescande         ###   ########.fr       */
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

static int		nb_c(const char *str, const unsigned char *esc, char c)
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

unsigned char	**ft_strsplit_esc(const char *str,
								const unsigned char *esc, char c)
{
	unsigned char		**s1;
	int					i;
	const char			*fix;
	int					len;
	int					pos;

	if ((pos = -1) && !str)
		return (NULL);
	if (!(s1 = (unsigned char **)malloc(sizeof(*s1) * (nb_c(str, esc, c) + 1))))
		return (NULL);
	i = 0;
	fix = str;
	while (*str && *str == c && ++pos > -1)
		++str;
	while (*str && (len = ft_strlen_c(str, fix, esc, c)))
	{
		s1[i] = ft_sub_esc(esc, pos, len);
		str += len;
		pos += len;
		++i;
		while (*str && *str == c && ++pos)
			++str;
	}
	s1[i] = 0;
	return (s1);
}
