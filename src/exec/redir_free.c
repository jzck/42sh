/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:12:57 by ariard            #+#    #+#             */
/*   Updated: 2017/03/08 12:40:34 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		redir_free(void *data, size_t content_size)
{
	t_redir *redir;

	(void)content_size;
	redir = data;
	if (redir->type == TK_GREAT || redir->type == TK_LESS || redir->type == TK_DGREAT)
	{
		ft_strdel(&redir->word);
	}
	free(redir);
}
