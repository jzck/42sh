/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qstate_dquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:10:09 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 12:26:09 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

void	qstate_dquote(t_qstate *new, char c)
{
	if (c == '\\')
		*new = Q_BACKSLASH;
	else if (c == '\"')
		*new = Q_NONE;
}
