/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:41:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/22 18:15:48 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_free(void *content, size_t content_size)
{
	t_process	*p;

	p = content;
	(void)content_size;
	if (p->map.free)
		(p->map.free)(p);
	ft_lstdel(&p->redirs, redir_free);
	if (content_size)
		free(p);
}
