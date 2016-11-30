/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_or_if.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:06:17 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/30 21:45:53 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_or_if(t_btree *ast, t_data *data)
{
	ft_exec(ast->left, data);
	ft_exec(ast->right, data);
	return (0);
}
