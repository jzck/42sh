/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:39:47 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/14 15:15:16 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_history_parsing_4(char *str, int *i)
{
	int tmp;

	if (!ft_strncmp("!!", str + *i, 2))
	{
		ft_realloc_str_history(&(data_singleton()->line.input), *i, 0, 2);
		++(*i);
		return (1);
	}
	else if (ft_isdigit(str[(*i) + 1]))
	{
		tmp = ft_nbr_len(ft_atoi(str + *i + 1));
		ft_realloc_str_history(&(data_singleton()->line.input), *i,
				ft_atoi(str + (*i) + 1), ft_nbr_len(ft_atoi(str + *i + 1)) + 1);
		(*i) += tmp;
		return (1);
	}
	return (0);
}

static int	ft_history_parsing_3(char *str, int *i)
{
	int tmp;

	if (ft_history_parsing_4(str, i))
		return (1);
	else if (str[*i + 1] == '-' && ft_isdigit(str[*i + 2]))
	{
		tmp = ft_nbr_len(ft_atoi(str + *i + 2));
		ft_realloc_str_history(&(data_singleton()->line.input), *i,
				data_singleton()->line.list_size - ft_atoi(str + *i + 2),
				ft_nbr_len(ft_atoi(str + *i + 2)) + 2);
		i += tmp;
	}
	else if (str[*i + 1] == '?')
		ft_realloc_str_history_3(&(data_singleton()->line.input), *i,
				ft_strdupi_w(str + *i + 2));
	else if (str[*i + 1] != ' ')
		ft_realloc_str_history_2(&(data_singleton()->line.input), *i,
				ft_strdupi_w(str + *i + 1));
	else
		return (0);
	return (1);
}

static void	ft_history_parsing_2(void)
{
	data_singleton()->line.pos = 0;
	data_singleton()->line.opt = data_singleton()->line.opt | HIST;
	ft_prompt();
	data_singleton()->line.input = ft_read_stdin();
	ft_putchar('\n');
	data_singleton()->line.opt = data_singleton()->line.opt | ~HIST;
	ft_check_heredoc(&data_singleton()->line.input);
	ft_history_parsing();
}

char		*ft_history_parsing(void)
{
	int		i;
	char	boolean;

	i = 0;
	boolean = 0;
	if (!STR)
		return (STR);
	while (STR && STR[i])
	{
		if (STR[i] == '!')
		{
			boolean = 1;
			if (!ft_history_parsing_3(STR, &i))
				boolean = 0;
		}
		STR = data_singleton()->line.input;
		++i;
	}
	if (boolean)
		ft_history_parsing_2();
	return (STR);
}
