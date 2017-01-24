/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cut_paste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 12:45:06 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/24 14:28:57 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_v(char *tmp, size_t *pos, char **str)
{
	size_t	tmp_pos;
	int		i;

	i = 0;
	tmp_pos = *pos;
	if (!tmp)
		return ;
	while (tmp[i])
	{
		*str = ft_realloc_imput(*str, tmp[i], *pos + i);
		++i;
	}
	sleep(1);
	if (*pos)
	{
		--(*pos);
		ft_get_beggin_with_curs(*str, pos);
	}
	sleep(1);
	ft_current_str(*str, *pos);
	sleep(1);
	ft_get_next_str(*str, pos);
	sleep(1);
	ft_putnc('\b', *pos - tmp_pos + 1);
	(*pos) = tmp_pos;
}

static char	*ft_strdupi_space(char const *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != '\n')
		++i;
	if (s[i] == '\n')
		++i;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str)
	{
		str[i] = '\0';
		--i;
		while (i >= 0)
		{
			str[i] = s[i];
			--i;
		}
	}
	return (str);
}

static void	ft_x(char **tmp, size_t *pos, char **str)
{
	int	i;

	if (*tmp)
		ft_strdel(tmp);
	*tmp = ft_strdupi_space(&(*str)[(*pos)]);
	i = ft_strlen(*tmp);
	while (i >= 0)
	{
		*str = ft_remove_imput(*str, *pos + i);
		--i;
	}
	ft_puttermcaps("cd");
}


void		ft_cxv(int ret, size_t *pos, char **str)
{
	static char	*tmp = NULL;

	if (!*str)
		return ;
	if (ret == TOUCHE_OPT_X)
		ft_x(&tmp, pos, str);
	else if (ret == TOUCHE_OPT_C)
	{
		if (tmp)
			ft_strdel(&tmp);
		tmp = ft_strdupi_space((*str) + (*pos));
		ft_printf("\n\ntmp = \"%s\"\n\n", tmp);
	}
	else if (ret == TOUCHE_OPT_V)
		ft_v(tmp, pos, str);
}
