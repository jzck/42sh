/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:52:34 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/02 16:09:42 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_get_next_word(char *str)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (str[j] && str[j] == ' ')
		++j;
	while (str[j + k] && str[j + k] != ' ')
		++k;
	return (ft_strndup(str + j, k));
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
				end = ft_get_next_word(*str + i + 2);
			else
				return ;
		}
		++i;
	}
	if (!end)
		return ;
	ft_check_heredoc_2(str, end);
}
