/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cut_paste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 12:45:06 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/17 11:56:42 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_strdupi_space(char const *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != '\n')
		++i;
	if (s[i] == '\n')
		++i;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
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

int			ft_v(char **str, size_t *pos)
{
	size_t	tmp_pos;
	int		i;
	char	*tmp;

	tmp = data_singleton()->line.copy_tmp;
	i = -1;
	tmp_pos = *pos;
	if (!*str || !tmp)
		return (0);
	while (tmp[++i])
		if (!(*str = ft_realloc_imput(*str, tmp[i], *pos + i)))
			return (-1);
	if (*pos)
	{
		--(*pos);
		ft_get_beggin_with_curs(*str, pos);
	}
	ft_current_str(*str, *pos);
	ft_get_next_str(*str, pos);
	ft_putnc('\b', *pos - tmp_pos);
	*pos = tmp_pos;
	return (0);
}

int			ft_x(char **str, size_t *pos)
{
	int		i;
	char	**tmp;

	tmp = &data_singleton()->line.copy_tmp;
	if (!*str)
		return (0);
	if (*tmp)
		ft_strdel(tmp);
	if (!(*tmp = ft_strdupi_space(&(*str)[*pos])))
		return (-1);
	i = ft_strlen(*tmp);
	while (i >= 0)
	{
		if (!(*str = ft_remove_imput(*str, *pos + i)))
			return (-1);
		--i;
	}
	ft_puttermcaps("cd");
	return (0);
}

int			ft_c(char **str, size_t *pos)
{
	char	**tmp;

	if (!*str)
		return (0);
	tmp = &data_singleton()->line.copy_tmp;
	if (*tmp)
		ft_strdel(tmp);
	if (!(*tmp = ft_strdupi_space(*str + *pos)))
		return (-1);
	return (0);
}
