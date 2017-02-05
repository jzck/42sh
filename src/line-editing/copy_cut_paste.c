/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cut_paste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 12:45:06 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/05 17:07:12 by gwojda           ###   ########.fr       */
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

	tmp = data_singleton()->line.copy_tmp;
	i = -1;
	tmp_pos = POS;
	if (!STR || !tmp)
		return ;
	while (tmp[++i])
		STR = ft_realloc_imput(STR, tmp[i], POS + i);
	if (POS)
	{
		--POS;
		ft_get_beggin_with_curs(STR, &POS);
	}
	ft_current_str(STR, POS);
	ft_get_next_str(STR, &POS);
	ft_putnc('\b', POS - tmp_pos);
	POS = tmp_pos;
}

void		ft_x(void)
{
	int		i;
	char	**tmp;

	tmp = &data_singleton()->line.copy_tmp;
	if (!STR)
		return ;
	if (*tmp)
		ft_strdel(tmp);
	*tmp = ft_strdupi_space(&STR[POS]);
	i = ft_strlen(*tmp);
	while (i >= 0)
	{
		STR = ft_remove_imput(STR, POS + i);
		--i;
	}
	ft_puttermcaps("cd");
}

void		ft_c(void)
{
	char	*tmp;

	tmp = data_singleton()->line.copy_tmp;
	if (tmp)
		ft_strdel(&tmp);
	tmp = ft_strdupi_space(STR + POS);
}
