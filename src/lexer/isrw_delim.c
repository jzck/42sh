/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istoken.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:54:23 by ariard            #+#    #+#             */
/*   Updated: 2017/03/20 16:38:43 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			isrw_delim(t_type type) 	
{
	return (type == TK_NEWLINE || type == TK_AMP
		|| type == TK_SEMI || type == TK_PIPE
		|| type == TK_WHILE || type == TK_UNTIL 
		|| type == TK_DONE || type == TK_RBRACE
		|| type == TK_DO || type == TK_IF
		|| type == TK_FI || type == TK_THEN
		|| type == TK_ELIF || type == TK_ELSE
		|| type == TK_DSEMI || type == TK_PAREN_CLOSE
		|| type == TK_PAREN_OPEN || type == TK_LBRACE
		|| type == 0);
}
