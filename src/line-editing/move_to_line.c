/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:21:40 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/21 17:29:08 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_up(size_t *pos, char *str)
{
	int i;
	int len;

	i = 0;
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
}

static void	ft_down(size_t *pos, char *str)
{
	int i;
	int len;

	i = 0;
	if (str[*pos] == '\n')
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
	else
	{
		len = ft_size_term();
		while (str[i + *pos] && str[i + *pos] != '\n' && --len + 1)
		{
			ft_putchar(str[i + *pos]);
			++i;
		}
		*pos += i;
	}
}

void		ft_move_to_line(int ret, size_t *pos, char *str)
{
	if (!str)
		return ;
	if (ret == TOUCHE_OPT_UP)
		ft_up(pos, str);
	else if (ret == TOUCHE_OPT_DOWN)
		ft_down(pos, str);
}
