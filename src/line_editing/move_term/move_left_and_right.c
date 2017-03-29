/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_and_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:43:58 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/29 17:45:36 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_end_right(char *str, size_t pos)
{
	if (!str)
		return ;
	if (ft_nb_last_line(str, pos) == 0)
	{
		ft_putchar(str[pos]);
		ft_puttermcaps("le");
	}
}

int			ft_move_right(char **str, size_t *pos)
{
	size_t	tmp;

	if (ft_strlen(*str) <= *pos)
		return (0);
	if ((*str)[*pos] == '\n')
	{
		if (*pos)
		{
			tmp = *pos - 1;
			ft_get_beggin_with_curs(*str, &tmp);
		}
		ft_puttermcaps("cd");
		++(*pos);
		ft_current_str(*str, *pos);
		ft_get_next_str(*str, pos);
		*pos = (!(*str)[*pos]) ? *pos - 1 : *pos;
		ft_get_beggin_with_curs(*str, pos);
	}
	else
	{
		ft_putchar((*str)[*pos]);
		++(*pos);
		check_end_right(*str, *pos);
	}
	return (0);
}

int			ft_move_left(char **str, size_t *pos)
{
	if (!*pos)
		return (0);
	if ((*str)[*pos - 1] == '\n')
	{
		if (*pos - 1 == 0)
		{
			ft_puttermcaps("cd");
			--(*pos);
			return (0);
		}
		ft_puttermcaps("cd");
		*pos -= 2;
		ft_get_beggin(*str, pos);
		if (!*pos && (*str)[*pos] == '\n')
			++(*pos);
		ft_current_str(*str, *pos);
		ft_get_next_str(*str, pos);
		++(*pos);
	}
	else
	{
		ft_puttermcaps("le");
		--(*pos);
	}
	return (0);
}
