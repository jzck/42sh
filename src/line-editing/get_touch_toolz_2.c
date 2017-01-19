/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_touch_toolz_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:43:58 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/19 16:42:41 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_put(int nb)
{
	write(1, &nb, 1);
	return (1);
}

void			ft_home_end(char *str, int ret, size_t *pos)
{
	if (ret == TOUCHE_END && str)
	{
		ft_putstr(str + *pos);
		(*pos) = ft_strlen(str);
	}
	else if (ret == TOUCHE_HOME)
		ft_move_to_beggin(str, pos);
}


void		ft_move_left(size_t pos, char *str)
{
	int i;
	int nb;
	int	prompt_size;

	prompt_size = data_singleton()->line.prompt_size;
	i = 1;
	nb = ft_nb_last_line(str, pos - 1) + 3;
	while (i < nb)
	{
		ft_puttermcaps("nd");
		++i;
	}
	if (!(pos - i) || i == 1)
	{
		while (--prompt_size + 3)
			ft_puttermcaps("nd");
	}
}

void			ft_move_term(int ret, size_t *pos, char *str)
{
	int len;
	int str_len;

	len = 0;
	str_len = 0;
	if (ret == FLECHE_DROITE && str && ft_strlen(str) > *pos
	&& str[(*pos)] == '\n')
	{
		ft_puttermcaps("do");
		++(*pos);
	}
	else if (ret == FLECHE_GAUCHE && *pos > 0
	&& str[(*pos) - 1] == '\n')
	{
		ft_puttermcaps("up");
		--(*pos);
		str_len = ft_nb_line(str, *pos - 1);
		len = ft_get_size_prev(str, *pos - 1) - (ft_size_term() * str_len);
		if (ft_get_ind_prev(str, *pos - 1) == 0)
			len += data_singleton()->line.prompt_size + 2;
		while (--len + 1)
			ft_puttermcaps("nd");
	}
	else if (ret == FLECHE_DROITE && str && ft_strlen(str) > *pos)
	{
		ft_putchar(str[*pos]);
		++(*pos);
		if (ft_nb_last_line(str, *pos) == ft_size_term() - 1)
		{
			ft_putchar(' ');
			ft_putchar('\b');
		}
	}
	else if (ret == FLECHE_GAUCHE && *pos > 0)
	{
		ft_puttermcaps("le");
		--(*pos);
	}
}
