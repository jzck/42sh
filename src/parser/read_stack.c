/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:32:10 by ariard            #+#    #+#             */
/*   Updated: 2017/02/20 22:38:48 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char			*read_state(t_sym current)
{
	if (current == UNTIL_CLAUSE)
		return ("UNTIL_CLAUSE");
	if (current == TK_UNTIL)
		return ("TK_UNTIL");
	if (current == IF_CLAUSE)
		return ("IF_CLAUSE");
	if (current == CONDITION)
		return ("CONDITION");
	if (current == COMPLETE_CONDITION)
		return ("COMPLETE_CONDITION");
	if (current == TK_ELSE)
		return ("TK_ELSE");
	if (current == TK_FI)
		return ("TK_FI");
	if (current == ELSE_PART)
		return ("ELSE_PART");
	if (current == TK_FI)
		return ("TK_FI");
	if (current == TK_IF)
		return ("TK_IF");
	if (current == TK_ELIF)
		return ("TK_ELIF");
	if (current == TK_THEN)
		return ("TK_THEN");
	if (current == COMPOUND_COMMAND)
		return ("COMPOUND_COMMAND");
	if (current == WHILE_CLAUSE)
		return ("WHILE_CLAUSE");
	if (current == LOOP)
		return ("LOOP");
	if (current == TK_DONE)
		return ("DONE");
	if (current == TK_DO)
		return ("TK_DO");
	if (current == END_COMMAND)
		return ("END_COMMAND");
	if (current == SEQUENTIAL_SEP)
		return ("SEQUENTIAL_SEP");
	if (current == SEPARATOR)
		return ("SEPARATOR");
	if (current == SEPARATOR_OP)
		return ("SEPARATOR_OP");
	if (current == TERM)
		return ("TERM");
	if (current == COMPOUND_LIST)
		return ("COMPOUND_LIST");
	if (current == DO_GROUP)
		return ("DO_GROUP");
	if (current == TK_NEWLINE)
		return ("TK_NEWLINE");
	if (current == TK_WHILE)
		return ("TK_WHILE");
	if (current == TK_DO)
		return ("TK_DO");
	if (current == TK_DONE)
		return ("TK_DONE");
	if (current == AND_OR_MINOR)
		return("AND_OR_MINOR");
	if (current == AND_OR_MAJOR)
		return ("AND_OR_MAJOR");
	if (current == TK_COMMAND)
		return ("TK_COMMAND");
	if (current == TK_AND_IF)
		return ("TK_AND_IF");
	if (current == TK_OR_IF)
		return ("TK_OR_IF");
	if (current == TK_AMP)
		return ("TK_AMP");
	if (current == TK_PIPE)
		return ("TK_PIPE");
	if (current == TK_LESS)
		return ("TK_LESS");
	if (current == TK_GREAT)
		return ("TK_GREAT");
	if (current == TK_DLESS)
		return ("TK_DLESS");
	if (current == TK_DGREAT)
		return ("TK_DGREAT");
	if (current == TK_DGREAT)
		return ("TK_DGREAT");
	if (current == TK_LESSAND)
		return ("TK_LESSAND");
	if (current == TK_GREATAND)
		return ("TK_GREATAND");
	if (current == TK_SUBSHELL)
		return ("TK_SUBSEHLL");
	if (current == CMD_SUPERIOR)
		return ("CMD_SUPERIOR");
	if (current == TK_IO_NUMBER)
		return ("IO_NUMBER");
	if (current == CMD_SUFFIX)
		return ("CMD_SUFFIX");
	if (current == CMD_PREFIX)
		return ("CMD_PREFIX");
	if (current == IO_REDIRECT)
		return ("IO_REDIRECT");
	if (current == IO_FILE)
		return ("IO_FILE");
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
	if (current == TK_WORD)
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
	if (current == NEWLINE_LIST)
		return ("NEWLINE_LIST");
	if (current == LINEBREAK)
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
