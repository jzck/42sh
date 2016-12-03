/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qstate_none.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:08:48 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 12:51:29 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

void	qstate_none(t_qstate *new, char c)
{
	if (c == '\\')
		*new = Q_BACKSLASH;
	else if (c == '\"')
		*new = Q_DQUOTE;
	else if (c == '\'')
		*new = Q_QUOTE;
}
