/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_parsing_toolz_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 20:04:16 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/22 11:56:47 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_strget_history(char *str)
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
		new_str3 = ft_strjoin(new_str2, (*str) + pos + ft_strlen(s) + 2);
		free(new_str2);
	}
	free(new_str);
	ft_strdel(str);
	*str = new_str3;
	free(s);
}
