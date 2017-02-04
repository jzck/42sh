/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_touch_toolz.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:42:54 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/04 15:17:19 by gwojda           ###   ########.fr       */
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

void		ft_found_prev_word(void)
{
	int		i;
	char	*str;
	size_t	*pos;

	i = 0;
	str = STR;
	pos = &POS;
	if (!*pos || !str)
		return ;
	ft_init_prev_word(pos, str);
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
		ft_found_prev_word_2(i, str, pos);
}

static void	ft_found_next_word_2(void)
{
	char	*str;
	size_t	*pos;

	str = STR;
	pos = &POS;
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

void		ft_found_next_word(void)
{
	int		i;
	char	*str;
	size_t	*pos;

	i = 0;
	str = STR;
	pos = &POS;
	if (!str)
		return ;
	while (str[i + *pos] && str[i + *pos] == ' ')
	{
		ft_putchar(str[i + *pos]);
		++i;
	}
	if (str[*pos] == '\n')
		ft_found_next_word_2();
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
