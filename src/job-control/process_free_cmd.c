/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_free_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:58:02 by wescande          #+#    #+#             */
/*   Updated: 2017/03/08 02:31:01 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		process_free_cmd(t_process *p)
{
	ft_strdel(&p->data.cmd.path);
	ft_sstrfree(p->data.cmd.av);
	return (0);
}
