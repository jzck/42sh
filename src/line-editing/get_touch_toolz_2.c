/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_touch_toolz_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:43:58 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/04 15:34:10 by gwojda           ###   ########.fr       */
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
	char	*str;
	size_t	*pos;

	str = STR;
	pos = &POS;
	if (!str)
		return ;
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

void			ft_home(void)
{
	char	*str;
	size_t	*pos;

	str = STR;
	pos = &POS;
	if (!str)
		return ;
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

void			ft_move_right(void)
{
	size_t	tmp;
	size_t	*pos;

	pos = &POS;
	if (ft_strlen(STR) <= *pos)
		return ;
	if (STR[*pos] == '\n')
	{
		if (*pos)
		{
			tmp = *pos - 1;
			ft_get_beggin_with_curs(STR, &tmp);
		}
		ft_puttermcaps("cd");
		++(*pos);
		ft_current_str(STR, *pos);
		ft_get_next_str(STR, pos);
		(*pos) = (!STR[*pos]) ? *pos - 1 : *pos;
		ft_get_beggin_with_curs(STR, pos);
	}
	else
	{
		ft_putchar(STR[*pos]);
		++(*pos);
	}
}

void			ft_move_left(void)
{
	size_t	*pos;

	pos = &POS;
	if (!*pos)
		return ;
	if (STR[*pos - 1] == '\n')
	{
		if (*pos - 1 == 0)
		{
			ft_puttermcaps("cd");
			--(*pos);
			return ;
		}
		ft_puttermcaps("cd");
		(*pos) -= 2;
		ft_get_beggin(STR, pos);
		ft_current_str(STR, *pos);
		ft_get_next_str(STR, pos);
		++(*pos);
	}
	else
	{
		ft_puttermcaps("le");
		--(*pos);
	}
}
