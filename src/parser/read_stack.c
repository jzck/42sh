/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:32:10 by ariard            #+#    #+#             */
/*   Updated: 2017/03/11 19:55:57 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*read_state(t_sym current)
{
	if (current == TK_BANG)
		return ("TK_BANG");
	if (current == OPEN_FUNC)
		return ("OPEN_FUNC");
	if (current == CLOSE_FUNC)
		return ("CLOSE_FUNC");
	if (current == HEREDOCDATA)
		return ("HEREDOCDATA");
	if (current == TERMINUS)
		return ("TERMINUS");
	if (current == SEQUENCE)
		return ("SEQUENCE");
	if (current == LINEBREAK)
		return ("LINEBREAK");
	if (current == CLOSE_LIST)
		return ("CLOSE_LIST");
	if (current == BRACE_CLAUSE)
		return ("BRACE_CLAUSE");
	if (current == FUNC_NAME)
		return ("FUNC_NAME");
	if (current == TK_LBRACE)
		return ("TK_LBRACE");
	if (current == TK_RBRACE)
		return ("TK_RBRACE");
	if (current == TK_ASSIGNEMENT_WORD)
		return ("TK_ASSIGNEMENT_WORD");
	if (current == CASE_CLAUSE)
		return ("CASE_CLAUSE");
	if (current == CASE_LIST_NS)
		return ("CASE_LIST_NS");
	if (current == TK_DSEMI)
		return ("TK_DSEMI");
	if (current == TK_PAREN_OPEN)
		return ("TK_PAREN_OPEN");
	if (current == TK_PAREN_CLOSE)
		return ("TK_PAREN_CLOSE");
	if (current == FOR_WORDLIST)
		return ("FOR_WORDLIST");
	if (current == FOR_CLAUSE)
		return ("FOR_CLAUSE");
	if (current == TK_NAME)
		return ("TK_NAME");
	if (current == TK_FOR)
		return ("FOR");
	if (current == NAME)
		return ("NAME");
	if (current == 0)
		return ("NULL");
	if (current == PATTERN)
		return ("PATTERN");
	if (current == TK_CASE)
		return ("TK_CASE");
	if (current == TK_IN)
		return ("TK_IN");
	if (current == TK_ESAC)
		return ("TK_ESAC");
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
	if (current == SUBSHELL)
		return ("SUBSEHLL");
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
	if (current == CMD)
		return ("CMD");
	if (current != 0)
		return ("NON-DEFINED");
	if (current == 0)
		return ("NULL");
	return ("NULL");
}

int			ft_read_stack(t_sym *stack)
{
	DG("read stack :");
	while (*stack)
		DG("%s", read_state(*stack--));
	return (0);
}


int			ft_show_heredoc_data(t_btree **ast)
{
	t_astnode	*node;
	t_redir		*redir;

	if (*ast)
		if ((*ast)->left)
		{
			node = ((*ast)->left)->item;
			redir = (node->data.cmd.redir)->content;
			if (redir->type == TK_DLESS)
				DG("Show me heredoc data from node :%s", redir->heredoc_data);
		}
	return (0);
}
