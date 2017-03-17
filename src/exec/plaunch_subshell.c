/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_subshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:11:44 by wescande          #+#    #+#             */
/*   Updated: 2017/03/17 20:28:08 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				plaunch_subshell(t_process *p)
{
	ft_exec(&p->data.subshell.content);
	exit(ft_atoi(ft_getenv(data_singleton()->env, "?")));
}
