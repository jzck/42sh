/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 19:02:23 by wescande          #+#    #+#             */
/*   Updated: 2017/03/20 18:15:17 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				plaunch_case(t_process *p)
{
	t_exec	*exec;

	exec = &data_singleton()->exec;
	exec->attrs &= ~EXEC_CASE_BRANCH;
	exec->case_pattern = token_to_argv(p->data.d_case.token, 1);
	ft_exec(&p->data.d_if.content);
	return (0);
}
