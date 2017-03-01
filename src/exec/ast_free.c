/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:50:51 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/01 16:36:20 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ast_free(void *data, size_t content_size)
{
	t_astnode	*node;

	(void)node;
	(void)data;
	(void)content_size;
/*
	(void)content_size;
	node = data;
	if (node->type == TK_COMMAND)
		ft_ld_clear(&node->data.cmd.token, &ft_tabdel);
	else if (node->type == TK_SUBSHELL)
	{
		ft_sstrfree(node->data.sstr);
		node->data.sstr = NULL;
	}
	else if (node->type == TK_LESS || node->type == TK_GREAT || node->type == TK_DGREAT)
	{
		ft_strdel(&node->data.cmd.redir.word.word);
	}
*/
}
