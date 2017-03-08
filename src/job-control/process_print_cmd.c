/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_print_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:17:16 by wescande          #+#    #+#             */
/*   Updated: 2017/03/08 16:20:11 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		process_print_cmd(t_process *p)
{
	ft_sstrprint(p->data.cmd.av, ' ');
}
