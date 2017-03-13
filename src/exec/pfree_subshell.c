/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfree_subshell.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 02:38:12 by wescande          #+#    #+#             */
/*   Updated: 2017/03/13 22:31:26 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		pfree_subshell(t_process *p)
{
	btree_del(&p->data.subshell.content, &ast_free);
	return (0);
}
