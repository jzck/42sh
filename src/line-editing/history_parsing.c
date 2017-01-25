/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:39:47 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/25 15:05:04 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_strget_history(char *str)
{
	t_list_history	*list;
	size_t			i;
	char			*tmp;

	list = data_singleton()->line.list_beg;
	if (!list)
		return (NULL);
	if (!list->str)
		list = list->prev;
	while (list->str)
	{
		tmp = list->str;
		i = 0;
		while (tmp[i])
		{
			if (ft_strlen(tmp + i) >= ft_strlen(str)
			&& !ft_strncmp(tmp + i, str, ft_strlen(str)))
				return (tmp);
			++i;
		}
		list = list->prev;
	}
	return (list->str);
}

void		ft_realloc_str_history_3(char **str, size_t pos, char *s)
{
	char	*new_str;
	char	*new_str2;
	char	*new_str3;

	if (!*str)
		return ;
	new_str = ft_strndup(*str, pos);
	new_str3 = ft_strget_history(s);
	if (new_str3)
	{
		new_str2 = ft_strjoin(new_str, new_str3);
		free(new_str);
		new_str3 = ft_strjoin(new_str2, (*str) + pos + ft_strlen(s) + 2);
		free(new_str2);
	}
	else
		new_str3 = ft_strjoin(new_str, (*str) + pos + ft_strlen(s) + 2);
	free(s);
	free(*str);
	*str = new_str3;
}

void	ft_history_parsing()
{
	char	*str;
	int		i;
	char	boolean;

	i = 0;
	boolean = 0;
	str = data_singleton()->line.input;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == '!')
		{
			boolean = 1;
			if (!ft_strncmp("!!", str + i, 2))
			{
				ft_realloc_str_history(&(data_singleton()->line.input), i, 0, 2);
				++i;
			}
			else if (ft_isdigit(str[i + 1]))
			{
				ft_realloc_str_history(&(data_singleton()->line.input), i,
				ft_atoi(str + i + 1), ft_nbr_len(ft_atoi(str + i + 1)) + 1);
				i += ft_nbr_len(ft_atoi(str + i + 1));
			}
			else if (str[i + 1] == '-')
			{
				ft_realloc_str_history(&(data_singleton()->line.input), i,
				data_singleton()->line.list_size - ft_atoi(str + i + 2),
				ft_nbr_len(ft_atoi(str + i + 2)) + 2);
				i += ft_nbr_len(ft_atoi(str + i + 2) + 1);
			}
			else if (str[i + 1] == '?')
				ft_realloc_str_history_3(&(data_singleton()->line.input), i,
				ft_strdupi_w(str + i + 2));
			else if (str[i + 1] != ' ')
				ft_realloc_str_history_2(&(data_singleton()->line.input), i,
				ft_strdupi_w(str + i + 1));
			else
				boolean = 0;
		}
		++i;
	}
	if (boolean)
	{
		data_singleton()->line.opt = data_singleton()->line.opt | HIST;
		ft_prompt();
		data_singleton()->line.input = ft_lecture(data_singleton()->line.list_beg);
		ft_putchar('\n');
		data_singleton()->line.opt = data_singleton()->line.opt | ~HIST;
		ft_check_quotes(&data_singleton()->line.input, data_singleton()->line.list_beg);
		ft_check_heredoc(&data_singleton()->line.input);
		ft_history_parsing();
	}
}
