/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:32:10 by ariard            #+#    #+#             */
/*   Updated: 2017/02/13 22:40:40 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char			*read_state(t_sym current)
{
	if (current == PIPE_SEMI_SEQUENCE)
		return ("PIPE_SEMI_SEQUENCE");
	if (current == TK_PIPE)
		return ("TK_PIPE");
	if (current == PROGRAM)
		return ("PROGRAM");
	if (current == COMMAND)
		return ("COMMAND");
	if (current == PIPE_SEQUENCE)
		return ("PIPE_SEQUENCE");
	if (current == PIPELINE)
		return ("PIPELINE");
	if (current == AND_OR)
		return ("AND_OR");
	if (current == LIST)
		return ("LIST");
	if (current == COMPLETE_COMMAND)
		return ("COMPLETE_COMMAND");
	if (current == COMPLETE_COMMANDS)
		return ("COMPLETE_COMMANDS");
	if (current == TK_N_WORD)
		return ("TK_WORD");
	if (current == CMD_NAME)
		return ("CMD_NAME");
	if (current == HERE_END)
		return ("HERE_END");
	if (current == FILENAME)
		return ("FILENAME");
	if (current == CMD_SUFFIX)
		return ("CMD_SUFFIX");
	if (current == SIMPLE_COMMAND)
		return ("SIMPLE_COMMAND");
	if (current == TK_SEMI)
		return ("TK_SEMI");
	if (current == ALL)
		return ("ALL");
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
