/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 21:25:26 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/09 22:49:51 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*stack_to_prompt(t_list	*stack)
{
	t_flag		top;

	if (!stack)
		return (NULL);
	top = *(int*)stack->content;
	if (top == BACKSLASH)
		return ("> ");
	else if (top == QUOTE)
		return ("quote> ");
	else if (top == DQUOTE)
		return ("dquote> ");
	else if (top == BQUOTE)
		return ("bquote> ");
	else if (top == DQUOTE_BQUOTE)
		return ("dquote bquote> ");
	else if (top == PAREN)
		return ("subsh> ");
	else
		return ("error> ");
}
