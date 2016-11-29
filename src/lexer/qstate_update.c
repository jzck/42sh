/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qstate_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:56:11 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/29 15:38:51 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	qstate_update(t_data *data, char c)
{
	t_qstate	*state;
	t_qstate	*new;
	t_list		**list;
	t_list		*tmp;

	list = &data->qstack;
	state = (*list)->content;
	/* ft_printf("befor state: %i\n", *state); */
	if (c == -1)
	{
		tmp = ft_lstpop(list);
		ft_lstdelone(&tmp, &ft_lst_cfree);
		return ;
	}
	ft_lstadd(list, ft_lstnew(NULL, sizeof(t_qstate)));
	new = (*list)->content;
	*new = *state;
	if (*state == Q_NONE)
	{
		if (c == '\\')
			*new = Q_BACKSLASH;
		else if (c == '\"')
			*new = Q_DQUOTE;
		else if (c == '\'')
			*new = Q_QUOTE;
	}
	else if (*state == Q_QUOTE)
	{
		if (c == '\'')
			*new = Q_NONE;
	}
	else if (*state == Q_DQUOTE)
	{
		if (c == '\\')
			*new = Q_BACKSLASH;
		else if (c == '\"')
			*new = Q_NONE;
	}
	else if (*state == Q_BACKSLASH)
		*new = *(t_qstate*)(*list)->next->next->content;
	/* ft_printf("new  state: %i\n", *new); */
}
