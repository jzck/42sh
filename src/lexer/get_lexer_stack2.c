/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lexer_stack2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:15:46 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/23 16:12:26 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_lexer_stack2(t_lexer lexer)
{
	if (!(lexer.stack && lexer.stack->next))
		return (0);
	return (*(int*)lexer.stack->next->content);
}
