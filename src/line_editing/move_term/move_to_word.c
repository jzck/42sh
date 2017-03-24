/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 11:12:09 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/24 12:12:11 by gwojda           ###   ########.fr       */
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
	(*pos) -= ((ft_nb_last_line(str, *pos) == 0) ? 1 : 0);
}

int			ft_found_prev_word(char **str, size_t *pos)
{
	int		i;

	i = 0;
	if (!*pos || !*str)
		return (0);
	ft_init_prev_word(pos, *str);
	if (*pos >= 1 && (*str)[*pos - 1] == '\n')
	{
		if (*pos - 1 == 0)
		{
			ft_puttermcaps("cd");
			--(*pos);
			return (0);
		}
		ft_puttermcaps("cd");
		*pos -= 2;
		ft_get_beggin(*str, pos);
		(!*pos && (*str)[*pos] == '\n') ? ++(*pos) : 0;
		ft_current_str(*str, *pos);
		ft_get_next_str(*str, pos);
		++(*pos);
	}
	else
		ft_found_prev_word_2(i, *str, pos);
	return (0);
}

static void	ft_found_next_word_2(char **str, size_t *pos)
{
	if (*pos)
	{
		--(*pos);
		ft_get_beggin_with_curs(*str, pos);
	}
	ft_puttermcaps("cd");
	ft_get_next_str(*str, pos);
	*pos += (*pos || (*str)[0] != '\n') ? 2 : 1;
	ft_current_str(*str, *pos);
	ft_get_next_str(*str, pos);
	if (!(*str)[*pos])
		--(*pos);
	ft_get_beggin_with_curs(*str, pos);
}

int			ft_found_next_word(char **str, size_t *pos)
{
	int		i;

	i = 0;
	if (!*str)
		return (0);
	while ((*str)[i + *pos] && (*str)[i + *pos] == ' ')
	{
		ft_putchar((*str)[i + *pos]);
		++i;
	}
	if ((*str)[*pos] == '\n')
		ft_found_next_word_2(str, pos);
	else
	{
		while ((*str)[i + *pos] && (*str)[i + *pos] != '\n' &&
													(*str)[i + *pos] != ' ')
		{
			ft_putchar((*str)[i + *pos]);
			++i;
		}
		*pos += i;
	}
	return (0);
}
