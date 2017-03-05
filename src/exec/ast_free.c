/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:50:51 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/05 16:50:06 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	read_redir(void *data)
{
	t_redir		*redir;

	redir = data;
	DG("file : [%s]", redir->word.word);
}

void	ast_free(void *data, size_t content_size)
{
	t_astnode	*node;

	(void)content_size;
	node = data;
  	if (node->type == CMD)
	{
		ft_ld_clear(&node->data.cmd.token, &ft_tabdel);
//		ft_lstdel(&node->data.cmd.redir, &redir_free);
	}
//	if (node->type == WORDLIST)
//		do clear
}
