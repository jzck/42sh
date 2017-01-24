/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_brace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:00:29 by wescande          #+#    #+#             */
/*   Updated: 2017/01/24 19:15:35 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

/*
** expand_brace return expansion of a string.
** pattern searched are {ab, cd}.
** return is t_ld which first param is ab and second is cd
** input parameters are :
**			-char	*pat  -> pattern string to be looking for expand
*/

static int		search_brace(t_ld **wk, char *str, int index)
{
	char	*start;
	char	*s1;
	char	**split;

	start = NULL;
	while (*str)
	{
		if (*str == '{')
			start = str;
		else if (*str == '}' && start)
		{
			s1 = ft_strsub(start, 1, str - start - 1);
			split = ft_strsplit(s1, ',');
			ft_strdel(&s1);
			s1 = ft_strsub((*wk)->content, 0, start - (char *)(*wk)->content);
			while (split[++index])
				ft_ld_pushfront(wk, ft_strjoinf(ft_strjoin(s1, split[index]),
					str + 1, 1));
			ft_strdel(&s1);
			ft_tabdel(&split);
			return (1);
		}
		++str;
	}
	return (0);
}

t_ld			*expand_brace(const char *pat)
{
	t_ld	*ret;
	t_ld	*tmp;
	int		do_it;

	ret = NULL;
	ft_ld_pushfront(&ret, ft_strdup(""));
	ft_ld_pushfront(&ret, ft_strdup(pat));
	do_it = 1;
	while (do_it)
	{
		do_it = 0;
		while (ret->next)
		{
			if ((tmp = ret) && search_brace(&ret, ret->content, -1))
			{
				ft_ld_del(&tmp, &ft_strdel);
				do_it = 1;
			}
			ret = ret->next;
		}
		ret = ft_ld_front(ret);
	}
	return (ret);
}
