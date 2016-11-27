/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:28:14 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/27 23:46:57 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_command(t_btree *ast, t_data *data)
{
	t_astnode	*node;

	node = ast->item;
	ft_putstr_fd("befor exec: ", 2);
	ft_sstrprint(((t_astnode*)ast->item)->u_data.sstr, ',');
	ft_putchar('\n');
	ft_cmd_process(node->u_data.sstr, &data->env);
	ft_putstr_fd("after exec\n", 2);
	return (0);
}
