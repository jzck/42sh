/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_touch_toolz.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:42:54 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/03 12:08:45 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_found_prev_word(void)
{
	int i;
	char	*str;
	size_t	*pos;

	str = data_singleton()->line.input;
	pos = &data_singleton()->line.pos;
	i = 0;
	if (!*pos)
		return ;
	if (str[*pos - 1] != '\n' && !(str[*pos] == '\n' || str[*pos] == ' '))
	{
		ft_puttermcaps("le");
		--(*pos);
	}
	while ((int)*pos - i  - 1 > 0 && str[*pos - i - 1] == ' ')
	{
		ft_puttermcaps("le");
		++i;
	}
	(*pos) = (i && str[*pos - i] == '\n') ? *pos - i + 1 : *pos - i;
	i = 0;
	if (*pos >= 1 && str[*pos - 1] == '\n')
	{
		ft_puttermcaps("cd");
		if (*pos >= 2)
			(*pos) -= 2;
		ft_get_beggin(str, pos);
		ft_current_str(str, *pos);
		ft_get_next_str(str, pos);
		++(*pos);
	}
	else
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
}

void	ft_found_next_word(void)
{
	int		i;
	char	*str;
	size_t	*pos;

	str = data_singleton()->line.input;
	pos = &data_singleton()->line.pos;
	i = 0;
	if (!str)
		return ;
	while (str[i + *pos] && str[i + *pos] == ' ')
	{
		ft_putchar(str[i + *pos]);
		++i;
	}
	if (str[*pos] == '\n')
	{
		if (*pos)
		{
			--(*pos);
			ft_get_beggin_with_curs(str, pos);
		}
		ft_puttermcaps("cd");
		ft_get_next_str(str, pos);
		(*pos) += (*pos) ? 2 : 1;
		ft_current_str(str, *pos);
		ft_get_next_str(str, pos);
		if (!str[*pos])
			--(*pos);
		ft_get_beggin_with_curs(str, pos);
	}
	else
	{
		while (str[i + *pos] && str[i + *pos] != '\n' && str[i + *pos] != ' ')
		{
			ft_putchar(str[i + *pos]);
			++i;
		}
		*pos += i;
	}
}
