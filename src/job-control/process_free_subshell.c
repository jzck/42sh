/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_free_subshell.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 02:38:12 by wescande          #+#    #+#             */
/*   Updated: 2017/03/08 02:38:27 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		process_free_subshell(t_process *p)
{
	btree_del(&p->data.d_while.content, &ast_free);
	return (0);
}
