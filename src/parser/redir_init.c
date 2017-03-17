/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:46:50 by ariard            #+#    #+#             */
/*   Updated: 2017/03/17 17:49:10 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		redir_init(t_type type, t_redir *redir)
{
	redir->n = (type == TK_LESS || type == TK_DLESS
	|| type == TK_LESSAND) ? STDIN : STDOUT;
	redir->type = type;
	redir->heredoc_data = NULL;
	redir->word = NULL;
	return (0);
}
