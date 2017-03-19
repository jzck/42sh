/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_and_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:21:40 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/17 11:44:08 by gwojda           ###   ########.fr       */
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

int			ft_up(char **str, size_t *pos)
{
	if (!*str || !*pos)
		return (0);
	if ((*str)[*pos - 1] == '\n')
	{
		ft_puttermcaps("cd");
		if (*pos >= 2)
			*pos -= 2;
		ft_get_beggin(*str, pos);
		ft_current_str(*str, *pos);
		ft_get_next_str(*str, pos);
		++(*pos);
	}
	else
		ft_up_2(pos, *str);
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

int			ft_down(char **str, size_t *pos)
{
	int		i;
	int		len;

	i = 0;
	if (!*str)
		return (0);
	if ((*str)[*pos] == '\n')
		ft_down_2(pos, *str);
	else
	{
		len = ft_size_term();
		while ((*str)[i + *pos] && (*str)[i + *pos] != '\n' && --len + 1)
		{
			ft_putchar((*str)[i + *pos]);
			++i;
		}
		*pos += i;
	}
	return (0);
}
