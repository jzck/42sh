/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qstate_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:56:40 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 15:36:24 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	qstate_update(t_data *data, char c)
{
	t_qstate	*state;
	t_qstate	*new;
	t_list		**list;
	t_list		*tmp;

	list = &data->line.qstack;
	state = (*list)->content;
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
		qstate_none(new, c);
	else if (*state == Q_QUOTE)
		qstate_quote(new, c);
	else if (*state == Q_DQUOTE)
		qstate_dquote(new, c);
	else if (*state == Q_BACKSLASH)
		*new = *(t_qstate*)(*list)->next->next->content;
}
