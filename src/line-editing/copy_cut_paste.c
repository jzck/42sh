/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cut_paste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 12:45:06 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/04 14:55:05 by gwojda           ###   ########.fr       */
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

void		ft_v(void)
{
	size_t	tmp_pos;
	int		i;
	char	*tmp;
	char	**str;
	size_t	*pos;

	tmp = data_singleton()->line.copy_tmp;
	str = &STR;
	pos = &POS;
	i = -1;
	tmp_pos = *pos;
	if (!*str || !tmp)
		return ;
	while (tmp[++i])
		*str = ft_realloc_imput(*str, tmp[i], *pos + i);
	if (*pos)
	{
		--(*pos);
		ft_get_beggin_with_curs(*str, pos);
	}
	ft_current_str(*str, *pos);
	ft_get_next_str(*str, pos);
	ft_putnc('\b', *pos - tmp_pos);
	(*pos) = tmp_pos;
}

void		ft_x(void)
{
	int		i;
	char	**tmp;
	char	**str;
	size_t	*pos;

	tmp = &data_singleton()->line.copy_tmp;
	str = &STR;
	pos = &POS;
	if (!*str)
		return ;
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

void		ft_c(void)
{
	char	*tmp;
	char	**str;
	size_t	*pos;

	tmp = data_singleton()->line.copy_tmp;
	str = &STR;
	pos = &POS;
	if (tmp)
		ft_strdel(&tmp);
	tmp = ft_strdupi_space((*str) + (*pos));
}
