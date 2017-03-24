/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:02:58 by ariard            #+#    #+#             */
/*   Updated: 2017/03/24 15:54:27 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			*redir_copy(void *data)
{
	t_redir		*old;
	t_redir		*new;

	if (!data)
		return (NULL);
	DG();
	old = data;
	new = (t_redir *)ft_memalloc(sizeof(t_redir));
	new->type = old->type;
	new->n = old->n;
	new->word = ft_strdup(old->word);
	new->heredoc_data = ft_strdup(old->heredoc_data);
	return (new);
}
