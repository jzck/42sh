/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolz.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:06:30 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/02 16:22:47 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_putnc(char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		++i;
	}
}

char		*ft_strndup(char const *s, int n)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str)
	{
		while (i < n)
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

char	*ft_strdupi(char const *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != ';' && s[i] != '>' && s[i] != '<'
	&& ft_strncmp(s + i, "||", 2))
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str)
	{
		str[i--] = '\0';
		while (i >= 0)
		{
			str[i] = s[i];
			i--;
		}
	}
	return (str);
}
