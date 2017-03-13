/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfree_cond.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 02:26:31 by wescande          #+#    #+#             */
/*   Updated: 2017/03/13 22:31:32 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		pfree_cond(t_process *p)
{
	btree_del(&p->data.d_while.condition, &ast_free);
	btree_del(&p->data.d_while.content, &ast_free);
	return (0);
}