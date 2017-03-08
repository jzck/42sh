/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_free_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:58:02 by wescande          #+#    #+#             */
/*   Updated: 2017/03/08 15:04:45 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		process_free_cmd(t_process *p)
{
	ft_strdel(&p->data.cmd.path);
	ft_sstrfree(p->data.cmd.av);
	p->data.cmd.execf = NULL;
	ft_memdel((void**)&p->data.cmd.stat);
	return (0);
}
