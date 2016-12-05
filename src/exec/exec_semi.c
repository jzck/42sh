/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_semi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:52:05 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/05 12:14:37 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_semi(t_btree **ast, t_data *data)
{
	ft_exec(&(*ast)->left, data);
	ft_exec(&(*ast)->right, data);
	btree_delone(ast, &ast_free);
	return (0);
}
