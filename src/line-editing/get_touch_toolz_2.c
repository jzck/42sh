/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_touch_toolz_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:43:58 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/23 15:17:18 by gwojda           ###   ########.fr       */
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
		ft_check_end_of_line(str, *pos);
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
			if (*pos)
			{
				tmp = *pos - 1;
				ft_get_beggin_with_curs(str, &tmp);
			}
			//si premiere ligne ne contient que \n, puis fleche droite -> decalage//
			ft_puttermcaps("cd");
			++(*pos);
			ft_current_str(str, *pos);
			ft_get_next_str(str, pos);
			if (!str[*pos])
				--(*pos);
			++(*pos);
			ft_get_beggin_with_curs(str, pos);
			if (*pos > 0 && str[*pos - 1] == '\n')
				ft_puttermcaps("nd");
		}
		else
		{
			ft_putchar(str[*pos]);
			++(*pos);
		}
	}
	else if (ret == FLECHE_GAUCHE && *pos > 0)
	{
		if (str[*pos - 1] == '\n')
		{
			if (*pos - 1 == 0)
			{
				ft_puttermcaps("cd");
				--(*pos);
				return ;
			}
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
