/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 11:12:09 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/17 10:46:44 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_prev_word(size_t *pos, char *str)
{
	int i;

	i = 0;
	if (str[*pos - 1] != '\n' && !(str[*pos] == '\n' || str[*pos] == ' '))
	{
		ft_puttermcaps("le");
		--(*pos);
	}
	while ((int)*pos - i - 1 > 0 && str[*pos - i - 1] == ' ')
	{
		ft_puttermcaps("le");
		++i;
	}
	(*pos) = (i && str[*pos - i] == '\n') ? *pos - i + 1 : *pos - i;
}

static void	ft_found_prev_word_2(int i, char *str, size_t *pos)
{
	if (*pos && !(str[*pos] == '\n' || str[*pos] == ' '))
	{
		ft_puttermcaps("le");
		--(*pos);
	}
	while (*pos - i && (str[*pos - i] == '\n' || str[*pos - i] == ' '))
	{
		ft_puttermcaps("le");
		++i;
	}
	while (*pos - i && str[*pos - i] != '\n' && str[*pos - i] != ' ')
	{
		ft_puttermcaps("le");
		++i;
	}
	if (str[*pos - i] == '\n' || str[*pos - i] == ' ')
	{
		ft_puttermcaps("nd");
		++(*pos);
	}
	(*pos) -= i;
}

int			ft_found_prev_word(void)
{
	int		i;

	i = 0;
	if (!POS || !STR)
		return (0);
	ft_init_prev_word(&POS, STR);
	if (POS >= 1 && STR[POS - 1] == '\n')
	{
		if (POS - 1 == 0)
		{
			ft_puttermcaps("cd");
			--POS;
			return (0);
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
		ft_found_prev_word_2(i, STR, &POS);
	return (0);
}

static void	ft_found_next_word_2(void)
{
	if (POS)
	{
		--POS;
		ft_get_beggin_with_curs(STR, &POS);
	}
	ft_puttermcaps("cd");
	ft_get_next_str(STR, &POS);
	POS += (POS || STR[0] != '\n') ? 2 : 1;
	ft_current_str(STR, POS);
	ft_get_next_str(STR, &POS);
	if (!STR[POS])
		--POS;
	ft_get_beggin_with_curs(STR, &POS);
}

int			ft_found_next_word(void)
{
	int		i;

	i = 0;
	if (!STR)
		return (0);
	while (STR[i + POS] && STR[i + POS] == ' ')
	{
		ft_putchar(STR[i + POS]);
		++i;
	}
	if (STR[POS] == '\n')
		ft_found_next_word_2();
	else
	{
		while (STR[i + POS] && STR[i + POS] != '\n' && STR[i + POS] != ' ')
		{
			ft_putchar(STR[i + POS]);
			++i;
		}
		POS += i;
	}
	return (0);
}
