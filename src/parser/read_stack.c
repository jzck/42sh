/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:32:10 by ariard            #+#    #+#             */
/*   Updated: 2017/02/10 01:41:47 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char			*read_state(t_sym current)
{
	if (current == CMD_NAME)
		return ("CMD_NAME");
/*	if (current == NEWLINE_LIST)
		return ("NEWLINE_LIST");
	if (current == SYM_DLESS)
		return ("DLESS");
	if (current == SYM_DGREAT)
		return ("DGREAT");
	if (current == SYM_GREATAND)
		return ("GREATAND");
*/	if (current == TK_GREAT)
		return ("GREAT");
	if (current == TK_LESS)
		return ("LESS");
/*	if (current == SYM_LESSAND)
		return ("LESSAND");
	if (current == SYM_LESS)
		return ("LESS");
	if (current == SIMPLE_COMMAND)
		return ("SIMPLE_COMMAND");
	if (current == PROGRAM)
		return ("PROGRAM");
*/	if (current == LINEBREAK)
		return ("LINEBREAK");
	if (current != 0)
		return ("NON-DEFINED");
	if (current == 0)
		return ("NULL");
	return ("NULL");
}

int			ft_read_stack(t_sym *stack)	
{
	while (*stack)
	{
		ft_putstr(read_state(*stack--));
		ft_putchar(10);
	}
	return (0);
}
