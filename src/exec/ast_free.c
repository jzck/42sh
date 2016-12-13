/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:50:51 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 17:17:38 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ast_free(void *data, size_t content_size)
{
	t_astnode	*node;

	(void)content_size;
	node = data;
	DG("gonna free a node");
	if (node->type == TK_COMMAND)
	{
		DG("ast_free TK_COMMAND");
		if (node->data.sstr)
			ft_sstrfree(node->data.sstr);
	}
	else if (node->type == TK_LESS || node->type == TK_GREAT || node->type == TK_DGREAT)
	{
		DG("ast_free TK_REDIR %p", node->data.redir.word.word);
		ft_strdel(&node->data.redir.word.word);
	}
	DG("ast_free done");
}
