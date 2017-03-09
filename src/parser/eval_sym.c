/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_sym.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:26:30 by ariard            #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_stackmatch	g_stackmatch[] =
{
	{TK_WORD, CMD_SUFFIX},
	{TK_WORD, TK_PIPE},
	{TK_WORD, TK_CASE},
	{TK_WORD, WORDLIST},
	{TK_WORD, LINEBREAK},
	{TK_WORD, TK_BANG},
	{TK_WORD, TK_PAREN_OPEN},
	{TK_WORD, TK_LBRACE},
	{TK_WORD, COMPLETE_COMMANDS},
	{TK_WORD, TK_IN},
	{TK_WORD, FOR_WORDLIST},
	{TK_WORD, MATH},
	{TK_ASSIGNEMENT_WORD, CMD_PREFIX},
	{TK_IO_NUMBER, REDIRECT_LIST},
	{TK_IO_NUMBER, CMD_SUFFIX},
	{TK_IO_NUMBER, CMD_PREFIX},
	{TK_IO_NUMBER, CMD_NAME},
	{TK_IO_NUMBER, CMD_WORD},
	{TK_IO_NUMBER, LINEBREAK},
	{TK_IO_NUMBER, TK_BANG},
	{TK_IO_NUMBER, TK_PAREN_OPEN},
	{TK_IO_NUMBER, TK_LBRACE},
	{TK_IO_NUMBER, COMPLETE_COMMANDS},
	{TK_IO_NUMBER, TK_BANG},
	{TK_IO_NUMBER, SEPARATOR_OP},
	{TK_IO_NUMBER, NEWLINE_LIST},
	{TK_IO_NUMBER, PIPE_SEMI_SEQUENCE},
	{TK_IO_NUMBER, PIPE_CLOSE_SEQUENCE},
	{TK_IO_NUMBER, SEQUENCE},
//	watch!
	{TK_IO_NUMBER, CMD_SUPERIOR},
	{TK_IO_NUMBER, AND_OR_MAJOR},
	{TK_AND_IF, AND_OR},
	{TK_AND_IF, CMD_SUPERIOR},
	{TK_OR_IF, AND_OR},
	{TK_OR_IF, CMD_SUPERIOR},
	{TK_OR_IF, AND_OR},
	{TK_DSEMI, LINEBREAK},
	{TK_DSEMI, TK_BANG},
	{TK_DSEMI, COMPLETE_COMMANDS},
	{TK_DSEMI, COMPOUND_LIST},
	{TK_DSEMI, CASE_LIST_NS},
	{TK_DSEMI, CMD_SUPERIOR},
	{TK_DSEMI, PIPE_SEMI_SEQUENCE},
	{TK_DSEMI, PIPE_CLOSE_SEQUENCE},
	{TK_DSEMI, SEQUENCE},
//	watch!
	{TK_LESS, TK_IO_NUMBER},
	{TK_LESS, REDIRECT_LIST},
	{TK_LESS, CMD_SUFFIX},
	{TK_LESS, CMD_PREFIX},
	{TK_LESS, CMD_WORD},
	{TK_LESS, CMD_NAME},
	{TK_LESS, LINEBREAK},
	{TK_LESS, TK_BANG},
	{TK_LESS, TK_PAREN_OPEN},
	{TK_LESS, TK_LBRACE},
	{TK_LESS, COMPLETE_COMMANDS},
	{TK_LESS, TK_BANG},
	{TK_LESS, SEPARATOR_OP},
	{TK_LESS, NEWLINE_LIST},
	{TK_LESS, PIPE_SEMI_SEQUENCE},
	{TK_LESS, PIPE_CLOSE_SEQUENCE},
	{TK_LESS, SEQUENCE},
//	watch !
	{TK_LESS, CMD_SUPERIOR},
	{TK_LESS, AND_OR_MAJOR},
	{TK_GREAT, TK_IO_NUMBER},
	{TK_GREAT, REDIRECT_LIST},
	{TK_GREAT, CMD_SUFFIX},
	{TK_GREAT, CMD_PREFIX},
	{TK_GREAT, CMD_WORD},
	{TK_GREAT, CMD_NAME},
	{TK_GREAT, LINEBREAK},
	{TK_GREAT, TK_BANG},
	{TK_GREAT, TK_PAREN_OPEN},
	{TK_GREAT, TK_LBRACE},
	{TK_GREAT, COMPLETE_COMMANDS},
	{TK_GREAT, TK_BANG},
	{TK_GREAT, SEPARATOR_OP},
	{TK_GREAT, NEWLINE_LIST},
	{TK_GREAT, PIPE_SEMI_SEQUENCE},
	{TK_GREAT, PIPE_CLOSE_SEQUENCE},
	{TK_GREAT, SEQUENCE},
//	watch !
//duplicate and extend
	{TK_GREAT, CMD_SUPERIOR},
	{TK_GREAT, AND_OR_MAJOR},

	{TK_DLESS, TK_IO_NUMBER},
	{TK_DLESS, REDIRECT_LIST},
	{TK_DLESS, CMD_SUFFIX},
	{TK_DLESS, CMD_PREFIX},
	{TK_DLESS, CMD_WORD},
	{TK_DLESS, CMD_NAME},
	{TK_DLESS, LINEBREAK},
	{TK_DLESS, TK_BANG},
	{TK_DLESS, TK_PAREN_OPEN},
	{TK_DLESS, TK_LBRACE},
	{TK_DLESS, COMPLETE_COMMANDS},
	{TK_DLESS, TK_BANG},
	{TK_DLESS, SEPARATOR_OP},
	{TK_DLESS, NEWLINE_LIST},
	{TK_DLESS, PIPE_SEMI_SEQUENCE},
	{TK_DLESS, PIPE_CLOSE_SEQUENCE},
	{TK_DLESS, SEQUENCE},
//	watch !
	{TK_DLESS, CMD_SUPERIOR},
	{TK_DLESS, AND_OR_MAJOR},

	{TK_DLESSDASH, TK_IO_NUMBER},
	{TK_DLESSDASH, REDIRECT_LIST},
	{TK_DLESSDASH, CMD_SUFFIX},
	{TK_DLESSDASH, CMD_PREFIX},
	{TK_DLESSDASH, CMD_WORD},
	{TK_DLESSDASH, CMD_NAME},
	{TK_DLESSDASH, LINEBREAK},
	{TK_DLESSDASH, TK_BANG},
	{TK_DLESSDASH, TK_PAREN_OPEN},
	{TK_DLESSDASH, TK_LBRACE},
	{TK_DLESSDASH, COMPLETE_COMMANDS},
	{TK_DLESSDASH, TK_BANG},
	{TK_DLESSDASH, TK_BANG},
	{TK_DLESSDASH, SEPARATOR_OP},
	{TK_DLESSDASH, NEWLINE_LIST},
	{TK_DLESSDASH, PIPE_SEMI_SEQUENCE},
	{TK_DLESSDASH, PIPE_CLOSE_SEQUENCE},
	{TK_DLESSDASH, SEQUENCE},
//	watch !
	{TK_DLESSDASH, CMD_SUPERIOR},
	{TK_DLESSDASH, AND_OR_MAJOR},

	{TK_DGREAT, TK_IO_NUMBER},
	{TK_DGREAT, REDIRECT_LIST},
	{TK_DGREAT, CMD_SUFFIX},
	{TK_DGREAT, CMD_PREFIX},
	{TK_DGREAT, CMD_WORD},
	{TK_DGREAT, CMD_NAME},
	{TK_DGREAT, LINEBREAK},
	{TK_DGREAT, TK_BANG},
	{TK_DGREAT, TK_PAREN_OPEN},
	{TK_DGREAT, TK_LBRACE},
	{TK_DGREAT, COMPLETE_COMMANDS},
	{TK_DGREAT, TK_BANG},
	{TK_DGREAT, TK_BANG},
	{TK_DGREAT, SEPARATOR_OP},
	{TK_DGREAT, NEWLINE_LIST},
	{TK_DGREAT, PIPE_SEMI_SEQUENCE},
	{TK_DGREAT, PIPE_CLOSE_SEQUENCE},
	{TK_DGREAT, SEQUENCE},
//	watch !
	{TK_DGREAT, CMD_SUPERIOR},
	{TK_DGREAT, AND_OR_MAJOR},

	{TK_LESSAND, TK_IO_NUMBER},
	{TK_LESSAND, REDIRECT_LIST},
	{TK_LESSAND, CMD_SUFFIX},
	{TK_LESSAND, CMD_PREFIX},
	{TK_LESSAND, CMD_WORD},
	{TK_LESSAND, CMD_NAME},
	{TK_LESSAND, LINEBREAK},
	{TK_LESSAND, TK_BANG},
	{TK_LESSAND, TK_PAREN_OPEN},
	{TK_LESSAND, TK_LBRACE},
	{TK_LESSAND, COMPLETE_COMMANDS},
	{TK_LESSAND, TK_BANG},
	{TK_LESSAND, TK_BANG},
	{TK_LESSAND, SEPARATOR_OP},
	{TK_LESSAND, NEWLINE_LIST},
	{TK_LESSAND, PIPE_SEMI_SEQUENCE},
	{TK_LESSAND, PIPE_CLOSE_SEQUENCE},
	{TK_LESSAND, SEQUENCE},
//	watch !
	{TK_LESSAND, CMD_SUPERIOR},
	{TK_LESSAND, AND_OR_MAJOR},

	{TK_GREATAND, TK_IO_NUMBER},
	{TK_GREATAND, REDIRECT_LIST},
	{TK_GREATAND, CMD_SUFFIX},
	{TK_GREATAND, CMD_PREFIX},
	{TK_GREATAND, CMD_WORD},
	{TK_GREATAND, CMD_NAME},
	{TK_GREATAND, LINEBREAK},
	{TK_GREATAND, TK_BANG},
	{TK_GREATAND, TK_PAREN_OPEN},
	{TK_GREATAND, TK_LBRACE},
	{TK_GREATAND, COMPLETE_COMMANDS},
	{TK_LESSAND, TK_BANG},
	{TK_GREATAND, TK_BANG},
	{TK_GREATAND, SEPARATOR_OP},
	{TK_GREATAND, NEWLINE_LIST},
	{TK_GREATAND, PIPE_SEMI_SEQUENCE},
	{TK_GREATAND, PIPE_CLOSE_SEQUENCE},
	{TK_GREATAND, SEQUENCE},
//	watch ! 
	{TK_GREATAND, CMD_SUPERIOR},
	{TK_GREATAND, AND_OR_MAJOR},


	{TK_IF, LINEBREAK},
	{TK_IF, TK_BANG},
	{TK_IF, TK_PAREN_OPEN},
	{TK_IF, TK_LBRACE},
	{TK_IF, COMPLETE_COMMANDS},
	{TK_IF, TK_BANG},
	{TK_IF, SEPARATOR_OP},
	{TK_IF, NEWLINE_LIST},
	{TK_IF, SEQUENCE},
//	watch !
	{TK_IF, TK_WHILE},
	{TK_IF, FUNC_NAME},
	{TK_IF, TK_UNTIL},
	{TK_IF, TK_IF},
	{TK_IF, TK_DO},
	{TK_IF, TK_ELIF},
	{TK_IF, TK_ELSE},
	{TK_IF, TK_THEN},
	{TK_IF, TK_PAREN_CLOSE},
	{TK_IF, COMPLETE_CONDITION},
	{TK_IF, COMPOUND_LIST},
	{TK_IF, CASE_LIST_NS},
	{TK_THEN, CONDITION},
	{TK_THEN, COMPOUND_LIST},
	{TK_ELSE, COMPOUND_LIST},
	{TK_ELSE, CONDITION},
	{TK_ELSE, COMPLETE_CONDITION},
	{TK_ELIF, COMPOUND_LIST},
	{TK_ELIF, COMPLETE_CONDITION},
	{TK_ELIF, CONDITION},
	{TK_FI, ELSE_PART},
	{TK_FI, COMPOUND_LIST},
	{TK_FI, CMD_SUPERIOR},
	{TK_FI, END_COMMAND},
	{TK_FI, CONDITION},
	{TK_DO, CMD_SUPERIOR},
	{TK_FI, COMPLETE_CONDITION},
	{TK_DO, COMPOUND_LIST},
	{TK_DO, NAME},
	{TK_DO, SEQUENTIAL_SEP},
	{TK_DONE, CMD_SUPERIOR},
	{TK_DONE, COMPOUND_LIST},
	{TK_DONE, END_COMMAND},
	{TK_CASE, LINEBREAK},
	{TK_CASE, TK_BANG},
	{TK_CASE, TK_PAREN_OPEN},
	{TK_CASE, TK_LBRACE},
	{TK_CASE, COMPLETE_COMMANDS},
	{TK_CASE, TK_BANG},
	{TK_CASE, TK_DO},
	{TK_CASE, TK_THEN},
	{TK_CASE, TK_PAREN_CLOSE},
	{TK_CASE, TK_WHILE},
	{TK_CASE, FUNC_NAME},
	{TK_CASE, TK_UNTIL},
	{TK_CASE, TK_IF},
	{TK_CASE, TK_ELIF},
	{TK_CASE, TK_ELSE},
	{TK_CASE, COMPLETE_CONDITION},
	{TK_CASE, CASE_LIST_NS},
	{TK_CASE, COMPOUND_LIST},
	{TK_CASE, NEWLINE_LIST},
	{TK_CASE, SEPARATOR_OP},
	{TK_CASE, SEQUENCE},
//	watch !
	{TK_IN, TK_WORD},
	{TK_IN, NAME},
	{TK_ESAC, CASE_LIST_NS},
	{TK_ESAC, LINEBREAK},
	{TK_ESAC, TK_BANG},
	{TK_ESAC, TK_IN},
	{TK_WHILE, LINEBREAK},
	{TK_WHILE, TK_BANG},
	{TK_WHILE, TK_PAREN_OPEN},
	{TK_WHILE, TK_LBRACE},
	{TK_WHILE, COMPLETE_COMMANDS},
	{TK_WHILE, TK_BANG},
	{TK_WHILE, SEPARATOR_OP},
	{TK_WHILE, NEWLINE_LIST},
	{TK_WHILE, SEQUENCE},
//	watch !
	{TK_WHILE, TK_DO},
	{TK_WHILE, TK_PAREN_CLOSE},
	{TK_WHILE, TK_WHILE},
	{TK_WHILE, FUNC_NAME},
	{TK_WHILE, COMPOUND_LIST},
	{TK_WHILE, CASE_LIST_NS},
	{TK_WHILE, TK_IF},
	{TK_WHILE, TK_ELIF},
	{TK_WHILE, TK_ELSE},
	{TK_WHILE, TK_PAREN_CLOSE},
	{TK_WHILE, TK_THEN},
	{TK_WHILE, COMPLETE_CONDITION},
	{TK_UNTIL, LINEBREAK},
	{TK_UNTIL, TK_BANG},
	{TK_UNTIL, TK_PAREN_OPEN},
	{TK_UNTIL, TK_LBRACE},
	{TK_UNTIL, COMPLETE_COMMANDS},
	{TK_UNTIL, TK_BANG},
	{TK_UNTIL, SEPARATOR_OP},
	{TK_UNTIL, NEWLINE_LIST},
	{TK_UNTIL, SEQUENCE},
//	watch !
	{TK_UNTIL, TK_DO},
	{TK_UNTIL, TK_PAREN_CLOSE},
	{TK_UNTIL, TK_WHILE},
	{TK_UNTIL, FUNC_NAME},
	{TK_UNTIL, COMPOUND_LIST},
	{TK_UNTIL, CASE_LIST_NS},
	{TK_UNTIL, TK_IF},
	{TK_UNTIL, TK_ELIF},
	{TK_UNTIL, TK_ELSE},
	{TK_UNTIL, TK_THEN},
	{TK_UNTIL, TK_PAREN_CLOSE},
	{TK_UNTIL, COMPLETE_CONDITION},
	{TK_FOR, LINEBREAK},
	{TK_FOR, TK_BANG},
	{TK_FOR, TK_PAREN_OPEN},
	{TK_FOR, TK_LBRACE},
	{TK_FOR, COMPLETE_COMMANDS},
	{TK_FOR, TK_BANG},
	{TK_FOR, TK_BANG},
	{TK_FOR, SEPARATOR_OP},
	{TK_FOR, NEWLINE_LIST},
	{TK_FOR, SEQUENCE},
//	watch !
	{TK_FOR, TK_DO},
	{TK_FOR, TK_PAREN_CLOSE},
	{TK_FOR, TK_WHILE},
	{TK_FOR, FUNC_NAME},
	{TK_FOR, COMPOUND_LIST},
	{TK_FOR, CASE_LIST_NS},
	{TK_FOR, TK_IF},
	{TK_FOR, TK_ELIF},
	{TK_FOR, TK_THEN},
	{TK_FOR, TK_ELSE},
	{TK_FOR, TK_PAREN_CLOSE},
	{TK_FOR, COMPLETE_CONDITION},
	{TK_LBRACE, COMPLETE_COMMANDS},
	{TK_LBRACE, LINEBREAK},
	{TK_LBRACE, TK_BANG},
	{TK_LBRACE, TK_LBRACE},
	{TK_LBRACE, TK_BANG},
	{TK_LBRACE, SEPARATOR_OP},
	{TK_LBRACE, NEWLINE_LIST},
	{TK_LBRACE, SEQUENCE},
//	watch !
	{TK_LBRACE, AND_OR_MAJOR},
	{TK_LBRACE, TK_WHILE},
	{TK_LBRACE, FUNC_NAME},
	{TK_LBRACE, TK_UNTIL},
	{TK_LBRACE, TK_DO},
	{TK_LBRACE, TK_PAREN_CLOSE},
	{TK_LBRACE, TK_LBRACE},
	{TK_LBRACE, TK_IF},
	{TK_LBRACE, TK_ELIF},
	{TK_LBRACE, TK_THEN},
	{TK_LBRACE, TK_ELSE},
	{TK_LBRACE, COMPOUND_LIST},
	{TK_LBRACE, CASE_LIST_NS},
	{TK_LBRACE, COMPLETE_CONDITION},
	{TK_LBRACE, TK_IN},
	{TK_LBRACE, TK_PIPE},
	{TK_RBRACE, TK_SEMI},
	{TK_RBRACE, END_COMMAND},
	{TK_RBRACE, SEPARATOR_OP},
	{TK_RBRACE, WORD},
	{TK_RBRACE, IN},
	{TK_RBRACE, TK_AND_IF},
	{TK_RBRACE, TK_OR_IF},
	{TK_RBRACE, TK_RBRACE},
	{TK_RBRACE, COMPLETE_COMMANDS},
	{TK_RBRACE, CMD_SUPERIOR},
	{TK_RBRACE, PIPE_SEMI_SEQUENCE},
	{TK_RBRACE, PIPE_CLOSE_SEQUENCE},
	{TK_RBRACE, CASE_LIST_NS},
	{TK_RBRACE, PROGRAM},
	{TK_RBRACE, TK_PAREN_OPEN},
	{TK_RBRACE, TK_LBRACE},
	{TK_RBRACE, PATTERN_CASE},
	{TK_RBRACE, PATTERN},
	{TK_RBRACE, COMPOUND_LIST},
	{TK_RBRACE, FUNC_NAME},
	{TK_BANG, LINEBREAK},
	{TK_BANG, TK_PAREN_OPEN},
	{TK_BANG, TK_LBRACE},
	{TK_BANG, COMPLETE_COMMANDS},
	{TK_BANG, SEPARATOR_OP},
	{TK_BANG, NEWLINE_LIST},
	{TK_IN, LINEBREAK},
	{TK_SEMI, NAME},
	{TK_SEMI, IN},
	{TK_SEMI, WORDLIST},
	{TK_SEMI, LIST},
	{TK_SEMI, TERM},
	{TK_SEMI, CMD_NAME},
	{TK_SEMI, PROGRAM},
	{TK_SEMI, FOR_WORDLIST},
	{TK_AMP, LIST},
	{TK_AMP, TERM},
	{TK_PIPE, PATTERN},
	{TK_PIPE, CMD_SUPERIOR},
	{TK_PIPE, PIPE_SEMI_SEQUENCE},
	{TK_PIPE, PIPE_CLOSE_SEQUENCE},
	{PATTERN_CASE, TK_IN},
	{PATTERN_CASE, CASE_LIST_NS},
	{TK_PAREN_OPEN, COMPLETE_COMMANDS},
	{TK_PAREN_OPEN, LINEBREAK},
	{TK_PAREN_OPEN, TK_BANG},
	{TK_PAREN_OPEN, TK_PAREN_OPEN},
	{TK_PAREN_OPEN, SEPARATOR_OP},
	{TK_PAREN_OPEN, NEWLINE_LIST},
	{TK_PAREN_OPEN, SEQUENCE},
	{TK_PAREN_OPEN, FUNC_NAME},
//	watch !
	{TK_PAREN_OPEN, AND_OR_MAJOR},
	{TK_PAREN_OPEN, TK_WHILE},
	{TK_PAREN_OPEN, FUNC_NAME},
	{TK_PAREN_OPEN, TK_UNTIL},
	{TK_PAREN_OPEN, TK_DO},
	{TK_PAREN_OPEN, TK_PAREN_CLOSE},
	{TK_PAREN_OPEN, TK_IF},
	{TK_PAREN_OPEN, TK_ELIF},
	{TK_PAREN_OPEN, TK_THEN},
	{TK_PAREN_OPEN, TK_ELSE},
	{TK_PAREN_OPEN, COMPOUND_LIST},
	{TK_PAREN_OPEN, CASE_LIST_NS},
	{TK_PAREN_OPEN, COMPLETE_CONDITION},
	{TK_PAREN_OPEN, TK_IN},
	{TK_PAREN_OPEN, CMD_SUPERIOR},
	{OPEN_FUNC, CMD_SUPERIOR},
	{SEQUENTIAL_SEP, NAME},
	{SEQUENTIAL_SEP, IN},
	{SEQUENTIAL_SEP, WORDLIST},
	{SEQUENTIAL_SEP, FOR_WORDLIST},
	{END_COMMAND, SEQUENCE},
	{END_COMMAND, PIPE_SEMI_SEQUENCE},
	{END_COMMAND, AND_OR_MAJOR},
	{END_COMMAND, TK_WHILE},
	{END_COMMAND, FUNC_NAME},
	{END_COMMAND, TK_UNTIL},
	{END_COMMAND, TK_DO},
	{END_COMMAND, TK_PAREN_CLOSE},
	{END_COMMAND, TK_IF},
	{END_COMMAND, TK_THEN},
	{END_COMMAND, TK_ELIF},
	{END_COMMAND, TK_ELSE},
	{END_COMMAND, LINEBREAK},
	{END_COMMAND, TK_BANG},
	{END_COMMAND, TK_PAREN_OPEN},
	{END_COMMAND, TK_LBRACE},
	{END_COMMAND, COMPLETE_COMMANDS},
	{END_COMMAND, COMPOUND_LIST},
	{END_COMMAND, CASE_LIST_NS},
	{END_COMMAND, COMPLETE_CONDITION},
	{SEPARATOR, MATH_SUP},
	{SEPARATOR, CMD_SUPERIOR},
	{SEPARATOR, TERM},
	{SEPARATOR, COMPOUND_LIST},
	{SEPARATOR, CASE_LIST_NS},
	{SEPARATOR, PIPE_SEMI_SEQUENCE},
	{SEPARATOR, PIPE_CLOSE_SEQUENCE},
	{SEPARATOR_OP, MATH_SUP},
	{SEPARATOR_OP, CMD_SUPERIOR},
	{SEPARATOR_OP, LIST},
	{SEPARATOR_OP, TERM},
	{SEPARATOR_OP, CASE_LIST_NS},
	{SEPARATOR_OP, COMPOUND_LIST},
	{SEPARATOR_OP, PIPE_SEMI_SEQUENCE},
	{SEPARATOR_OP, PIPE_CLOSE_SEQUENCE},
	{LINEBREAK, MATH_SUP},
	{LINEBREAK, TK_SEMI},
	{LINEBREAK, END_COMMAND},
	{LINEBREAK, SEPARATOR_OP},
	{LINEBREAK, TK_PAREN_CLOSE},
	{LINEBREAK, WORD},
	{LINEBREAK, IN},
	{LINEBREAK, TK_AND_IF},
	{LINEBREAK, TK_OR_IF},
	{LINEBREAK, TK_PIPE},
	{LINEBREAK, LINEBREAK},
	{LINEBREAK, TK_BANG},
	{LINEBREAK, COMPLETE_COMMANDS},
	{LINEBREAK, CMD_SUPERIOR},
	{LINEBREAK, PIPE_SEMI_SEQUENCE},
	{LINEBREAK, PIPE_CLOSE_SEQUENCE},
	{LINEBREAK, COMPOUND_LIST},
	{LINEBREAK, CASE_LIST_NS},
	{LINEBREAK, PROGRAM},
	{LINEBREAK, TK_PAREN_OPEN},
	{LINEBREAK, TK_LBRACE},
	{TK_PAREN_CLOSE, MATH},
	{TK_PAREN_CLOSE, MATH_PLUS},
	{TK_PAREN_CLOSE, TK_SEMI},
	{TK_PAREN_CLOSE, END_COMMAND},
	{TK_PAREN_CLOSE, SEPARATOR_OP},
	{TK_PAREN_CLOSE, WORD},
	{TK_PAREN_CLOSE, IN},
	{TK_PAREN_CLOSE, TK_AND_IF},
	{TK_PAREN_CLOSE, TK_OR_IF},
	{TK_PAREN_CLOSE, TK_PIPE},
	{TK_PAREN_CLOSE, COMPLETE_COMMANDS},
	{TK_PAREN_CLOSE, CMD_SUPERIOR},
	{TK_PAREN_CLOSE, PIPE_SEMI_SEQUENCE},
	{TK_PAREN_CLOSE, PIPE_CLOSE_SEQUENCE},
	{TK_PAREN_CLOSE, CASE_LIST_NS},
	{TK_PAREN_CLOSE, PROGRAM},
	{TK_PAREN_CLOSE, TK_LBRACE},
	{TK_PAREN_CLOSE, PATTERN_CASE},
	{TK_PAREN_CLOSE, PATTERN},
	{TK_PAREN_CLOSE, COMPOUND_LIST},
	{TK_PAREN_CLOSE, FUNC_NAME},
	{TK_PAREN_CLOSE, OPEN_FUNC},
	{TK_RBRACE, MATH},
	{TK_RBRACE, MATH_PLUS},
	{TK_RBRACE, TK_SEMI},
	{TK_RBRACE, END_COMMAND},
	{TK_RBRACE, SEPARATOR_OP},
	{TK_RBRACE, WORD},
	{TK_RBRACE, IN},
	{TK_RBRACE, TK_AND_IF},
	{TK_RBRACE, TK_OR_IF},
	{TK_RBRACE, TK_PIPE},
	{TK_RBRACE, TK_RBRACE},
	{TK_RBRACE, COMPLETE_COMMANDS},
	{TK_RBRACE, CMD_SUPERIOR},
	{TK_RBRACE, PIPE_SEMI_SEQUENCE},
	{TK_RBRACE, PIPE_CLOSE_SEQUENCE},
	{TK_RBRACE, CASE_LIST_NS},
	{TK_RBRACE, PROGRAM},
	{TK_RBRACE, TK_LBRACE},
	{TK_RBRACE, PATTERN_CASE},
	{TK_RBRACE, PATTERN},
	{TK_RBRACE, COMPOUND_LIST},
	{TK_RBRACE, FUNC_NAME},
	{NEWLINE_LIST, MATH_SUP},
	{NEWLINE_LIST, TK_DO},
	{NEWLINE_LIST, CASE_LIST_NS},
	{NEWLINE_LIST, TK_PAREN_CLOSE},
	{NEWLINE_LIST, TK_RBRACE},
	{NEWLINE_LIST, SEQUENTIAL_SEP},
	{NEWLINE_LIST, FOR_WORDLIST},
	{NEWLINE_LIST, TK_IN},
	{NEWLINE_LIST, TK_WHILE},
	{NEWLINE_LIST, FUNC_NAME},
	{NEWLINE_LIST, TK_UNTIL},
	{NEWLINE_LIST, TK_IF},
	{NEWLINE_LIST, TK_ELIF},
	{NEWLINE_LIST, TK_THEN},
	{NEWLINE_LIST, TK_ELSE},
	{NEWLINE_LIST, CMD_NAME},
	{NEWLINE_LIST, NEWLINE_LIST},
	{NEWLINE_LIST, NAME},
	{NEWLINE_LIST, IN},
	{NEWLINE_LIST, WORDLIST},
	{NEWLINE_LIST, TERM},
	{NEWLINE_LIST, COMPOUND_LIST},
	{NEWLINE_LIST, CASE_LIST_NS},
	{NEWLINE_LIST, COMPLETE_COMMANDS},
	{NEWLINE_LIST, COMPLETE_CONDITION},
	{NEWLINE_LIST, CONDITION},
	{NEWLINE_LIST, LINEBREAK},
	{NEWLINE_LIST, TK_BANG},
	{NEWLINE_LIST, TK_PAREN_OPEN},
	{NEWLINE_LIST, TK_LBRACE},
	{NEWLINE_LIST, PROGRAM},
	{HERE_END, TK_DLESS},
	{HERE_END, TK_DLESS},
	{HERE_END, TK_DLESSDASH},
	{IO_HERE, TK_IO_NUMBER},
	{IO_HERE, CMD_SUPERIOR},
	{IO_HERE, REDIRECT_LIST},
	{IO_HERE, CMD_SUFFIX},
	{IO_HERE, CMD_PREFIX},
	{IO_HERE, CMD_WORD},
	{IO_HERE, CMD_NAME},
	{IO_HERE, LINEBREAK},
	{IO_HERE, TK_BANG},
	{IO_HERE, TK_PAREN_OPEN},
	{IO_HERE, TK_LBRACE},
	{IO_HERE, COMPLETE_COMMANDS},
	{IO_HERE, SEPARATOR_OP},
	{IO_HERE, NEWLINE_LIST},
	{IO_HERE, PIPE_SEMI_SEQUENCE},
	{IO_HERE, PIPE_CLOSE_SEQUENCE},
	{IO_HERE, SEQUENCE},
//	watch !
	{FILENAME, TK_LESS},
	{FILENAME, TK_LESSAND},
	{FILENAME, TK_GREAT},
	{FILENAME, TK_GREATAND},
	{FILENAME, TK_DGREAT},
	{FILENAME, TK_LESSGREAT},
	{FILENAME, TK_CLOBBER},
	{IO_FILE, TK_IO_NUMBER},
	{IO_FILE, CMD_SUPERIOR},
	{IO_FILE, REDIRECT_LIST},
	{IO_FILE, CMD_SUFFIX},
	{IO_FILE, CMD_PREFIX},
	{IO_FILE, CMD_WORD},
	{IO_FILE, CMD_NAME},
	{IO_FILE, LINEBREAK},
	{IO_FILE, TK_BANG},
	{IO_FILE, COMPLETE_COMMANDS},
	{IO_FILE, SEPARATOR_OP},
	{IO_FILE, NEWLINE_LIST},
	{IO_FILE, PIPE_SEMI_SEQUENCE},
	{IO_FILE, PIPE_CLOSE_SEQUENCE},
	{IO_FILE, SEQUENCE},
//	watch !
	{IO_REDIRECT, REDIRECT_LIST},
	{IO_REDIRECT, CMD_SUPERIOR},
	{IO_REDIRECT, CMD_SUFFIX},
	{IO_REDIRECT, CMD_PREFIX},
	{IO_REDIRECT, CMD_WORD},
	{IO_REDIRECT, CMD_NAME},
	{IO_REDIRECT, LINEBREAK},
	{IO_REDIRECT, TK_BANG},
	{IO_REDIRECT, TK_PAREN_OPEN},
	{IO_REDIRECT, TK_LBRACE},
	{IO_REDIRECT, COMPLETE_COMMANDS},
	{IO_REDIRECT, SEPARATOR_OP},
	{IO_REDIRECT, NEWLINE_LIST},
	{IO_REDIRECT, PIPE_SEMI_SEQUENCE},
	{IO_REDIRECT, PIPE_CLOSE_SEQUENCE},
	{IO_REDIRECT, SEQUENCE},
//	watch !/
	{REDIRECT_LIST, COMPOUND_COMMAND},
	{CMD_SUFFIX, CMD_WORD},
	{CMD_SUFFIX, CMD_NAME},
	{CMD_SUFFIX, CMD_SUPERIOR},
	{CMD_SUFFIX, PIPE_SEMI_SEQUENCE},
	{CMD_SUFFIX, PIPE_CLOSE_SEQUENCE},
	{CMD_PREFIX, LINEBREAK},
	{CMD_PREFIX, TK_PAREN_OPEN},
	{CMD_PREFIX, TK_LBRACE},
	{CMD_PREFIX, COMPLETE_COMMANDS},
	{CMD_PREFIX, TK_BANG},
	{CMD_PREFIX, SEPARATOR_OP},
	{CMD_PREFIX, NEWLINE_LIST},
	{CMD_PREFIX, SEQUENCE},
//	watch !
	{CMD_WORD, CMD_PREFIX},
	{CMD_NAME, COMPLETE_COMMANDS},
	{CMD_NAME, LINEBREAK},
	{CMD_NAME, TK_PAREN_OPEN},
	{CMD_NAME, TK_LBRACE},
	{CMD_NAME, TK_BANG},
	{CMD_NAME, SEPARATOR_OP},
	{CMD_NAME, NEWLINE_LIST},
	{CMD_NAME, SEQUENCE},
//	watch !
	{CMD_NAME, AND_OR_MAJOR},
	{CMD_NAME, TK_WHILE},
	{CMD_NAME, FUNC_NAME},
	{CMD_NAME, TK_UNTIL},
	{CMD_NAME, TK_DO},
	{CMD_NAME, TK_PAREN_CLOSE},
	{CMD_NAME, TK_IF},
	{CMD_NAME, TK_ELIF},
	{CMD_NAME, TK_THEN},
	{CMD_NAME, TK_ELSE},
	{CMD_NAME, COMPOUND_LIST},
	{CMD_NAME, CASE_LIST_NS},
	{CMD_NAME, COMPLETE_CONDITION},

	{CMD_SUPERIOR, TK_WHILE},
	{CMD_SUPERIOR, FUNC_NAME},
	{CMD_SUPERIOR, TK_UNTIL},
	{CMD_SUPERIOR, TK_DO},
	{CMD_SUPERIOR, TK_PAREN_CLOSE},
	{CMD_SUPERIOR, TK_IF},
	{CMD_SUPERIOR, TK_ELIF},
	{CMD_SUPERIOR, TK_THEN},
	{CMD_SUPERIOR, TK_ELSE},
	{CMD_SUPERIOR, COMPOUND_LIST},
	{CMD_SUPERIOR, CASE_LIST_NS},
	{CMD_SUPERIOR, COMPLETE_CONDITION},
	{CMD_SUPERIOR, LINEBREAK},
	{CMD_SUPERIOR, TK_PAREN_OPEN},
	{CMD_SUPERIOR, TK_LBRACE},
	{CMD_SUPERIOR, COMPLETE_COMMANDS},
	{CMD_SUPERIOR, TK_BANG},
	{CMD_SUPERIOR, SEPARATOR_OP},
	{CMD_SUPERIOR, NEWLINE_LIST},
	{CMD_SUPERIOR, TK_PIPE},
	{CMD_SUPERIOR, SEQUENCE},
//	watch !
	{CMD_SUPERIOR, AND_OR_MAJOR},

	{CLOSE_FUNC, CMD_SUPERIOR},
	{CLOSE_FUNC, OPEN_FUNC},
	{MATH, LINEBREAK},
	{MATH, NEWLINE_LIST},
	{MATH, SEPARATOR},
	{MATH, SEPARATOR_OP},
	{MATH_PLUS, LINEBREAK},
	{MATH_PLUS, NEWLINE_LIST},
	{MATH_PLUS, SEPARATOR},
	{MATH_PLUS, SEPARATOR_OP},
	{MATH_SUP, LINEBREAK},
	{MATH_SUP, NEWLINE_LIST},
	{MATH_SUP, SEPARATOR},
	{MATH_SUP, SEPARATOR_OP},

	{SIMPLE_COMMAND, TK_WHILE},
	{SIMPLE_COMMAND, TK_UNTIL},
	{SIMPLE_COMMAND, TK_DO},
	{SIMPLE_COMMAND, TK_PAREN_CLOSE},
	{SIMPLE_COMMAND, TK_IF},
	{SIMPLE_COMMAND, TK_ELIF},
	{SIMPLE_COMMAND, TK_THEN},
	{SIMPLE_COMMAND, TK_ELSE},
	{SIMPLE_COMMAND, COMPOUND_LIST},
	{SIMPLE_COMMAND, CASE_LIST_NS},
	{SIMPLE_COMMAND, COMPLETE_CONDITION},
	{SIMPLE_COMMAND, LINEBREAK},
	{SIMPLE_COMMAND, TK_PAREN_OPEN},
	{SIMPLE_COMMAND, TK_LBRACE},
	{SIMPLE_COMMAND, COMPLETE_COMMANDS},
	{SIMPLE_COMMAND, TK_BANG},
	{SIMPLE_COMMAND, SEPARATOR_OP},
	{SIMPLE_COMMAND, NEWLINE_LIST},
	{SIMPLE_COMMAND, SEQUENCE},
//	watch !
	{SIMPLE_COMMAND, AND_OR_MAJOR},
	{DO_GROUP, CMD_SUPERIOR},
	{DO_GROUP, COMPOUND_LIST},
	{DO_GROUP, NAME},
	{DO_GROUP, SEQUENTIAL_SEP},
	{LOOP, TK_WHILE},
	{LOOP, FUNC_NAME},
	{LOOP, TK_UNTIL},
	{CONDITION, LINEBREAK},
	{CONDITION, TK_PAREN_OPEN},
	{CONDITION, TK_LBRACE},
	{CONDITION, COMPLETE_COMMANDS},
	{CONDITION, COMPOUND_LIST},
	{CONDITION, CASE_LIST_NS},
	{CONDITION, COMPLETE_CONDITION},
	{COMPLETE_CONDITION, LINEBREAK},
	{COMPLETE_CONDITION, TK_PAREN_OPEN},
	{COMPLETE_CONDITION, TK_LBRACE},
	{COMPLETE_CONDITION, COMPLETE_COMMANDS},
	{COMPLETE_CONDITION, COMPLETE_CONDITION},
	{COMPLETE_CONDITION, COMPLETE_CONDITION},
	{BRACE_GROUP, LINEBREAK},
	{BRACE_GROUP, TK_PAREN_OPEN},
	{BRACE_GROUP, TK_LBRACE},
	{BRACE_GROUP, COMPLETE_COMMANDS},
	{BRACE_GROUP, TK_BANG},
	{BRACE_GROUP, SEPARATOR_OP},
	{BRACE_GROUP, NEWLINE_LIST},
	{BRACE_GROUP, SEQUENCE},
//	watch !
	{FNAME, LINEBREAK},
	{FNAME, TK_PAREN_OPEN},
	{FNAME, TK_LBRACE},
	{FNAME, COMPLETE_COMMANDS},
	{FNAME, TK_BANG},
	{FNAME, SEPARATOR_OP},
	{FNAME, NEWLINE_LIST},
	{FNAME, SEQUENCE},
//	watch !
	{FUNCTION_BODY, FUNC},
	{FUNCTION_DEFINITION, LINEBREAK},
	{FUNCTION_DEFINITION, TK_PAREN_OPEN},
	{FUNCTION_DEFINITION, TK_LBRACE},
	{FUNCTION_DEFINITION, COMPLETE_COMMANDS},
	{FUNCTION_DEFINITION, TK_BANG},
	{FUNCTION_DEFINITION, SEPARATOR_OP},
	{FUNCTION_DEFINITION, NEWLINE_LIST},
	{FUNCTION_DEFINITION, SEQUENCE},
//	watch !
	{UNTIL_CLAUSE, LINEBREAK},
	{UNTIL_CLAUSE, TK_PAREN_OPEN},
	{UNTIL_CLAUSE, TK_LBRACE},
	{UNTIL_CLAUSE, COMPLETE_COMMANDS},
	{UNTIL_CLAUSE, TK_BANG},
	{UNTIL_CLAUSE, SEPARATOR_OP},
	{UNTIL_CLAUSE, NEWLINE_LIST},
	{UNTIL_CLAUSE,	SEQUENCE},
	{UNTIL_CLAUSE, TK_DO},
	{UNTIL_CLAUSE, TK_PAREN_CLOSE},
	{UNTIL_CLAUSE, TK_WHILE},
	{UNTIL_CLAUSE, FUNC_NAME},
	{UNTIL_CLAUSE, TK_UNTIL},
	{UNTIL_CLAUSE, TK_IF},
	{UNTIL_CLAUSE, TK_ELIF},
	{UNTIL_CLAUSE, TK_THEN},
	{UNTIL_CLAUSE, TK_ELSE},
	{UNTIL_CLAUSE, COMPOUND_LIST},
	{UNTIL_CLAUSE, CASE_LIST_NS},
	{UNTIL_CLAUSE, COMPLETE_CONDITION},
	{UNTIL_CLAUSE, AND_OR_MAJOR},
	{WHILE_CLAUSE, LINEBREAK},
	{WHILE_CLAUSE, COMPLETE_COMMANDS},
	{WHILE_CLAUSE, TK_BANG},
	{WHILE_CLAUSE, SEPARATOR_OP},
	{WHILE_CLAUSE, NEWLINE_LIST},
	{WHILE_CLAUSE, SEQUENCE},
//	watch !
	{WHILE_CLAUSE, TK_DO},
	{WHILE_CLAUSE, TK_PAREN_CLOSE},
	{WHILE_CLAUSE, TK_WHILE},
	{WHILE_CLAUSE, FUNC_NAME},
	{WHILE_CLAUSE, TK_UNTIL},
	{WHILE_CLAUSE, TK_IF},
	{WHILE_CLAUSE, TK_ELIF},
	{WHILE_CLAUSE, TK_THEN},
	{WHILE_CLAUSE, TK_ELSE},
	{WHILE_CLAUSE, COMPOUND_LIST},
	{WHILE_CLAUSE, CASE_LIST_NS},
	{WHILE_CLAUSE, COMPLETE_CONDITION},
	{WHILE_CLAUSE, AND_OR_MAJOR},
//	{ELSE_PART, COMPOUND_LIST},
//	{ELSE_PART, COMPLETE_CONDITION},
	{IF_CLAUSE, LINEBREAK},
	{IF_CLAUSE, TK_BANG},
	{IF_CLAUSE, TK_PAREN_OPEN},
	{IF_CLAUSE, TK_LBRACE},
	{IF_CLAUSE, COMPLETE_COMMANDS},
	{IF_CLAUSE, TK_BANG},
	{IF_CLAUSE, SEPARATOR_OP},
	{IF_CLAUSE, NEWLINE_LIST},
	{IF_CLAUSE, SEQUENCE},
//	watch !
	{IF_CLAUSE, TK_DO},
	{IF_CLAUSE, TK_PAREN_CLOSE},
	{IF_CLAUSE, TK_WHILE},
	{IF_CLAUSE, FUNC_NAME},
	{IF_CLAUSE, TK_UNTIL},
	{IF_CLAUSE, TK_IF},
	{IF_CLAUSE, TK_ELIF},
	{IF_CLAUSE, TK_THEN},
	{IF_CLAUSE, TK_ELSE},
	{IF_CLAUSE, COMPOUND_LIST},
	{IF_CLAUSE, CASE_LIST_NS},
	{IF_CLAUSE, COMPLETE_COMMAND},
	{IF_CLAUSE, COMPLETE_CONDITION},
	{IF_CLAUSE, AND_OR_MAJOR},
	{BRACE_CLAUSE, LINEBREAK},
	{BRACE_CLAUSE, TK_BANG},
	{BRACE_CLAUSE, TK_PAREN_OPEN},
	{BRACE_CLAUSE, TK_LBRACE},
	{BRACE_CLAUSE, COMPLETE_COMMANDS},
	{BRACE_CLAUSE, TK_BANG},
	{BRACE_CLAUSE, SEPARATOR_OP},
	{BRACE_CLAUSE, NEWLINE_LIST},
	{BRACE_CLAUSE, SEQUENCE},
//	watch !
	{BRACE_CLAUSE, TK_DO},
	{BRACE_CLAUSE, TK_PAREN_CLOSE},
	{BRACE_CLAUSE, TK_WHILE},
	{BRACE_CLAUSE, FUNC_NAME},
	{BRACE_CLAUSE, TK_UNTIL},
	{BRACE_CLAUSE, TK_IF},
	{BRACE_CLAUSE, TK_ELIF},
	{BRACE_CLAUSE, TK_THEN},
	{BRACE_CLAUSE, TK_ELSE},
	{BRACE_CLAUSE, COMPOUND_LIST},
	{BRACE_CLAUSE, CASE_LIST_NS},
	{BRACE_CLAUSE, COMPLETE_COMMAND},
	{BRACE_CLAUSE, COMPLETE_CONDITION},
	{BRACE_CLAUSE, AND_OR_MAJOR},
	{PATTERN, PATTERN_CASE},
	{PATTERN, CASE_LIST},
	{PATTERN, TK_IN},
	{CASE_LIST_NS, LINEBREAK},
	{CASE_LIST_NS, TK_IN},
	{CASE_CLAUSE, LINEBREAK},
	{CASE_CLAUSE, TK_BANG},
	{CASE_CLAUSE, TK_PAREN_OPEN},
	{CASE_CLAUSE, TK_LBRACE},
	{CASE_CLAUSE, COMPLETE_COMMANDS},
	{CASE_CLAUSE, TK_BANG},
	{CASE_CLAUSE, SEPARATOR_OP},
	{CASE_CLAUSE, NEWLINE_LIST},
	{CASE_CLAUSE, SEQUENCE},
//	watch !
	{CASE_CLAUSE, TK_PAREN_CLOSE},
	{CASE_CLAUSE, CASE_LIST_NS},
	{CASE_CLAUSE, TK_DO},
	{CASE_CLAUSE, TK_WHILE},
	{CASE_CLAUSE, FUNC_NAME},
	{CASE_CLAUSE, TK_UNTIL},
	{CASE_CLAUSE, TK_IF},
	{CASE_CLAUSE, TK_ELIF},
	{CASE_CLAUSE, TK_THEN},
	{CASE_CLAUSE, TK_ELSE},
	{CASE_CLAUSE, COMPOUND_LIST},
	{CASE_CLAUSE, CASE_LIST_NS},
	{CASE_CLAUSE, COMPLETE_CONDITION},
	{CASE_CLAUSE, AND_OR_MAJOR},
	
	{WORDLIST, IN},
	{IN, LINEBREAK},
	{NAME, TK_FOR},
	{FOR_WORDLIST, NAME},
	{FOR_CLAUSE, LINEBREAK},
	{FOR_CLAUSE, TK_BANG},
	{FOR_CLAUSE, TK_PAREN_OPEN},
	{FOR_CLAUSE, TK_LBRACE},
	{FOR_CLAUSE, COMPLETE_COMMANDS},
	{FOR_CLAUSE, SEPARATOR_OP},
	{FOR_CLAUSE, NEWLINE_LIST},
	{FOR_CLAUSE, SEQUENCE},
//	watch !
	{FOR_CLAUSE, TK_DO},
	{FOR_CLAUSE, TK_PAREN_CLOSE},
	{FOR_CLAUSE, TK_WHILE},
	{FOR_CLAUSE, FUNC_NAME},
	{FOR_CLAUSE, TK_UNTIL},
	{FOR_CLAUSE, TK_IF},
	{FOR_CLAUSE, TK_ELIF},
	{FOR_CLAUSE, TK_THEN},
	{FOR_CLAUSE, TK_ELSE},
	{FOR_CLAUSE, COMPOUND_LIST},
	{FOR_CLAUSE, CASE_LIST_NS},
	{FOR_CLAUSE, COMPLETE_CONDITION},
	{FOR_CLAUSE, AND_OR_MAJOR},
	{COMPOUND_LIST, TK_DO},
	{COMPOUND_LIST, TK_PAREN_CLOSE},
	{COMPOUND_LIST, TK_LBRACE},
	{COMPOUND_LIST, TK_WHILE},
	{COMPOUND_LIST, FUNC_NAME},
	{COMPOUND_LIST, TK_UNTIL},
	{COMPOUND_LIST, TK_ELIF},
	{COMPOUND_LIST, TK_ELSE},
	{COMPOUND_LIST, TK_IF},
	{COMPOUND_LIST, TK_THEN},
	{COMPOUND_LIST, TK_ELSE},
	{COMPOUND_LIST, COMPOUND_LIST},
	{COMPOUND_LIST, COMPLETE_CONDITION},
	{CLOSE_LIST, PATTERN},
	{CLOSE_LIST, FUNC_NAME},
	{SUBSHELL, LINEBREAK},
	{SUBSHELL, COMPLETE_COMMANDS},
	{SUBSHELL, TK_BANG},
	{SUBSHELL, SEPARATOR_OP},
	{SUBSHELL, NEWLINE_LIST},
	{SUBSHELL, SEQUENCE},
//	watch !
	{SUBSHELL, SEPARATOR_OP},
	{SUBSHELL, NEWLINE_LIST},
	{SUBSHELL, TK_DO},
	{SUBSHELL, TK_PAREN_CLOSE},
	{SUBSHELL, TK_WHILE},
	{SUBSHELL, FUNC_NAME},
	{SUBSHELL, TK_UNTIL},
	{SUBSHELL, TK_IF},
	{SUBSHELL, TK_ELIF},
	{SUBSHELL, TK_THEN},
	{SUBSHELL, TK_ELSE},
	{SUBSHELL, COMPOUND_LIST},
	{SUBSHELL, CASE_LIST_NS},
	{SUBSHELL, COMPLETE_CONDITION},
	{SUBSHELL, AND_OR_MAJOR},
	{COMPOUND_COMMAND, LINEBREAK},
	{COMPOUND_COMMAND, TK_PAREN_OPEN},
	{COMPOUND_COMMAND, TK_LBRACE},
	{COMPOUND_COMMAND, COMPLETE_COMMANDS},
	{COMPOUND_COMMAND, TK_BANG},
	{COMPOUND_COMMAND, SEPARATOR_OP},
	{COMPOUND_COMMAND, NEWLINE_LIST},
	{COMPOUND_COMMAND, SEQUENCE},
//	watch !
	{COMPOUND_COMMAND, FUNC},
	{COMPOUND_COMMAND, TK_DO},
	{COMPOUND_COMMAND, TK_PAREN_CLOSE},
	{COMPOUND_COMMAND, TK_WHILE},
	{COMPOUND_COMMAND, FUNC_NAME},
	{COMPOUND_COMMAND, TK_UNTIL},
	{COMPOUND_COMMAND, TK_IF},
	{COMPOUND_COMMAND, TK_ELIF},
	{COMPOUND_COMMAND, TK_THEN},
	{COMPOUND_COMMAND, TK_ELSE},
	{COMPOUND_COMMAND, COMPOUND_LIST},
	{COMPOUND_COMMAND, CASE_LIST_NS},
	{COMPOUND_COMMAND, COMPLETE_CONDITION},
	{COMPOUND_COMMAND, AND_OR_MAJOR},
	{COMMAND, TK_WHILE},
	{COMMAND, TK_UNTIL},
	{COMMAND, LINEBREAK},
	{COMMAND, TK_BANG},
	{COMMAND, TK_PAREN_OPEN},
	{COMMAND, TK_LBRACE},
	{COMMAND, COMPLETE_COMMANDS},
	{COMMAND, TK_DO},
	{COMMAND, TK_PAREN_CLOSE},
	{COMMAND, TK_IF},
	{COMMAND, TK_ELIF},
	{COMMAND, TK_THEN},
	{COMMAND, TK_ELSE},
	{COMMAND, COMPOUND_LIST},
	{COMMAND, CASE_LIST_NS},
	{COMMAND, COMPLETE_CONDITION},
	{COMMAND, TK_BANG},
	{COMMAND, SEPARATOR_OP},
	{COMMAND, NEWLINE_LIST},
	{COMMAND, SEQUENCE},
	{COMMAND, AND_OR_MAJOR},
	{AND_OR_MINOR, SEQUENCE},
//	watch !
	{AND_OR_MINOR, LINEBREAK},
	{AND_OR_MINOR, TK_BANG},
	{AND_OR_MINOR, TK_PAREN_OPEN},
	{AND_OR_MINOR, TK_LBRACE},
	{AND_OR_MINOR, COMPLETE_COMMANDS},
	{AND_OR_MINOR, AND_OR_MAJOR},
	{PIPE_SEQUENCE, TK_WHILE},
	{PIPE_SEQUENCE, FUNC_NAME},
	{PIPE_SEQUENCE, TK_UNTIL},
	{PIPE_SEQUENCE, TK_DO},
	{PIPE_SEQUENCE, TK_PAREN_CLOSE},
	{PIPE_SEQUENCE, TK_IF},
	{PIPE_SEQUENCE, TK_ELIF},
	{PIPE_SEQUENCE, TK_THEN},
	{PIPE_SEQUENCE, TK_ELSE},
	{PIPE_SEQUENCE, COMPOUND_LIST},
	{PIPE_SEQUENCE, CASE_LIST_NS},
	{PIPE_SEQUENCE, COMPLETE_CONDITION},
	{PIPE_SEQUENCE, LINEBREAK},
	{PIPE_SEQUENCE, TK_BANG},
	{PIPE_SEQUENCE, TK_PAREN_OPEN},
	{PIPE_SEQUENCE, TK_LBRACE},
	{PIPE_SEQUENCE, COMPLETE_COMMANDS},
	{PIPE_SEQUENCE, TK_BANG},
	{PIPE_SEQUENCE, TK_BANG},
	{PIPE_SEQUENCE, SEPARATOR_OP},
	{PIPE_SEQUENCE, NEWLINE_LIST},
	{PIPE_SEQUENCE, AND_OR_MAJOR},
	{TK_BANG, TK_WHILE},
	{TK_BANG, TK_UNTIL},
	{TK_BANG, TK_DO},
	{TK_BANG, TK_PAREN_CLOSE},
	{TK_BANG, TK_IF},
	{TK_BANG, TK_ELIF},
	{TK_BANG, TK_THEN},
	{TK_BANG, TK_ELSE},
	{TK_BANG, COMPOUND_LIST},
	{TK_BANG, CASE_LIST_NS},
	{TK_BANG, COMPLETE_CONDITION},
	{TK_BANG, LINEBREAK},
	{TK_BANG, TK_PAREN_OPEN},
	{TK_BANG, TK_LBRACE},
	{TK_BANG, COMPLETE_COMMANDS},
	{TK_BANG, TK_BANG},
	{TK_BANG, TK_BANG},
	{TK_BANG, SEPARATOR_OP},
	{TK_BANG, NEWLINE_LIST},
	{TK_BANG, AND_OR_MAJOR},
	{PIPE_SEMI_SEQUENCE, TK_WHILE},
	{PIPE_SEMI_SEQUENCE, TK_UNTIL},
	{PIPE_SEMI_SEQUENCE, TK_DO},
	{PIPE_SEMI_SEQUENCE, TK_PAREN_CLOSE},
	{PIPE_SEMI_SEQUENCE, TK_IF},
	{PIPE_SEMI_SEQUENCE, TK_ELIF},
	{PIPE_SEMI_SEQUENCE, TK_THEN},
	{PIPE_SEMI_SEQUENCE, TK_ELSE},
	{PIPE_SEMI_SEQUENCE, COMPOUND_LIST},
	{PIPE_SEMI_SEQUENCE, CASE_LIST_NS},
	{PIPE_SEMI_SEQUENCE, COMPLETE_CONDITION},
	{PIPE_SEMI_SEQUENCE, LINEBREAK},
	{PIPE_SEMI_SEQUENCE, TK_BANG},
	{PIPE_SEMI_SEQUENCE, TK_PAREN_OPEN},
	{PIPE_SEMI_SEQUENCE, TK_LBRACE},
	{PIPE_SEMI_SEQUENCE, COMPLETE_COMMANDS},
	{PIPE_SEMI_SEQUENCE, SEPARATOR_OP},
	{PIPE_SEMI_SEQUENCE, NEWLINE_LIST},
	{PIPE_SEMI_SEQUENCE, AND_OR_MAJOR},
	{PIPE_SEMI_SEQUENCE, SEQUENCE},
	{PIPE_CLOSE_SEQUENCE, TK_WHILE},
	{PIPE_CLOSE_SEQUENCE, TK_UNTIL},
	{PIPE_CLOSE_SEQUENCE, TK_DO},
	{PIPE_CLOSE_SEQUENCE, TK_PAREN_CLOSE},
	{PIPE_CLOSE_SEQUENCE, TK_IF},
	{PIPE_CLOSE_SEQUENCE, TK_ELIF},
	{PIPE_CLOSE_SEQUENCE, TK_THEN},
	{PIPE_CLOSE_SEQUENCE, TK_ELSE},
	{PIPE_CLOSE_SEQUENCE, COMPOUND_LIST},
	{PIPE_CLOSE_SEQUENCE, CASE_LIST_NS},
	{PIPE_CLOSE_SEQUENCE, COMPLETE_CONDITION},
	{PIPE_CLOSE_SEQUENCE, LINEBREAK},
	{PIPE_CLOSE_SEQUENCE, TK_BANG},
	{PIPE_CLOSE_SEQUENCE, TK_PAREN_OPEN},
	{PIPE_CLOSE_SEQUENCE, TK_LBRACE},
	{PIPE_CLOSE_SEQUENCE, COMPLETE_COMMANDS},
	{PIPE_CLOSE_SEQUENCE, SEPARATOR_OP},
	{PIPE_CLOSE_SEQUENCE, NEWLINE_LIST},
	{PIPE_CLOSE_SEQUENCE, AND_OR_MAJOR},
	{PIPE_CLOSE_SEQUENCE, SEQUENCE},
	{SEQUENCE, PIPE_SEMI_SEQUENCE},
	{SEQUENCE, PIPE_CLOSE_SEQUENCE},
	{SEQUENCE, TK_WHILE},
	{SEQUENCE, TK_UNTIL},
	{SEQUENCE, TK_DO},
	{SEQUENCE, TK_PAREN_CLOSE},
	{SEQUENCE, TK_IF},
	{SEQUENCE, TK_ELIF},
	{SEQUENCE, TK_THEN},
	{SEQUENCE, TK_ELSE},
	{SEQUENCE, COMPOUND_LIST},
	{SEQUENCE, CASE_LIST_NS},
	{SEQUENCE, COMPLETE_CONDITION},
	{SEQUENCE, LINEBREAK},
	{SEQUENCE, TK_PAREN_OPEN},
	{SEQUENCE, TK_LBRACE},
	{SEQUENCE, COMPLETE_COMMANDS},
	{SEQUENCE, TK_BANG},
	{SEQUENCE, SEPARATOR_OP},
	{SEQUENCE, NEWLINE_LIST},
	{SEQUENCE, AND_OR_MAJOR},
	{SEQUENCE, SEQUENCE},
	{PIPELINE, TK_WHILE},
	{PIPELINE, TK_UNTIL},
	{PIPELINE, TK_DO},
	{PIPELINE, TK_PAREN_CLOSE},
	{PIPELINE, TK_IF},
	{PIPELINE, TK_ELIF},
	{PIPELINE, TK_THEN},
	{PIPELINE, TK_ELSE},
	{PIPELINE, COMPOUND_LIST},
	{PIPELINE, CASE_LIST_NS},
	{PIPELINE, COMPLETE_CONDITION},
	{PIPELINE, LINEBREAK},
	{PIPELINE, TK_BANG},
	{PIPELINE, TK_PAREN_OPEN},
	{PIPELINE, TK_LBRACE},
	{PIPELINE, COMPLETE_COMMANDS},
	{PIPELINE, SEPARATOR_OP},
	{PIPELINE, SEPARATOR_OP},
	{PIPELINE, NEWLINE_LIST},
	{PIPELINE, AND_OR_MAJOR},
	{AND_OR_MAJOR, LINEBREAK},
	{AND_OR_MAJOR, TK_BANG},
	{AND_OR_MAJOR, TK_PAREN_OPEN},
	{AND_OR_MAJOR, TK_LBRACE},
	{AND_OR_MAJOR, COMPLETE_COMMANDS},
	{AND_OR_MAJOR, AND_OR_MAJOR},
	{AND_OR_MAJOR, AND_OR_MAJOR},
	{AND_OR, TK_DO},
	{AND_OR, TK_PAREN_CLOSE},
	{AND_OR, TK_WHILE},
	{AND_OR, TK_UNTIL},
	{AND_OR, TK_IF},
	{AND_OR, TK_ELIF},
	{AND_OR, TK_THEN},
	{AND_OR, TK_ELSE},
	{AND_OR, COMPOUND_LIST},
	{AND_OR, CASE_LIST_NS},
	{AND_OR, COMPLETE_CONDITION},
	{AND_OR, LINEBREAK},
	{AND_OR, TK_BANG},
	{AND_OR, TK_PAREN_OPEN},
	{AND_OR, TK_LBRACE},
	{AND_OR, COMPLETE_COMMANDS},
	{AND_OR, SEPARATOR_OP},
	{AND_OR, SEPARATOR_OP},
	{AND_OR, NEWLINE_LIST},
	{LIST, LINEBREAK},
	{LIST, COMPLETE_COMMANDS},
	{LIST, NEWLINE_LIST},
	{COMPLETE_COMMAND, LINEBREAK},
	{COMPLETE_COMMAND, COMPLETE_COMMANDS},
	{COMPLETE_COMMAND, NEWLINE_LIST},
	{COMPLETE_COMMANDS, COMPLETE_COMMANDS},
	{PROGRAM, TERMINUS},
	{0, 0},
};

int			eval_sym(t_list **stack, t_sym new_sym)
{
	t_sym		*head;	
	int		i;

	if (!*stack)
		return (1);
	head = (*stack)->content;
//	DG("eval head %s && sym %s", read_state(*head), read_state(new_sym));
	i = 0;
	while (g_stackmatch[i].top)
	{
		if (new_sym == g_stackmatch[i].top && *head == g_stackmatch[i].under)
			return (0);
		i++;
	}
	return (1);
}
