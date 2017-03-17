/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:48:24 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/17 20:22:12 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		plaunch_builtin(t_process *p)
{
	return ((*p->data.cmd.execf)(
				p->data.cmd.path,
				p->data.cmd.av,
				data_singleton()->env));
}
