/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_and_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:43:58 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/16 17:15:21 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_move_right(void)
{
	size_t	tmp;

	if (ft_strlen(STR) <= POS)
		return (1);
	if (STR[POS] == '\n')
	{
		if (POS)
		{
			tmp = POS - 1;
			ft_get_beggin_with_curs(STR, &tmp);
		}
		ft_puttermcaps("cd");
		++POS;
		ft_current_str(STR, POS);
		ft_get_next_str(STR, &POS);
		POS = (!STR[POS]) ? POS - 1 : POS;
		ft_get_beggin_with_curs(STR, &POS);
	}
	else
	{
		ft_putchar(STR[POS]);
		++POS;
	}
	return (1);
}

int			ft_move_left(void)
{
	if (!POS)
		return (1);
	if (STR[POS - 1] == '\n')
	{
		if (POS - 1 == 0)
		{
			ft_puttermcaps("cd");
			--POS;
			return (1);
		}
		ft_puttermcaps("cd");
		POS -= 2;
		ft_get_beggin(STR, &POS);
		if (!POS && STR[POS] == '\n')
			++POS;
		ft_current_str(STR, POS);
		ft_get_next_str(STR, &POS);
		++POS;
	}
	else
	{
		ft_puttermcaps("le");
		--POS;
	}
	return (1);
}
