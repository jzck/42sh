/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:12:57 by ariard            #+#    #+#             */
/*   Updated: 2017/03/20 12:21:21 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		redir_free(void *data, size_t content_size)
{
	t_redir *redir;

	(void)content_size;
	redir = data;
	ft_strdel(&redir->word);
	if (redir->type == TK_DLESS)
		ft_strdel(&redir->heredoc_data);
	redir->type = 0;
	redir->n = 0;	
	free(redir);
}
