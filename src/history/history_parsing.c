/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:39:47 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/18 15:04:16 by gwojda           ###   ########.fr       */
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
	else if (str[*i + 1] == '-' && ft_isdigit(str[*i + 2]) &&
								(size_t)ft_atoi(str + (*i) + 2) < ft_hist_len())
	{
		tmp = ft_nbr_len(ft_atoi(str + *i + 2));
		ft_realloc_str_history(&(data_singleton()->line.input), *i,
				ft_atoi(str + (*i) + 2), ft_nbr_len(ft_atoi(str + *i + 2)) + 2);
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
	else if (ft_isdigit(str[(*i) + 1]) && (size_t)ft_atoi(str + (*i) + 1) <
																ft_hist_len())
	{
		tmp = ft_nbr_len(ft_atoi(str + *i + 1));
		ft_realloc_str_history(&(data_singleton()->line.input), *i,
				data_singleton()->line.list_size - ft_atoi(str + *i + 1),
				ft_nbr_len(ft_atoi(str + *i + 1)) + 1);
		i += tmp;
	}
	else if (str[*i + 1] == '?')
		ft_realloc_str_history_3(&(data_singleton()->line.input), *i,
				ft_strdupi_w(str + *i + 2));
	else if (str[*i + 1] && str[*i + 1] != ' ')
		ft_realloc_str_history_2(&(data_singleton()->line.input), *i,
				ft_strdupi_w(str + *i + 1));
	else
		return (0);
	return (1);
}

static int	ft_history_parsing_2(int has_prompt, char **input)
{
	data_singleton()->line.pos = 0;
	has_prompt ? ft_prompt() : ft_putstr("> ");
	if (ft_read_stdin(input) < 0)
		return (-1);
	if (data_singleton()->line.input)
		ft_current_str(data_singleton()->line.input,
													data_singleton()->line.pos);
	ft_putchar('\n');
	ft_history_parsing(has_prompt, input);
	return (0);
}

int			ft_history_parsing(int has_prompt, char **input)
{
	int		i;
	char	boolean;

	i = 0;
	boolean = 0;
	if (!data_singleton()->line.input)
		return (0);
	while (data_singleton()->line.input && data_singleton()->line.input[i])
	{
		if (data_singleton()->line.input[i] == '!')
		{
			boolean = 1;
			if (!ft_history_parsing_3(data_singleton()->line.input, &i))
				boolean = 0;
			else
				break ;
		}
		++i;
	}
	if (boolean && ft_history_parsing_2(has_prompt, input))
		return (-1);
	return (0);
}
