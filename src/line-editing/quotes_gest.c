/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_gest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 12:20:19 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/19 16:43:10 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_quotes_num(char *s)
{
	int		i;
	char	simp;
	char	doub;

	i = 0;
	simp = 0;
	doub = 0;
	while (s[i])
	{
		if (s[i] == '\'')
		{
			simp = 1;
			++i;
			while (s[i] && s[i] != '\'')
				++i;
			if (s[i] == '\'')
				simp = 0;
		}
		else if (s[i] == '"')
		{
			doub = 1;
			++i;
			while (s[i] && s[i] != '"')
				++i;
			if (s[i] == '"')
				doub = 0;
		}
		if (s[i])
			++i;
	}
	if (doub)
		return (2);
	else if (simp)
		return (1);
	return (0);
}

void	ft_check_quotes(char **s, t_list_history *head)
{
	int		ret;
	char	*tmp;
	char	*tmp2;
	int		prompt_size_mem;

	if (!*s)
		return ;
	while ((ret = (ft_check_quotes_num(*s))))
	{
		if (ret == 1)
			ft_putstr("squote> ");
		else if (ret == 2)
			ft_putstr("dquote> ");
		tmp = *s;
		*s = ft_strjoin(*s, "\n");
		ft_strdel(&tmp);
		tmp = *s;
		prompt_size_mem = data_singleton()->line.prompt_size;
		tmp2 = ft_lecture(head);
		data_singleton()->line.prompt_size = prompt_size_mem;
		ft_putchar('\n');
		if (!tmp2)
			continue ;
		*s = ft_strjoin(tmp, tmp2);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
}
