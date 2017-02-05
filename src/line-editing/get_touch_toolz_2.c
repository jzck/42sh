/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_touch_toolz_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:43:58 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/05 17:07:43 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_put(int nb)
{
	write(1, &nb, 1);
	return (1);
}

void			ft_end(void)
{
	if (!STR)
		return ;
	if (POS)
	{
		--POS;
		ft_get_beggin_with_curs(STR, &POS);
	}
	ft_puttermcaps("cd");
	while (STR[POS])
		++POS;
	ft_get_beggin(STR, &POS);
	ft_current_str(STR, POS);
	ft_get_next_str(STR, &POS);
}

void			ft_home(void)
{
	if (!STR)
		return ;
	if (POS)
	{
		--POS;
		ft_get_beggin_with_curs(STR, &POS);
		if (STR[POS + 1] == '\n')
			ft_puttermcaps("nd");
	}
	ft_puttermcaps("cd");
	POS = 0;
	ft_current_str(STR, POS);
	ft_get_next_str(STR, &POS);
	ft_check_end_of_line(STR, POS);
	if (!STR[POS])
		--POS;
	ft_get_beggin_with_curs(STR, &POS);
}

void			ft_move_right(void)
{
	size_t	tmp;

	if (ft_strlen(STR) <= POS)
		return ;
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
}

void			ft_move_left(void)
{
	if (!POS)
		return ;
	if (STR[POS - 1] == '\n')
	{
		if (POS - 1 == 0)
		{
			ft_puttermcaps("cd");
			--POS;
			return ;
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
}
