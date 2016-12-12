/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ampersand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:01:30 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/12 18:03:03 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_ampersand(t_btree **ast)
{
	data_singleton()->exec.amp = 1;
	ft_exec(&(*ast)->left);
	data_singleton()->exec.amp = 0;
	ft_exec(&(*ast)->right);
	btree_delone(ast, &ast_free);
	return (0);
}
