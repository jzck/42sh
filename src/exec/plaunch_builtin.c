/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:48:24 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 18:10:21 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		plaunch_builtin(t_process *p)
{
	return (*p->data.cmd.execf)(
				p->data.cmd.path,
				p->data.cmd.av,
				data_singleton()->env);
}
