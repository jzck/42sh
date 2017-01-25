/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_parsing_toolz.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:09:39 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/25 14:41:29 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_nget_histo(size_t nb_his)
{
	t_list_history	*list;
	size_t			i;

	i = 0;
	list = data_singleton()->line.list_beg;
	if (!list)
		return (NULL);
	if (!list->str)
		list = list->prev;
	while (i < nb_his && list->str)
	{
		list = list->prev;
		++i;
	}
	return (list->str);
}

void		ft_realloc_str_history(char **str, size_t pos, int nb_his, int len)
{
	char	*new_str;
	char	*new_str2;
	char	*new_str3;

	if (!*str)
		return ;
	new_str = ft_strndup(*str, pos);
	ft_printf("\n\npos = %d\n\n", len);
	new_str3 = ft_nget_histo(nb_his);
	if (new_str3)
	{
		new_str2 = ft_strjoin(new_str, new_str3);
		free(new_str);
		new_str3 = ft_strjoin(new_str2, (*str) + pos + len);
		free(new_str2);
	}
	else
		new_str3 = ft_strjoin(new_str, (*str) + pos + len);
	free(*str);
	*str = new_str3;
}

static char	*ft_strget_histo(char *str)
{
	t_list_history	*list;

	list = data_singleton()->line.list_beg;
	if (!list)
		return (NULL);
	if (!list->str)
		list = list->prev;
	while (list->str && ft_strncmp(list->str, str, ft_strlen(str)))
		list = list->prev;
	return (list->str);
}

void		ft_realloc_str_history_2(char **str, size_t pos, char *s)
{
	char	*new_str;
	char	*new_str2;
	char	*new_str3;

	if (!*str)
		return ;
	new_str = ft_strndup(*str, pos);
	new_str3 = ft_strget_histo(s);
	if (new_str3)
	{
		new_str2 = ft_strjoin(new_str, new_str3);
		free(new_str);
		new_str3 = ft_strjoin(new_str2, (*str) + pos + ft_strlen(s) + 1);
		free(new_str2);
	}
	else
		new_str3 = ft_strjoin(new_str, (*str) + pos + ft_strlen(s) + 1);
	free(s);
	free(*str);
	*str = new_str3;
}
