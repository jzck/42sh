/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_touch_toolz_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:43:58 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/25 16:26:42 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_put(int nb)
{
	write(1, &nb, 1);
	return (1);
}

void			ft_end(char *str, size_t *pos)
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

void			ft_home(char *str, size_t *pos)
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

void			ft_move_right(size_t *pos, char *str)
{
	size_t	tmp;

	if (ft_strlen(str) <= *pos)
		return ;
	if (str[*pos] == '\n')
	{
		if (*pos)
		{
			tmp = *pos - 1;
			ft_get_beggin_with_curs(str, &tmp);
		}
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
}

void			ft_move_left(size_t *pos, char *str)
{
	if (!*pos)
		return ;
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
