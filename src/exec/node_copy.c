/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 03:38:36 by wescande          #+#    #+#             */
/*   Updated: 2017/03/20 16:28:33 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		*node_copy(void *data)
{
	t_astnode	*new;
	t_astnode	*old;

	if (!data)
		return (NULL);
	old = data;
	new = (t_astnode *)ft_memalloc(sizeof(t_astnode));
	new->nest = old->nest;
	new->full = old->full;
	new->type = old->type;
	new->pattern = old->pattern;
	if (old->type == CMD || old->type == TK_ASSIGNMENT_WORD)
	{
		new->data.cmd.redir = ft_lstmap(old->data.cmd.redir, &redir_copy);
		new->data.cmd.token = ft_ld_copy(old->data.cmd.token, &tab_esc_copy);
	}
	if (old->type == TK_FOR || old->type == TK_PAREN_OPEN
		|| old->type == TK_CASE || old->type == FNAME)
		new->data.cmd.token = ft_ld_copy(old->data.cmd.token, &tab_esc_copy);
	return (new);
}
