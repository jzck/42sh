/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_if.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:26:53 by wescande          #+#    #+#             */
/*   Updated: 2017/03/17 20:30:36 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				plaunch_if(t_process *p)
{
	data_singleton()->exec.attrs &= ~EXEC_IF_BRANCH;
	ft_exec(&p->data.d_if.content);
	return (ft_atoi(ft_getenv(data_singleton()->env, "?")));
}
