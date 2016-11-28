/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qstate_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:56:11 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/28 19:27:44 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	qstate_update(t_data *data, char c)
{
	t_qstate	*state;
	t_list		**list;
	t_list		*tmp;

	list = &data->qstack;
	state = (*list)->content;
	ft_lstadd(list, ft_lstnew(NULL, sizeof(t_qstate)));
	if (c == -1)
	{
		tmp = ft_lstpop(list);
		ft_lstdelone(&tmp, &ft_lst_cfree);
		return ;
	}
	else if (*state == Q_NONE)
	{
		if (c == '\\')
			*state = Q_BACKSLASH;
		else if (c == '\"')
			*state = Q_DQUOTE;
		else if (c == '\'')
			*state = Q_QUOTE;
	}
	else if (*state == Q_QUOTE)
	{
		if (c == '\'')
			*state = Q_NONE;
	}
	else if (*state == Q_DQUOTE)
	{
		if (c == '\\')
			*state = Q_BACKSLASH;
		else if (c == '\"')
			*state = Q_NONE;
	}
	else if (*state == Q_BACKSLASH)
		state = (*list)->next->next->content;
	*((t_qstate *)(*list)->content) = *state;
}
