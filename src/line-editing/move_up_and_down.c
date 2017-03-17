/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_and_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:21:40 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/17 10:46:55 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_up_2(size_t *pos, char *str)
{
	int len;
	int i;

	i = 0;
	len = ft_size_term();
	if (str[*pos - i] == '\n')
	{
		--len;
		ft_puttermcaps("le");
		++i;
	}
	while (*pos - i && str[*pos - i] != '\n' && --len + 1)
	{
		ft_puttermcaps("le");
		++i;
	}
	if (str[*pos - i] == '\n')
	{
		ft_puttermcaps("nd");
		++(*pos);
	}
	(*pos) -= i;
}

int			ft_up(void)
{
	if (!STR || !POS)
		return (0);
	if (STR[POS - 1] == '\n')
	{
		ft_puttermcaps("cd");
		if (POS >= 2)
			POS -= 2;
		ft_get_beggin(STR, &POS);
		ft_current_str(STR, POS);
		ft_get_next_str(STR, &POS);
		++POS;
	}
	else
		ft_up_2(&POS, STR);
	return (0);
}

static void	ft_down_2(size_t *pos, char *str)
{
	if (*pos)
	{
		--(*pos);
		ft_get_beggin_with_curs(str, pos);
	}
	ft_puttermcaps("cd");
	ft_get_next_str(str, pos);
	(*pos) += 2;
	ft_current_str(str, *pos);
	ft_get_next_str(str, pos);
	if (!(str[*pos]))
		--(*pos);
	ft_get_beggin_with_curs(str, pos);
}

int			ft_down(void)
{
	int		i;
	int		len;

	i = 0;
	if (!STR)
		return (0);
	if (STR[POS] == '\n')
		ft_down_2(&POS, STR);
	else
	{
		len = ft_size_term();
		while (STR[i + POS] && STR[i + POS] != '\n' && --len + 1)
		{
			ft_putchar(STR[i + POS]);
			++i;
		}
		POS += i;
	}
	return (0);
}
