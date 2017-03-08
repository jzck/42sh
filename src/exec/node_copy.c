/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:44:42 by wescande          #+#    #+#             */
/*   Updated: 2017/03/08 01:00:05 by ariard           ###   ########.fr       */
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
	ft_bzero((void *)&new, sizeof(t_astdata));
	new->nest = old->nest;
	new->full = old->full;
	new->type = old->type;
	new->pattern = old->pattern;
	if (old->type == CMD || old->type == TK_ASSIGNEMENT_WORD)
	{		
		new->data.cmd.redir = ft_lstdup(&old->data.cmd.redir, &redir_copy);
		new->data.cmd.token = ft_ld_copy(old->data.cmd.token, &tab_esc_copy);
	}
	if (old->type == TK_FOR || old->type == TK_PAREN_OPEN || old->type == TK_CASE)
  		new->data.cmd.wordlist = ft_ld_copy(old->data.cmd.token, &tab_esc_copy);
	return (new);
}
