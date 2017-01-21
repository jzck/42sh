/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_touch_toolz_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:43:58 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/21 17:13:55 by gwojda           ###   ########.fr       */
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
		if (*pos)
		{
			--(*pos);
			ft_get_beggin_with_curs(str, pos);
		}
		ft_puttermcaps("cd");
		while (str[*pos])
			++(*pos);
		ft_get_beggin(str, pos);
		ft_current_str(str, *pos);
		ft_get_next_str(str, pos);
	}
	else if (ret == TOUCHE_HOME)
	{
		if (*pos)
		{
			--(*pos);
			ft_get_beggin_with_curs(str, pos);
			if (str[*pos + 1] == '\n')
				ft_puttermcaps("nd");
		}
		ft_puttermcaps("cd");
		*pos = 0;
		ft_current_str(str, *pos);
		ft_get_next_str(str, pos);
		if (!str[*pos])
			--(*pos);
		ft_get_beggin_with_curs(str, pos);
	}
}

void			ft_move_term(int ret, size_t *pos, char *str)
{
	size_t	tmp;

	if (ret == FLECHE_DROITE && str && ft_strlen(str) > *pos)
	{
		if (str[*pos] == '\n')
		{
			tmp = *pos - 1;
			ft_get_beggin_with_curs(str, &tmp);
			ft_puttermcaps("cd");
			++(*pos);
			ft_current_str(str, *pos);
			ft_get_next_str(str, pos);
			if (!str[*pos])
				--(*pos);
			ft_get_beggin_with_curs(str, pos);
		}
		else
		{
			ft_putchar(str[*pos]);
			++(*pos);
		}
		if (ft_nb_last_line(str, *pos) == ft_size_term() - 1)
		{
			ft_putchar(' ');
			ft_putchar('\b');
		}
	}
	else if (ret == FLECHE_GAUCHE && *pos > 0)
	{
		if (str[*pos - 1] == '\n')
		{
			ft_puttermcaps("cd");
			(*pos) -= 2;
			ft_get_beggin(str, pos);
			ft_current_str(str, *pos);
			ft_get_next_str(str, pos);
			++(*pos);
		}
		else
		{
			ft_puttermcaps("le");
			--(*pos);
		}
	}
}
