/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:02:58 by ariard            #+#    #+#             */
/*   Updated: 2017/03/08 00:41:57 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			*redir_copy(void *data)
{
	t_redir		*old;
	t_redir		*new;	

	if (!data)
		return (NULL);
	old = data;
	ft_bzero((void *)&new, sizeof(t_astdata));
	new->type = old->type;
	new->n = old->n;
	new->word = ft_strdup(old->word);
	return (0);
}	
