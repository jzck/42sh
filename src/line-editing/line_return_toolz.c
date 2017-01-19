/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_return_toolz.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:32:12 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/19 16:42:54 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_found_prev_char(char *str, size_t i)
{
	while (i)
	{
		if (str[i] == '\n')
			return (1);
		--i;
	}
	return (0);
}

void		ft_move_dell(char *str, size_t pos)
{
	size_t	i;
	int		count;

	count = 1;
	i = 0;
	while (str[i + pos + 1])
	{
		if (str[i + pos] == '\n')
			++count;
		++i;
	}
	while (i && str[i + pos + 1] != '\n')
	{
		ft_puttermcaps("le");
		--i;
	}
	if (i)
	{
		while (i && count)
		{
			if (str[i + pos + 1] == '\n')
			{
				ft_puttermcaps("up");
				--count;
			}
			--i;
		}
		while (pos && str[pos] != '\n')
		{
			ft_puttermcaps("nd");
			--pos;
		}
	}
}

void		ft_move_suppr(char *str, size_t pos)
{
	size_t	i;
	int		count;
	int		prompt_size;

	prompt_size = data_singleton()->line.prompt_size;
	count = 0;
	i = 0;
	while (str[i + pos])
	{
		if (str[i + pos] == '\n')
			++count;
		++i;
	}
	while (i && str[i + pos] != '\n')
	{
		ft_puttermcaps("le");
		--i;
	}
	if (i)
	{
		while (i && count)
		{
			if (str[i + pos] == '\n')
			{
				ft_puttermcaps("up");
				--count;
			}
			--i;
		}
		if (pos > 2)
			pos -= 2;
		if (!ft_found_prev_char(str, pos))
		{
			while (--prompt_size + 3)
				ft_puttermcaps("nd");
		}
		while (pos && str[pos] != '\n')
		{
			ft_puttermcaps("nd");
			--pos;
		}
	}
}

void		ft_curse_move(char *str)
{
	int		i;
	int		count;
	int		prompt_size;

	prompt_size = data_singleton()->line.prompt_size;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			count += ft_nb_line(str, i - 1);
			count++;
		}
		++i;
	}
	while (i && str[i] != '\n')
	{
		ft_putchar('\b');
		--i;
	}
	if (count)
	{
		while (count)
		{
			ft_puttermcaps("up");
			--count;
		}
		while (--prompt_size + 2)
			ft_puttermcaps("nd");
	}
	ft_puttermcaps("cd");
}
