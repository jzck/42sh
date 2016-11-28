/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:27:08 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/28 18:19:26 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_less(t_btree *ast, t_data *data)
{
	t_astnode	*node;
	int			fd;

	node = ast->item;
	fd = open(node->u_data.redir.u_word.word, O_RDONLY);
	dup2(fd, node->u_data.redir.n);
	close(fd);

	return (ft_exec(ast->left, data));
}
