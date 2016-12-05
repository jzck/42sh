/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:50:51 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/05 12:07:38 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ast_free(void *data, size_t content_size)
{
	t_astnode	*node;

	(void)content_size;
	node = data;
	if (node->type == TK_COMMAND)
	{
		if (node->data.sstr)
			ft_sstrfree(node->data.sstr);
	}
	else if (node->type == TK_LESS || node->type == TK_GREAT || node->type == TK_DGREAT)
	{
		ft_printf("gonna del word of redirection at %p\n", node->data.redir.word.word);
		ft_strdel(&node->data.redir.word.word);
	}
}
