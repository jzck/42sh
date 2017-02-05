/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:52:34 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/05 12:21:21 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_get_next_word(char *str)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (str[j] && (str[j] == ' ' || str[j] == '\n'))
		++j;
	while (str[j + k] && str[j + k] != ' ' && str[j + k] != '\n')
		++k;
	return (ft_strndup(str + j, k));
}

static void	ft_after_retline(char *str, int *i)
{
	while (str[*i] && str[*i] != '\n')
		++(*i);
	if (str[*i] == '\n')
		++(*i);
}

static int	ft_is_keyword(char *str, char *end)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		ft_after_retline(str, &i);
		j = 0;
		while (str[i + j] && str[i + j] != '\n')
			++j;
		if (str[i] && ft_strncmp(str + i, end, j) == 0)
			return (0);
	}
	return (1);
}

static void	ft_check_heredoc_2(char **str, char *end)
{
	char	boolean;
	char	*tmp;
	char	*tmp2;

	boolean = 0;
	while (!boolean)
	{
		ft_putstr("heredoc> ");
		data_singleton()->line.prompt_size = 9;
		tmp = *str;
		*str = ft_strjoin(*str, "\n");
		free(tmp);
		tmp = *str;
		data_singleton()->line.input = NULL;
		data_singleton()->line.pos = 0;
		tmp2 = ft_read_stdin();
		if (!ft_strcmp(end, tmp2))
			boolean = 1;
		*str = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
		ft_putchar('\n');
	}
}

void		ft_check_heredoc(char **str)
{
	int		i;
	char	*end;

	i = 0;
	end = NULL;
	if (!*str)
		return ;
	while ((*str)[i])
	{
		if ((*str)[i] == '<' && !ft_strncmp(*str + i, "<<", 2))
		{
			if ((*str)[i + 1] == '<' && (*str)[i + 2])
			{
				end = ft_get_next_word(*str + i + 2);
				if (ft_is_keyword(*str, end))
					ft_check_heredoc_2(str, end);
				free(end);
			}
			else
				return ;
		}
		++i;
	}
	if (!end)
		return ;
}
