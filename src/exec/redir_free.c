/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:12:57 by ariard            #+#    #+#             */
/*   Updated: 2017/03/05 15:58:13 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void		redir_free(void *data, size_t content_size)
{
	t_redir *redir;

	(void)content_size;
	redir = data;
	if (redir->type == TK_GREAT || redir->type == TK_LESS || redir->type == TK_DGREAT)
	{
		/* DG("word.word: %s", redir->word.word); */
		ft_strdel(&redir->word.word);
	}
	/* else */
	/* 	redir->word.fd = 0; */
	/* redir->type = 0; */
	/* redir->n = 0; */
	/* redir->close = 1; */
	free(redir);
}
