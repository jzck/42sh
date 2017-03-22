/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_misc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:17:10 by alao              #+#    #+#             */
/*   Updated: 2017/03/22 18:23:04 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** Count the number of time char c is in str.
*/

static size_t	ft_strxchr(char *str, char c)
{
	size_t		rt;

	rt = 0;
	while(*str)
	{
		if (*str == c)
			rt++;
		str++;
	}
	return (rt);
}

/*
** Add escape char \ for char to_escape.
*/

char		*ft_add_escape(char *str, char to_escape)
{
	char	*rt;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	if (!ft_strxchr(str, ' '))
		return (ft_strdup(str));
	rt = ft_strnew(ft_strlen(str) + ft_strxchr(str, to_escape));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == to_escape)
		{
			i++;
			rt[j++] = '\\';
			rt[j++] = ' ';
		}
		else
			rt[j++] = str[i++];
	}
	return (rt);
}

/*
** Support: Return the size of a char**.
*/

int			ft_sstrlen(char **s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
** Support: Tranform a char** as char* with char*sep in between.
*/

char		*ft_sstrtostr(char **s, char *sep)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	tmp = NULL;
	tmp2 = NULL;
	tmp = ft_strjoin(s[0], sep);
	i = 1;
	while (s[i])
	{
		tmp2 = ft_strjoin(tmp, s[i]);
		ft_memdel((void *)&tmp);
		tmp = ft_strjoin(tmp2, sep);
		ft_memdel((void *)&tmp2);
		i++;
	}
	return (tmp);
}
