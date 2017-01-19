/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cut_paste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 12:45:06 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/19 16:42:34 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_v(char *tmp, size_t *pos, char **str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = *pos;
	if (!tmp)
		return ;
	while (tmp[i])
	{
		*str = ft_realloc_imput(*str, tmp[i], *pos);
		++(*pos);
		++i;
	}
	ft_putstr((*str) + *pos - i);
	if (ft_nb_last_line(*str, *pos) == ft_size_term() - 1)
	{
		ft_putchar(' ');
		ft_putchar('\b');
	}
	*pos = ft_strlen(*str);
	ft_move_to_beggin(*str, pos);
	*pos = len;
	write(1, *str, *pos);
}

static void	ft_x(char **tmp, size_t *pos, char **str)
{
	int	i;

	i = ft_strlen(*str) - 1;
	if (*tmp)
		ft_strdel(tmp);
	*tmp = ft_strdup(&(*str)[(*pos)]);
	while (i >= 0 && i >= (int)*pos)
	{
		*str = ft_remove_imput(*str, i);
		--i;
	}
	ft_move_to_beggin(*str, pos);
	ft_puttermcaps("cd");
	ft_putstr(*str);
	*pos = ft_strlen(*str);
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
		tmp = ft_strdup(&(*str)[(*pos)]);
	}
	else if (ret == TOUCHE_OPT_V)
		ft_v(tmp, pos, str);
}
