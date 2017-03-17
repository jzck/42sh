/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 03:23:59 by wescande          #+#    #+#             */
/*   Updated: 2017/03/17 20:29:36 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				plaunch_function(t_process *p)
{
	DG("do function");
	ft_exec(&p->data.function.content);
	return (ft_atoi(ft_getenv(data_singleton()->env, "?")));
}
