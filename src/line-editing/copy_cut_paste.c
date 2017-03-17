/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cut_paste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 12:45:06 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/17 10:45:37 by gwojda           ###   ########.fr       */
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

int			ft_v(void)
{
	size_t	tmp_pos;
	int		i;
	char	*tmp;

	tmp = data_singleton()->line.copy_tmp;
	i = -1;
	tmp_pos = POS;
	if (!STR || !tmp)
		return (0);
	while (tmp[++i])
		if (!(STR = ft_realloc_imput(STR, tmp[i], POS + i)))
			return (-1);
	if (POS)
	{
		--POS;
		ft_get_beggin_with_curs(STR, &POS);
	}
	ft_current_str(STR, POS);
	ft_get_next_str(STR, &POS);
	ft_putnc('\b', POS - tmp_pos);
	POS = tmp_pos;
	return (0);
}

int			ft_x(void)
{
	int		i;
	char	**tmp;

	tmp = &data_singleton()->line.copy_tmp;
	if (!STR)
		return (0);
	if (*tmp)
		ft_strdel(tmp);
	if (!(*tmp = ft_strdupi_space(&STR[POS])))
		return (-1);
	i = ft_strlen(*tmp);
	while (i >= 0)
	{
		if (!(STR = ft_remove_imput(STR, POS + i)))
			return (-1);
		--i;
	}
	ft_puttermcaps("cd");
	return (0);
}

int			ft_c(void)
{
	char	**tmp;

	if (!STR)
		return (1);
	tmp = &data_singleton()->line.copy_tmp;
	if (*tmp)
		ft_strdel(tmp);
	if (!(*tmp = ft_strdupi_space(STR + POS)))
		return (-1);
	return (0);
}
