/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_and_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:52:28 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/30 21:06:05 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_and_if(t_btree *ast, t_data *data)
{
	ft_exec(ast->left, data);
	ft_exec(ast->right, data);
	return (0);
}
